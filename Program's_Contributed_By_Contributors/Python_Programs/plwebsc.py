import json
import pandas as pd
from bs4 import BeautifulSoup
from urllib.request import urlopen

scrape_url = 'https://understat.com/league/EPL'


pg_connect = urlopen(scrape_url)

pg_html = BeautifulSoup(pg_connect, "html.parser")

json_raw_string = pg_html.find_all(name = "script")[3].string
print(json_raw_string)

start_ind = json_raw_string.index("\\") 
end_ind = json_raw_string.index("')")

json_data = json_raw_string[start_ind:end_ind]

json_data = json_data.encode("utf8").decode("unicode_escape")

json.loads(json_data)

fin_json_df = pd.json_normalize(json.loads(json_data))

print(fin_json_df)

fin_json_df.to_csv('PLPLAYERS.csv')


