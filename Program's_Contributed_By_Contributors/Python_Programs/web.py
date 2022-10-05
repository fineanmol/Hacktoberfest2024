import requests

#this script is used to print the status code & http response headers of a website
def get_headers(url):
    
    res = requests.get(url)
    headers = res.headers

    print("\n\n")
    print("HTTP Response Headers: \n")
    for key, value in headers.items():
        print(key, ":", value)

    print("\n\n")
    print("Status Code:", res.status_code)

if __name__ == "__main__":
    url = input("Enter the URL: ")
    get_headers(url)