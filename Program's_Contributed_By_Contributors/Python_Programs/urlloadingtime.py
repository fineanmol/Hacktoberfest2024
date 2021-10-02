from urllib.request import urlopen
import time

url = input("Enter the url whose loading time you want to check: ")


def get_load_time(url):
    if ("https" or "http") in url:
        open_this_url = urlopen(url)
    else:
        open_this_url = urlopen("https://" + url)
    start_time = time.time()
    open_this_url.read()
    end_time = time.time()
    open_this_url.close()
    time_to_load = end_time - start_time

    return time_to_load


print(f"\nThe time taken to load {url} is {get_load_time(url):.2} seconds.")