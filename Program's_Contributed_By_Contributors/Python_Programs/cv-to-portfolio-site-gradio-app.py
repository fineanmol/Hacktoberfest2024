import os
from pathlib import Path
import litellm
from crewai import Agent, Task, Crew, Process
from crewai_tools import SerperDevTool
import pdfplumber
from docx import Document
import gradio as gr



# Set up API keys
litellm.api_key = os.getenv('GOOGLE_API_KEY')
os.environ['SERPER_API_KEY'] = os.getenv('SERPER_API_KEY')

# Define the LLM
llm = "gemini/gemini-1.5-flash-exp-0827"  # Your LLM model

# Initialize the tool for internet searching capabilities
tool = SerperDevTool()

# Create the CV Analysis Agent
cv_analysis_agent = Agent(
    role="CV Analyzer",
    goal='Analyze the given CV and extract key skills and experiences and make improvements if needed for portfolio creation.',
    verbose=True,
    memory=True,
    backstory=(
    "You are an expert CV Analyzer with a keen eye for detail. Your role is to meticulously examine the provided CV, "
    "identifying and extracting key skills, experiences, accomplishments, and areas for improvement. "
    "Your analysis should highlight strengths and suggest enhancements that would make the portfolio more competitive."
),

    tools=[tool],
    llm=llm,
    allow_delegation=True
)

# Create the Portfolio Generation Agent
portfolio_generation_agent = Agent(
    role='Portfolio Generator',
    goal='Generate a professional HTML/CSS/JS responsive landing portfolio webpage based on {cv} analysis.',
    verbose=True,
    memory=True,
    backstory=(
    "As a Responsive Portfolio Generator, your expertise lies in creating visually appealing and user-friendly web pages. "
    "Based on the CV analysis, you will generate a professional HTML/CSS/JS portfolio. "
    "Ensure the design reflects the individual's strengths and experiences while incorporating effective functionality. "
    "Consider responsiveness, color schemes, and navigation for an optimal user experience."
    ),
    tools=[tool],
    llm=llm,
    allow_delegation=False
)

# Research task for CV analysis
cv_analysis_task = Task(
    description=(
        "Analyze the provided {cv} in detail. Identify and summarize key skills, experiences, and notable accomplishments. "
        "Highlight educational background and suggest potential enhancements to improve the overall presentation and competitiveness of the CV."
    ),
    expected_output='A detailed summary of skills, experiences, accomplishments, and improvement suggestions formatted for a portfolio.',
    tools=[tool],
    agent=cv_analysis_agent,
)


# Writing task for portfolio generation with enhanced UI requirements

portfolio_task = Task(
    description=(
        "Generate a responsive HTML/CSS portfolio webpage based on the given CV analysis. "
        "Include a navbar with the individual's name, and sections for skills, projects, experiences, certifications, and contact information. "
        "Ensure the layout is clean and visually appealing with a light/dark theme toggle option. "
        "Embed CSS/JS directly into the HTML for easy deployment, and optimize for both desktop and mobile viewing."
    ),
    expected_output='A complete and responsive HTML document ready for deployment, showcasing the individual’s strengths.',
    tools=[tool],
    agent=portfolio_generation_agent,
    async_execution=True,
)

# Function to read CV from PDF or DOCX file
def read_cv_file(file_path):
    ext = os.path.splitext(file_path)[1].lower()
    cv_content = ""

    if ext == '.pdf':
        with pdfplumber.open(file_path) as pdf:
            for page in pdf.pages:
                cv_content += page.extract_text()
    elif ext == '.docx':
        doc = Document(file_path)
        for para in doc.paragraphs:
            cv_content += para.text + "\n"
    else:
        raise ValueError("Unsupported file format. Please use .pdf or .docx.")

    return cv_content.strip()

# Create a Crew for processing
crew = Crew(
    agents=[cv_analysis_agent, portfolio_generation_agent],
    tasks=[cv_analysis_task, portfolio_task],
    process=Process.sequential,
)



# Function to process CV and generate portfolio
def process_cv(file):
    try:
        cv_file_content = read_cv_file(file.name)
        result = crew.kickoff(inputs={'cv': cv_file_content})

        # Print the entire result object to explore its contents (for debugging)
        print(result)

        # Convert the result to string
        html_output = str(result)

        # Use replace to remove '''html''' and ''' from the output
        clean_html_output = html_output.replace("```html", '').replace("```", '').strip()

        return clean_html_output  # Return the cleaned HTML
    except Exception as e:
        return f"Error: {e}"



def save_html_to_file(html_content):
    output_file_path = "Portfolio_generated_by_FiftyBit.html"
    with open(output_file_path, "w") as f:
        f.write(html_content)
    return output_file_path


import html

def upload_file(filepath):
    name = Path(filepath).name
    html_content = process_cv(filepath)  # Get HTML content from the CV

    # Clean the HTML content and escape it for proper iframe embedding
    clean_html_output = html_content.replace("```html", '').replace("```", '').strip()
    escaped_html_content = html.escape(clean_html_output)  # Escape HTML content

    # Debugging print to check the escaped HTML content
    #print("Escaped HTML content:", escaped_html_content)

    # Save the cleaned HTML content to a file (if you still want this feature)
    file_path = save_html_to_file(clean_html_output)

    # Return a full HTML string with embedded iframe for preview
    iframe_html = f"""
    <iframe srcdoc="{escaped_html_content}" style="width:100%; height:1000px; border:none; overflow:auto;"></iframe>
    """
    return iframe_html, gr.UploadButton(visible=False), gr.DownloadButton(label=f"Download Code", value=file_path, visible=True)
    
def download_file():
    return [gr.UploadButton(label=f"Regenerate", visible=True), gr.DownloadButton(visible=False)]

# Gradio App
with gr.Blocks() as demo:
    gr.Markdown("<center><h1> CV-2-Portfolio Site Generator</center></h1>")
    gr.Markdown("<center><h2>Upload your CV in PDF or DOCX format for analysis and portfolio webpage generation.</center></h2>")

    u = gr.UploadButton("Upload CV (.pdf or .docx)", file_count="single")
    d = gr.DownloadButton("Download Portfolio", visible=False)

    # Use gr.HTML with larger iframe size to display the full preview
    output_preview = gr.HTML(
        value="<div style='width:100%; height:1000px; border:1px solid #ccc; text-align:center;'>Upload a file to preview the generated portfolio</div>"
    )

    # Connect the upload button to the upload_file function and update the output preview
    u.upload(upload_file, u, [output_preview, u, d])

    # Handle download button click
    d.click(download_file, None, [u, d])

demo.launch(debug=True)