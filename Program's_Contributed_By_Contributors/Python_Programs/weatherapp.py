import requests


def get_weather(city, api_key):
  base_url = "http://api.weatherapi.com/v1/current.json"
  params = {'key': api_key, 'q': city}
  response = requests.get(base_url, params=params)
  data = response.json()
  return data


def display_weather(data):
  if data.get("error") is not None:
    print("City not found.")
    return
  weather = data["current"]["condition"]["text"]
  temp = data["current"]["temp_c"]
  humidity = data["current"]["humidity"]
  dewpoint = data["current"]["dewpoint_c"]

  print(f"Weather in {city}:")
  print(f"Weather: {weather}")
  print(f"Temperature: {temp}°C")
  print(f"Humidity: {humidity}")
  print(f"Dew Point: {dewpoint}°C")


if __name__ == "__main__":
  api_key = "WeatherAPI.com API key" 
  city = input("Enter the city name: ")
  weather_data = get_weather(city, api_key)
  display_weather(weather_data)
