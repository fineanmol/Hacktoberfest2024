import streamlit as st
import pickle
import nltk
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer

ps = PorterStemmer()
import string

tfidf = pickle.load(open('vectorizer.pkl', 'rb'))
#TFIDF = pickle.load(open('new_vector.pkl', 'rb'))
model = pickle.load(open('model.pkl', 'rb'))
# model_rfc = pickle.load(open('model_rfc.pkl', 'rb'))


def transform_tex(text):
    text = text.lower()  # step 1
    text = nltk.word_tokenize(text)  # step 2, text is converted into a list
    # we'll run a loop that will
    y = []
    for i in text:  # step 3 - removing special characters
        if i.isalnum():
            y.append(i)
    text = y[:]
    y.clear()

    for i in text:
        if i not in stopwords.words('english') and i not in string.punctuation:
            y.append(i)
    text = y[:]
    y.clear()
    for i in text:  # stem 4 -> stemming
        y.append(ps.stem(i))

    return " ".join(y)


st.title("Mail Spam Classifier")
ip_mail = st.text_area("Enter your Mail")

if st.button('Predict'):
    # preprocess
    transformed_text = transform_tex(ip_mail)
    # vectorize
    vector_input = tfidf.transform([transformed_text])
    # model prediction
    result = model.predict(vector_input)[0]
    # display
    if result == 1:
        st.header("SPAM")
    else:
        st.header("NOT SPAM")
