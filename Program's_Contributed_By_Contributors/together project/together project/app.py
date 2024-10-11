from flask import Flask, render_template, request
import os
from together import Together

app = Flask(__name__)

client = Together(api_key=os.environ.get("6ac70d93fd09dc1231ef8a57725909ad34370f93363dda88d7c6b1e91ff3eafd"))

conversation = []

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        user_input = request.form['user_input']
        response = generate_response(user_input)  # call the response generation function
        conversation.append({'username': 'User  ', 'text': user_input})
        conversation.append({'username': 'AI', 'text': response})
        return render_template('index.html', conversation=conversation)
    return render_template('index.html', conversation=conversation)

def generate_response(user_input):
    stream = client.chat.completions.create(
        model="meta-llama/Meta-Llama-3.1-8B-Instruct-Turbo",
        messages=[{"role": "user", "content": user_input}],
        stream=True,
    )
    response = ""
    for chunk in stream:
        response += chunk.choices[0].delta.content or ""
    return response

if __name__ == '__main__':
    app.run(debug=True)