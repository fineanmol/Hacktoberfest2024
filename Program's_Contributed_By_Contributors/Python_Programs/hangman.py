try:
    from PIL import Image
except ImportError:
    import Image
import random,string

def play_again():
	play_again = input("Do you want to play again(y/n): ").lower()
	if play_again == "y":
		return hangman(words)
	else:
		return "Thanks for playing"

def hangman(list_of_words):
	random_word = random.choice(list_of_words)
	secret_word = random_word
	available_letters = list(string.ascii_lowercase)
	answer = ''
	chances = 8
	blank_spaces = ("-" * len(secret_word))
	list2 = list(blank_spaces)
	position_list = []
	message = '''You can't guess same letter again,\nplease guess letters from available letters list.'''
	print("Welcome to the game, Hangman!")
	print("I am thinking of a word that is " + str(len(secret_word)) + " letters long.")
	print("")
	print(blank_spaces)
	while chances > 0:
		print("")
		print("You have " + str(chances) + " chances to guess the correct word.")
		print("Available letters to guess:- ")
		print(available_letters)
		try:
			guess = input("Guess your letter: ")
			if len(guess) == 1:
				position_list = []
				if guess in secret_word:
					list1 = list(secret_word)
					counter = 0
					while counter < len(list1):
						if list1[counter] == guess:
							if counter not in position_list:
								position_list.append(counter)
							else:
								position_list.append(counter)
						else:
							pass
						counter+=1

					for numbers in position_list:
						list2[numbers] = guess.upper()
						answer = "".join(list2)
					print(answer)

					available_letters.remove(guess)
				else:
					print("Incorrect Guess")
					print(IMAGES[8 - chances])
					if chances == 1:
						print("You loss the game")
						print("The Secret Word is " + secret_word)
						print("")
					chances -=1
				if answer.lower() == secret_word:
						print("You won the game!!!")
						print("")
						break
			else:
				print("Please Enter one letter at time")
		except:
			print("")
			print(message)

	again = play_again()
	print(again)
		

words = ['mango','apple','london','america','lion','tiger','onion','bus','car','happy','beautiful','ugly','headphone']
hangman(words)