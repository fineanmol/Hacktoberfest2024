import numpy as np
import pandas as pd
from google_play_scraper import app, Sort, reviews_all
zoho_reviews = reviews_all(
    'com.zoho.mail', sleep_milliseconds=0,  # defaults to 0
    lang='en',  # defaults to 'en'
    country='us',  # defaults to 'us'
    sort=Sort.NEWEST,  # defaults to Sort.MOST_RELEVANT
)
print(zoho_reviews)
