import requests

CITY = "Christchurch"


def get_weather():
    """Display Weather for city in console"""
    url = f"https://wttr.in/{CITY}"
    response = requests.get(url=url)
    print(response.text)


if __name__ == "__main__":
    get_weather()
