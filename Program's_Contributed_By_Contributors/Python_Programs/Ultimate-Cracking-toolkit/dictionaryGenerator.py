#/!python
#!/usr/bin/python
import pathlib

def intro():
	print("\t\t\t Tool: Dictionary Generator  \n |\t\tCoded By Bishal Aryal Batch30 Ethical Hacking \n | \t\t\t Twitter @C15C01337")
	print("_"*80+"\n")
	print("Welcome to the Password Generator")

def main():
	intro()
	#A file with an . lst extension is most likely a text file that contains a list of data.
	file = pathlib.Path("passwordRule.lst")  
	if file.exists():
		execute()
	else:
		CreateRule()
		execute()
	pass

def CreateRule():
	print (f"Hello,\n\n\t The password rule list for creation (passwordRule.lst) not found,\n\t Let's make one specifically for you.\n\nBest Regards,\nYour @C15C01337")
	f = open("passwordRule.lst", "a")
	f.write("{}123\n{}@123\n{}12345\n{}987654321\n{}445566\n{}2021\n{}@2021\n{}@2022\n2022!{}\n")
	f.close()
	print("_"*80+"\n")

def execute():
	with open('passwordRule.lst') as genformat:
		word = input("Please enter the word: ").lower()
		
		if len(word)==1:
			print(f"User Input Type was \"Word\"")
			word = word[0]

		print("_"*85)
		print(f"\nCreating a List of Common Passwords("+word+f".txt)")
		print("_"*85+"\n")

		for x in genformat:
		#The rstrip() method removes any trailing characters (characters at the end a string), space is the default trailing character to remove.
			x = x.rstrip('\n').format(word) 
			print(x+"\n"+x.upper()+"\n"+x.capitalize()+"\n")
			f = open(word+".txt", "a")
			f.write(x+"\n"+x.upper()+"\n"+x.capitalize()+"\n")
			f.close()
	print("_"*85+f"\n\n\t Making you happy is our True Mission :) ....")
	print("_"*85+"\n")

if __name__ == "__main__":
	main()