import requests

# Make a GET request to the API
url = "https://api.example.com/users"
response = requests.get(url)

# Extract data from the response
data = response.json()

# Process the data
for user in data:
    print("User:", user["name"])
    print("Email:", user["email"])
    print("Username:", user["username"])
    