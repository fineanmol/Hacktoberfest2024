import requests
import inquirer


r = requests.get("http://api.open-notify.org/astros.json",
                 headers={"User-Agent": "Hello"})

data = r.json()
astroEmoji = "👨‍🚀"
astronauts = data["people"]

print(f'There are {data["number"]} astronauts in the space')
for people in astronauts:
    print(f'Name: {people["name"]} {astroEmoji}')

print("Hey you! Join us and go in the space!")

confirm = {
    inquirer.Confirm('confirmed',
                     message="Do you want to become an astronaut?",
                     default=True),
}
confirmation = inquirer.prompt(confirm)
if(confirmation["confirmed"]):
    print('Welcome aboard!!!!')
else:
    print('Oh no :c')