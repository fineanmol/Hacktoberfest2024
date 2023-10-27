# Import required modules
import json
import requests
from datetime import datetime
from urllib.parse import urlparse
from bs4 import BeautifulSoup
from beautifultable import BeautifulTable

# Function to load JSON data from a file or create an empty array
def load_json(database_json_file="scraped_data.json"):
    try:
        with open(database_json_file, "r") as read_it:
            all_data_base = json.loads(read_it.read())
            return all_data_base
    except:
        all_data_base = dict()
        return all_data_base

# Function to save scraped data in JSON format
def save_scraped_data_in_json(data, database_json_file="scraped_data.json"):
    file_obj = open(database_json_file, "w")
    file_obj.write(json.dumps(data))
    file_obj.close()

# Function to initialize existing scraped data from JSON
def existing_scraped_data_init(json_db):
    scraped_data = json_db.get("scraped_data")
    if scraped_data is None:
        json_db['scraped_data'] = dict()

    return None

# Function to create a timestamp for tracking scraped data
def scraped_time_is():
    now = datetime.now()
    dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
    return dt_string

# Function to process a URL request and scrape the data
def process_url_request(website_url):
    request_data = requests.get(website_url)
    if request_data.status_code == 200:
        soup = BeautifulSoup(request_data.text, 'html.parser')
        return soup
    return None

# Function to process Beautiful Soup data and extract information
def process_beautiful_soup_data(soup):
    return {
        'title': soup.find('title').text,
        'all_anchor_href': [i['href'] for i in soup.find_all('a', href=True)],
        'all_anchors': [str(i) for i in soup.find_all('a')],
        'all_images_data': [str(i) for i in soup.find_all('img')],
        'all_images_source_data': [i['src'] for i in soup.find_all('img')],
        'all_h1_data': [i.text for i in soup.find_all('h1')],
        'all_h2_data': [i.text for i in soup.find_all('h2')],
        'all_h3_data': [i.text for i in soup.find_all('h3')],
        'all_p_data': [i.text for i in soup.find_all('p')]
    }

# Main loop for user interaction
while True:
    print("""  ================ Welcome to this scraping program =============
    ==>> press 1 for checking existing scraped websites
    ==>> press 2 for scrap a single website
    ==>> press 3 for exit
    """)

    choice = int(input("==>> Please enter your choice: "))

    # Load JSON data and initialize the scraped data structure
    local_json_db = load_json()
    existing_scraped_data_init(local_json_db)

    if choice == 1:
        # Display existing scraped websites using BeautifulTable
        scraped_websites_table = BeautifulTable()
        scraped_websites_table.columns.header = ["Sr no.", "Alias name", "Website domain", "Title", "Scraped at", "Status"]
        scraped_websites_table.set_style(BeautifulTable.STYLE_BOX_DOUBLED)

        for count, data in enumerate(local_json_db['scraped_data']):
            scraped_websites_table.rows.append([count + 1,
                local_json_db['scraped_data'][data]['alias'],
                local_json_db['scraped_data'][data]['domain'],
                local_json_db['scraped_data'][data]['title'],
                local_json_db['scraped_data'][data]['scraped_at'],
                local_json_db['scraped_data'][data]['status']
            ])

        if not local_json_db['scraped_data']:
            print('===> No existing data found !!!')
        print(scraped_websites_table)

    elif choice == 2:
        # Scraping a new website
        print()
        url_for_scrap = input("===> Please enter the URL you want to scrape: ")
        is_accessible = process_url_request(url_for_scrap)

        if is_accessible:
            scraped_data_packet = process_beautiful_soup_data(is_accessible)
            print(' =====> Data scraped successfully !!!')
            key_for_storing_data = input("Enter an alias name for saving scraped data: ")
            scraped_data_packet['url'] = url_for_scrap
            scraped_data_packet['name'] = key_for_storing_data
            scraped_data_packet['scraped_at'] = scraped_time_is()

            # Handle alias name conflicts
            if key_for_storing_data in local_json_db['scraped_data']:
                key_for_storing_data = key_for_storing_data + str(scraped_time_is())
                print("Provided key already exists, so data stored as: {}".format(key_for_storing_data))

            scraped_data_packet['alias'] = key_for_storing_data
            scraped_data_packet['status'] = True
            scraped_data_packet['domain'] = urlparse(url_for_scrap).netloc

            local_json_db['scraped_data'][key_for_storing_data] = scraped_data_packet
            print('Scraped data is:', local_json_db['scraped_data'][key_for_storing_data])
            save_scraped_data_in_json(local_json_db)
            print(' =====> Data saved successfully !!!')
            print()
    
    elif choice == 3:
        print('Thank you for using!!!')
        break

    else:
        print("Enter a valid choice")
