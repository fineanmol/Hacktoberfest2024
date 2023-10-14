import random
import time

dad_jokes = [
    "Why don't scientists trust atoms? Because they make up everything! 😄",
    "I told my wife she was drawing her eyebrows too high. She looked surprised. 😄",
    "What do you call a fish with no eyes? Fsh! 🐟",
    "I used to play piano by ear, but now I use my hands. 🎹👐",
    "Parallel lines have so much in common. It's a shame they'll never meet. 📐📏",
]

knock_knock_jokes = [
    "Knock, knock. Who's there? Atch. Atch who? Bless you! 🤧",
    "Knock, knock. Who's there? Lettuce. Lettuce who? Lettuce in, it's cold out here! 🥬❄️",
    "Knock, knock. Who's there? Boo. Boo who? Don't cry; it's just a joke! 👻",
    "Knock, knock. Who's there? Olive. Olive who? Olive you and I miss you! 🫒❤️",
]

family_guy_jokes = [
    "Why did Peter Griffin cross the road? To get to the Drunken Clam! 🍺",
    "What's Stewie's favorite fruit? Victory shall be mine, so it's bananas! 🍌",
    "Why does Quagmire use a ladder in the bathroom? Giggity! 😏🪜",
    "Lois, this joke program is freakin' sweet! 😂",
]

movie_and_tv_jokes = [
    "Why was the math book sad? Because it had too many problems, just like Game of Thrones Season 8! 📚🐉",
    "Why did the tomato turn red? Because it saw the salad dressing, and it thought it was a Russian spy! 🍅🕵️‍♂️",
    "I'm reading a book on anti-gravity. It's impossible to put down, unlike The Lord of the Rings trilogy! 📖🌌",
    "What's Harry Potter's favorite method of communication? Owl mail, because he's tired of all the Floo Network glitches! 🦉🔥",
]

def main():
    while True:
        joke_type = random.choice(["Dad Joke", "Knock-Knock Joke", "Family Guy Joke", "Movie/TV Joke"])
        if joke_type == "Dad Joke":
            joke = random.choice(dad_jokes)
        elif joke_type == "Knock-Knock Joke":
            joke = random.choice(knock_knock_jokes)
        elif joke_type == "Family Guy Joke":
            joke = random.choice(family_guy_jokes)
        else:
            joke = random.choice(movie_and_tv_jokes)
        
        print(f"{joke_type}: {joke}")
        print("-" * 30)  
        time.sleep(2.5)  # timer here

if __name__ == "__main__":
    main()
