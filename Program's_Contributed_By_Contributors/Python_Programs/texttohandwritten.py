import pywhatkit

text = "Web Crawling is all about viewing web pages as a whole and indexing it." \
       "When a crawler (bot) crawls a website, it goes through every page and every link of the website for indexing."
pywhatkit.text_to_handwriting(text, rgb=(0,0,255))