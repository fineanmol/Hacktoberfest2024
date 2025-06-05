import requests
from bs4 import BeautifulSoup

# Specify the URL of the webpage you want to scrape
url = 'https://example.com'

# Send an HTTP GET request to the URL
response = requests.get(url)

# Check if the request was successful
if response.status_code == 200:
    # Parse the page content with BeautifulSoup
    soup = BeautifulSoup(response.text, 'html.parser')
    
    # Extract specific data from the webpage
    # For example, let's say you want to extract all the links on the page
    links = soup.find_all('a')
    
    # Print the links
    for link in links:
        print(link.get('href'))
else:
    print('Failed to retrieve the webpage')

