import streamlit as st

# Title 
st.title("Chatbot UI")
st.markdown("Welcome to the Chatbot! Type your questions below.")

# Text input for user input
user_input = st.text_input("You:", "")

# Function to generate bot responses
def generate_response(user_input):
    # Simple response for any user input
    return "Bot: Hey, hello!"

# Generate bot response when the user submits input
if st.button("Send"):
    bot_response = generate_response(user_input)
    st.text(bot_response)
