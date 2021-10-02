from os.path import exists
import os
"""
1. Enter details of student 
2. View Student details 
3. Search for student 
4. Remove a student's entry 
5. Delete previos student data 
6. Exit

"""

details = ["Name","Roll no","DIV","Contact no","Email ID","Branch Name","Address"]
validLength = { "Contact no":10,"Roll no":9,"DIV":1}

def info(fp):
	for i in details:
		data = input("Enter "+ i + " :")

		if (i == "Contact no" or i == "Roll no" or i == "DIV"):
			while (len(data) != validLength[i] and len(data) != 0):
				data = input("Enter valid "+ i + " :")
		fp.write(data + ",")
	fp.write("\n")
	return
	
	
def readFile (filename):
	if exists(filename):
		f = open(filename, "r")
		lines = f.readlines()
		for line in lines:
			print("\n")
			dataStudent = line.split(',')
			for i,l in enumerate(details):
				print("\t"+details[i]+" : ",dataStudent[i])
		print("------------------------------------------")
		f.close()
	else:
		print("\nNo entries are added until now\n")
		
def menu():
	choice = 1
	title = "\n\n\t------------------------------------------\n\t----------------- MENU -------------------  \n\t------------------------------------------\n"
	print(title)
	while (choice != 6):
		
		menu = "\n\n------------------------------------------\n1. Enter details of student \n2. View Student details \n3. Search for student \n4. Remove a student's entry \n5. Delete previos student data \n6. Exit\n \nEnter choice here :"
		choice = int(input(menu))
		print("------------------------------------------")
		filename = "studentData.txt"
		
		if choice ==1:
			add_info = 1
			while add_info == 1:

				print("\n\nEnter the Student information:")
				if exists(filename):
					fp = open(filename, "a")
				else:
					fp = open(filename, "w")
				info(fp)
				

				x = input("\n\nDo you want to exit?(yes/no):")
				if(x.upper() == "YES" or x.upper() == "Y"):
					continue
				else:
					add_info = 0
					fp.close()
				
					
		if choice == 2:
			readFile(filename)  # function instead of following lines
			
			"""
			if exists(filename):
				f = open(filename, "r")
				lines = f.readlines()
				for line in lines:
					print("\n")
					dataStudent = line.split(',')
					for i,l in enumerate(details):
						print(details[i]+" : ",dataStudent[i])
				print("------------------------------------------")
				f.close()
			else:
				print("\nNo entries are added until now\n")
			"""
		if choice == 3:
			found = 0
			name = input("Enter student name/Roll no:")
			if exists(filename):
				f = open(filename, "r")
				lines = f.readlines()
				for line in lines:
					if (line.find(name) !=-1 or line.find(name.lower()) !=-1 or line.find(name.upper()) !=-1):
						print("Student Record Found")
						dataStudent = line.split(',')
						for i,l in enumerate(details):
							print(details[i]+" : ",dataStudent[i])
						found = 1
						break
				if found == 0:
					print("Record not found for the student")
				print("------------------------------------------")
				f.close()
			else:
				print("\nNo entries are added until now\n")
		
		if choice == 4:
			if exists(filename):
				f = open(filename, "r")
				lines = f.readlines()
				name = input("Enter name of student:")
				Roll no = input("Enter Roll no of student:")
				f.close()
				f = open(filename, "w")
				for line in lines:
					if Roll no in line and name in line:
						pass
					else:
						f.write(line)
				f.close()
				print("\nStudent's entry removed successfully")
			else:
				print("\nNo entries are added until now\n")
		
		
		if choice == 5:
			os.remove(filename)
			
		if choice == 6:
			print("\n\tThank you")
			print("------------------------------------------")
if __name__ == "__main__":
	menu()
