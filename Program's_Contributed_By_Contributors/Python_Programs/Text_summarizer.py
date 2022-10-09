#Using Transformer pipeline
#Do pip install transformers Before using it
from transformers import pipeline
import re



text = input(str("Type what you want to Summarize Here"))
text = re.sub(r"(@\[A-Za-z0-9]+)|([^0-9A-Za-z \t])|(\w+:\/\/\S+)|^rt|http.+?", "", text) # Clean The text

summarizer = pipeline('summarization')

summarized = summarizer(text ,max_length = 100, min_length = 50 ,do_sample = False)   
print(summarized)
