def chat_bot(user_input):
    user_input = user_input.lower()
    rules_and_responses = {
        "hello": "Hello! How can I assist you today?",
        "how are you": "I'm just a chatbot, but thanks for asking!",
        "goodbye": "Goodbye! Feel free to return if you have more questions.",
        "name": "I'm just a simple chatbot, but you can call me by any name.",
        "help": "Sure, I can help you with a wide range of topics. Just ask me a question!",
        "weather": "I can provide you with the current weather information for your location. Please provide your city or zip code.",
        "time": "I can tell you the current time. What time zone are you interested in?",
        "joke": "Why did the computer keep freezing? Because it left its Windows open!",
        "thanks": "You're welcome! If you have any more questions, feel free to ask.",
        "age": "I'm just a computer program, so I don't have an age.",
        "favorite color": "I don't have preferences, but I think all colors are beautiful.",
        "age": "I don't have an age, as I'm just a computer program, but i was just made yesterday!!!.",
        "default": "I'm not sure how to respond to that. Can you please rephrase your question?"
    }
    for keyword, response in rules_and_responses.items():
        if keyword in user_input:
            return response
        
    return rules_and_responses["default"]

while True:
    user_input=input("You: ")
    if user_input.lower() == "exit":
        print("Chatbot: Goodbye! Feel free to return if you have more questions.")
        break
    response = chat_bot(user_input)
    print("Chatbot: ",response)
    