#pip install PyPDF2

import PyPDF2

input_pdf_path = "input.pdf"

output_pdf_path = "output.pdf"
password = "your_password_here"

with open(input_pdf_path, "rb") as pdf_file:
    pdf_reader = PyPDF2.PdfFileReader(pdf_file)
    
    pdf_writer = PyPDF2.PdfFileWriter()
    
    for page_num in range(pdf_reader.getNumPages()):
        pdf_writer.addPage(pdf_reader.getPage(page_num))
    
    pdf_writer.encrypt(password)
        with open(output_pdf_path, "wb") as output_file:
        pdf_writer.write(output_file)

print(f"Password-protected PDF saved to {output_pdf_path}")
