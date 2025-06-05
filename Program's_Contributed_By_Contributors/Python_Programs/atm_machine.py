def initial_data():
	"""This function is used to keep records of the 3 main dict that is user,bank and atm"""
	global user_dict,banks, atm_dict,time_exceed,time_start_time 			# 3 main dict user_dict,banksdict,atm_dict

	user_dict = {1:{"account_num":"100","account_name":"DK","card_num":"1111","pin":"1234","amount":10000,"limit":4,"bank":2},
				2:{"account_num":"101","account_name":"Darshan","card_num":"2222","pin":"5678","amount":20000,"limit":4,"bank":3},
				3:{"account_num":"102","account_name":"Vasu","card_num":"3333","pin":"7867","amount":30000,"limit":4,"bank":1}}
	banks = {1:{"bank":"ICICI","location":"sadar","atm":[1],"users":[3]},
			2:{"bank":"SBI","location":"kalawad","atm":[2],"users":[1]},
			3:{"bank":"CBI","location":"indira","atm":[3],"users":[2]}}			
	atm_dict = {1:{"bank":1,"branch_code":"100","balance":20000},
				2:{"bank":2,"branch_code":"200","balance":10000},
				3:{"bank":3,"branch_code":"300","balance":20000}}
	time_start_time = time.time() + 600   # 10 min from now 
	atm_machine()

def user():
	"""
	This function is used to verify the details of a specific user of a bank

	Parameter index: stores key from user list
			  detail_user: stores the dict of a specific user verified
	          b_user: stores the reference of bank
	"""	
	while True:	

		global index,detail_user,b_user
		card = input("Enter the card_number: ")
		pin = input("Enter the pin: ")
		for i in range(1,len(user_dict)+1):
			if user_dict[i]['card_num']==card and user_dict[i]['pin']==pin:
				print("\nVerified\n\n")
				detail_user = user_dict[i]
				b_user = user_dict[i]['bank']
				index=i
				return 0
		print("\nEnter Proper details")

def user_detail():
	"""This function is used to give all the details of the user specific"""
	user()
	for i in detail_user:
		print(i,detail_user[i])

def bank_detail():
	"""
	This function is used to give all the details of a specific bank having all details of atms and users

	Parameter atm_values: stores the all the atms reference having specific bank
			  user_values:  stores all the users reference having specific bank
	"""

	choose_bank()
	print("\nDETAILS OF {} BANK are: \n".format(atm_temp[bank_key]))
	for i,j in banks.items():
		count=0
		for k,v in j.items():
			if v == atm_temp[bank_key]:
				count+=1

			if k == "atm" and count>0:
				atm_values = v

			if k == "users" and count>0:
				user_values = v

			if k == "location" and count>0:
				print(k,v)

	print("\nDETAILS OF ALL THE {} ATM'S OF {} BANK: \n".format(len(atm_values),atm_temp[bank_key]))

	for i, j in atm_dict.items():
		if i in atm_values:
			print("\n--------------")
			for k,v in j.items():
				if k == "bank":
					pass
				else:
					print(k,v)
			print("\n--------------")

	print("\nDETAILS OF ALL THE {} USER'S OF {} BANK: \n".format(len(user_values),atm_temp[bank_key]))
	for i, j in user_dict.items():
		if i in user_values:
			print("\n--------------")
			for k,v in j.items():
				if k == "bank":
					pass
				else:
					print(k,v)
			print("\n--------------")

def all_detail():
	"""
	This function is used to give all the details of the entire history of the bank

	Parameter atm_values: stores the all the atms reference having specific bank
			  user_values:  stores all the users reference having specific bank
	"""
	length = len(banks)
	count=1
	while length>0:
		print("\nDETAILS OF {} BANK are: \n".format(banks[count]['bank']))
		for i,j in banks.items():
			if i == count:
				for k,v in j.items():
					if k == "atm":
						atm_values = v

					if k == "users":
						user_values = v

					if k  == "location":
						print(k,v)

		print("\nDETAILS OF ALL THE {} ATM'S OF {} BANK: \n".format(len(atm_values),banks[count]['bank']))

		for i, j in atm_dict.items():
			if i in atm_values:
				print("\n--------------")
				for k,v in j.items():
					if k == "bank":
						pass
					else:
						print(k,v)
				print("\n--------------")

		print("\nDETAILS OF ALL THE {} USER'S OF {} BANK: \n".format(len(user_values),banks[count]['bank']))
		for i, j in user_dict.items():
			if i in user_values:
				print("\n--------------")
				for k,v in j.items():
					if k == "bank":
						pass
					else:
						print(k,v)
				print("\n--------------")

		length-=1
		count+=1

def atm_detail():
	"""
	This function is used to give all the details of available atms of a specific bank

	Parameter l: List is used to store the key in the userdict
	"""
	choose_bank()
	l=[]
	for i,j in user_dict.items():
		for k,v in j.items():
			if v == bank_key and k == "bank":
				l.append(i)

	print("\nDETAILS OF ALL THE {} USER'S OF {} ATM: \n".format(len(l),atm_temp[bank_key]))
	for i,j in user_dict.items():
		if i in l:
			print("\n--------------")
			for k,v in j.items():
				if k == "bank":
					pass
				else:
					print(k,v)
			print("\n--------------")

def withdraw():
	"""This function is used to withdraw money from any bank"""
	choose_bank()
	choose_branch()
	user()
	global user_dict,atm_dict

	if detail_user['limit']==0:
		print("\nYOU HAVE REACHED THE MAXIMUM LIMIT OF TRANSACTION FOR A DAY")
		atm_machine()

	else:
		try:
			withdraw = int(input("ENTER AMOUNT TO WITHDRAW: "))

			if withdraw > int(detail_user['amount']):
				print("YOU HAVE INSUFFICIENT BALANCE")

			elif atm_dict[bank_key]['balance'] - withdraw <=0:
				print("BANK IS CURRENTLY RUNNING OUT OF CASH") 

			elif detail_user['amount'] - withdraw < 400:
				print("MIN BALANCE SHOULD NOT BE BREACHED")

			elif withdraw > 10000:
				print("YOU CAN TAKE OUT A MAXIMUM OF 10000")

			else:
				if d_user!=b_user:
					detail_user['amount'] = detail_user['amount'] - withdraw
					atm_dict[bank_key]['balance'] = atm_dict[bank_key]['balance'] - withdraw
					print("\nTAKE YOUR MONEY: {}".format(withdraw*0.95))

				else:
					detail_user['amount'] = detail_user['amount'] - withdraw
					atm_dict[bank_key]['balance'] = atm_dict[bank_key]['balance'] - withdraw
					print("\nTAKE YOUR MONEY: {}".format(withdraw))
				print("YOUR NEW BALANCE IS {} ".format(detail_user['amount']))
				detail_user['limit']-=1
				atm_machine()
		except ValueError:
			print("ENTER PROPER VALUES")

def deposit():
	"""This function is used to deposit money into his specific bank"""
	choose_bank()
	choose_branch()
	user()
	global user_dict,atm_dict
	if detail_user['limit']==0:
		print("\nYOU HAVE REACHED THE MAXIMUM LIMIT OF TRANSACTION FOR A DAY")
		atm_machine()

	elif detail_user['bank']!=bank_key:
		print("\nYOU CANNOT DEPOSIT FROM ANOTHER BANK\n")
		atm_machine()
	else:
		try:
			deposit = int(input("ENTER AMOUNT TO DEPOSIT: "))
			detail_user['amount'] = detail_user['amount'] + deposit
			atm_dict[bank_key]['balance'] = atm_dict[bank_key]['balance'] + deposit

			print("YOUR NEW BALANCE IS {} ".format(detail_user['amount']))
			detail_user['limit']-=1
			atm_machine()
		except ValueError:
			print("ENTER PROPER VALUES")
			atm_machine()

def user_add():
	"""
	This function is used to add the user to a particular bank

	Parameter new_user: It is a dict that is used to store all the details of new user and then append in user_dict
	"""
	choose_bank()

	global user_dict
	import random
	new_user=dict()
	new_user['account_num'] = str(random.randint(100,999))
	print("\nGIVE ACCOUNT HOLDER NAME: \n")
	name = input()
	if name.isalpha()==False:
		print("\nENTER PROPER NAME")
		atm_machine()
	new_user['account_name'] = name
	new_user['card_num'] = str(random.randint(1000,9999))
	new_user['pin'] = str(random.randint(1000,9999))
	new_user['bank'] = bank_key
	new_user['amount'] = 10000
	new_user['limit'] = 4
	print(new_user['card_num'],new_user['pin'])
	user_dict[len(user_dict)+1]=new_user
	banks[bank_key]['users'].append(len(user_dict))
	print("\nUSER ADDED SUCCESSFULLY\n")

def user_update():
	"""This function is used to update the details of a specific users like pin,accountname and bank"""
	user()
	print("\n\nUPDATE USERNAME --> 1 \nUPDATE PIN --> 2 \nUPDATE BANK --> 3 \nBACK --> 4")
	choice = input("\nENTER FROM ABOVE CHOICES: ")

	if choice == "1":
		update_user = input("\nENTER THE NEW ACCOUNT NAME: \n")
		detail_user['account_name']=update_user
		print("\nUSER ACCOUNT NAME DETAILS UPDATED SUCCESSFULLY")
		atm_machine()

	elif choice == "2":
		update_pin = input("\nENTER THE NEW PIN: \n")
		update_cpin = input("\nENTER AGAIN TO CONFIRM THE PIN: \n")
		if update_pin==update_cpin:
			detail_user['pin']=update_pin
			print("\nUSER ACCOUNT PIN DETAILS UPDATED SUCCESSFULLY")
		else:
			atm_machine()

	elif choice == "3":
		choose_bank()
		a=detail_user['bank']
		detail_user['bank'] = bank_key


		for i,j in banks.items():
			if j['bank'] == atm_temp[bank_key]:
				j['users'].append(index)
			if i == b_user:
				j['users'].remove(index)
		print("\nBANK UPDATED SUCCESSFULLY\n")
	elif choice == "4":
		atm_machine()
	else:
		print("\nENTER FROM ABOVE CHOICES")

def user_delete():
	"""This function is used to delete the user from a specific bank"""
	global detail_user,index
	user()
	confirm = input("\nARE U SURE U WANT TO DELETE THE ACCOUNT \nType 1 for yes\nType 2 for cancel\n")
	if confirm == "1":
		
		for i,j in banks.items():
			if i==b_user:
				for k,v in j.items():
					if k=="users":
						print(v)
						v.remove(index)
						break

		del user_dict[index]
		print(banks)
		print(user_dict)
		print("\nACCOUNT HOLDER DELETED SUCCESSFULLY")
		#atm_bank()
	elif confirm == "2":
		atm_machine()
	else:
		print("ENTER FROM ABOVE CHOICES")
		pass

def bank_add():
	"""This function is used to add the bank""" 
	while True:

		new_bank = input("\nENTER THE NEW BANK NAME: \n")
		count=0
		for i,j in banks.items():
			for k,v in j.items():
				if new_bank == v:
					print("BANK ALREADY EXIST")
					count+=1
		if count==0:
			new_bank_dict = dict()
			new_bank_dict['bank'] = new_bank
			new_location = input("\nGIVE LOCATION: \n")
			if new_location.isalpha()==False:
				print("\nENTER PROPER LOCATION")
				atm_machine()
			new_bank_dict['location'] = new_location
			new_bank_dict['atm'] = []
			new_bank_dict['users'] = []
			banks[len(banks)+1] = new_bank_dict
			print(banks)
			break

def bank_update():
	"""This function is used to update the details of a specific bank"""
	choose_bank()
	# user()
	while True:

		update_location = input("\nENTER THE NEW LOCATION: \n")
		count=0
		if update_location.isalpha()==False:
			print("ENTER PROPER LOCATION")
		else:
			banks[bank_key]['location']=update_location
			print("\nBANKS UPDATED SUCCESSFULLY")
			break

def bank_delete():
	"""
	This function is used to delete the bank along with its users and atms

	Parameter new_dict: It is a dict to store the details of usersdict and then atmdict
	"""
	choose_bank()
	global user_dict, atm_dict
	confirm = input("\nARE U SURE U WANT TO DELETE THE ACCOUNT \nType 1 for yes\nType 2 for cancel\n")
	if confirm == "1":
		for i,j in banks.items():
			for k,v in j.items():
				if v == atm_temp[bank_key]:
					temp=i
		for i,j in banks.items():
			if temp==i:
				del banks[i]
				break

		new_dict=dict()
		for i,j in user_dict.items():
			count=0
			for k,v in j.items():
				if v == temp and k == "bank":
					count+=1
			if count==0:
				new_dict[i] = j
		del user_dict
		user_dict = new_dict		

		new_dict=dict()
		for i,j in atm_dict.items():
			count=0
			for k,v in j.items():
				if v == temp and k == "bank":
					count+=1
			if count==0:
				new_dict[i] = j
		del atm_dict
		atm_dict = new_dict
		print("\nBANK DELETED SUCCESSFULLY")

	elif confirm == "2":
		atm_machine()
	else:
		print("ENTER FROM ABOVE CHOICES")
		pass

def money_insert():
	"""This function is used to insert money into the atm of a specific branch""" 
	choose_bank()
	choose_branch()
	try:
		money = int(input("\nENTER THE MONEY TO INSERT IN {} BANK\n".format(atm_temp[bank_key])))
		atm_dict[d_user]['balance'] = atm_dict[d_user]['balance'] + money
		print(atm_dict[d_user]['balance'])
	except:
		print("ENTER PROPER VALUES")

def atm_add():
	"""This function is used to add the atm of a bank having unique branchcode"""
	choose_bank()
	while True:

		count=0
		import random
		new_atm = dict()
		new_branch = str(random.randint(100,999))
		for i,j in atm_dict.items():
			for k,v in j.items():
				if v==new_branch:
					print("ATM ALREADY EXIST")
					count+=1
					break
		if count==0:
			new_atm['bank'] = bank_key
			new_atm['branch_code'] = new_branch
			new_atm['balance'] = 10000
			atm_dict[len(atm_dict)+1] = new_atm
			banks[bank_key]['atm'].append(len(atm_dict))
			print(atm_dict)
			print(banks)
			print("\nATM ADDED SUCCESSFULLY")
			break	

def atm_update():
	"""This function is used to update the atm branch code of a specific atm"""
	choose_bank()
	choose_branch()
	count=0
	global atm_dict
	while True:

		update_atm = input("\nENTER THE NEW BRANCH CODE: \n")

		for i,j in atm_dict.items():
			for k,v in j.items():
				if v == atm_t[branch_key]:
					atm_dict[bank_key]['branch_code'] = update_atm
					print(atm_dict[bank_key]['branch_code'])
					print(atm_dict)
					count+=1
					break
		if count==0:
			print("\nENTER PROPER BRANCH CODE\n")
		break

def atm_delete():
	"""This function is used to delete the atm of a specific bank having unique branchcode"""
	choose_bank()
	choose_branch()
	confirm = input("\nARE U SURE U WANT TO DELETE THE ACCOUNT \nType 1 for yes\nType 2 for cancel\n")
	if confirm == "1":
		try:
			for i,j in banks.items():
				if i==d_user:
					for k,v in j.items():
						if k=="atm":
							v.remove(bank_key)
							break

			for i,j in atm_dict.items():
				for k,v in j.items():
					if v == atm_t[branch_key]:
						del atm_dict[bank_key]
						print("ATM DELETED SUCCESSFULLY")
						atm_machine()
		except:
			print("ENTER PROPER VALUES")
	elif confirm == "2":
		atm_machine()
	else:
		print("\nENTER PROPER VALUES")
		pass
	
def choose_bank():
	"""
	This function is used to choose a bank from a bunch of available banks

	Parameter atm_temp: It is a dict which stores the value as the bank name
			  bank_key: It is used to get the key of the atm_temp dict
	"""
	print("\nChoose BANK:\n")
	global atm_temp, bank_key
	j=1
	atm_temp = dict()
	for i,k in banks.items():
	    for x,y in k.items():
	        if x == "bank":
	            atm_temp[j]=y
	            a=y
	    print(f"{j}:{a}")
	    j+=1

	while True:
		try:
			bank_key=int(input())
			print("Welcome to {} bank".format(atm_temp[bank_key]))
			break
		except ValueError:
			print("\nENTER ONLY INTEGERS")
			atm_machine()
		except KeyError:
			print("\nENTER FROM ABOVE CHOICES")
			atm_machine()

def choose_branch():
	"""
	This function is used to choose a branch from a bunch of available branches of a specific bank

	Parameter atm_t: It is a dict to store the bank in the value
			  branch_key: It takes as an input for the key in atm_t dict
			  d_user: It stores the reference of the specific bank
	"""
	count=0
	j=1
	global d_user,atm_t,branch_key
	atm_t = dict()
	print("\nChoose a branch: \n")
	for i,k in atm_dict.items():
	    for x,y in k.items():
	    	if y == bank_key:
	        	count+=1
	    	if x == "branch_code" and count>0:
	        	atm_t[j]=y
	    	if x == "bank" and count>0:
	        	d_user=y
	    j+=1
	    count=0
	if len(atm_t)==0:
		print("NO ATMS ARE PRESENT FOR THE BANK")
		atm_machine()
	for i,j in atm_t.items():
		print(f"{i}:{j}")

	while True:
		try:
			branch_key=int(input())
			print("Welcome to {} branch".format(atm_t[branch_key]))
			break	
		except ValueError:
			print("\nENTER ONLY INTEGERS")
			atm_machine()
		except KeyError:
			print("\nENTER PROPERLY FROM ABOVE CHOICES\n")
			atm_machine()

import time 

def limit_reset():
	for i,j in user_dict.items():
		j['limit'] = 4

def atm_machine():

	""""This function is used to keep continuously calling the atm to proceed further"""
	global detail_user, bank_key, atm_temp, time_exceed,time_start_time

	while True:

		# if present time exceeds the script start time, then limit is reset
		if time.time() > time_start_time:
			limit_reset()
			time_start_time = time.time()


		print("\n\nINSERT --> 1 \nUPDATE --> 2 \nDELETE --> 3  \nDISPLAY --> 4  \nTRANSACTION --> 5  \nEXIT --> 6")
		response = input("ENTER FROM ABOVE CHOICES: ")

		if response == "1":
			print("\n\nADD USER --> 1 \nADD BANK --> 2 \nADD ATM --> 3 \nBACK --> 4")
			choice = input("\nENTER FROM ABOVE CHOICES: ")
			if choice == "1":
				user_add()
			elif choice == "2":
				bank_add()
			elif choice == "3":
				atm_add()
			elif choice == "4":
				atm_machine()
			else:
				print("\nENTER FROM ABOVE CHOICES")
			
		elif response == "2":
			print("\n\nUPDATE USER --> 1 \nUPDATE BANK --> 2 \nUPDATE ATM --> 3  \nMONEY INSERT --> 4  \nBACK --> 5")
			choice = input("\nENTER FROM ABOVE CHOICES: ")
			if choice == "1":
				user_update()
			elif choice == "2":
				bank_update()
			elif choice == "3":
				atm_update()
			elif choice == "4":
				money_insert()
			elif choice == "5":
				atm_machine()
			else:
				print("\nENTER FROM ABOVE CHOICES")
				
		elif response == "3":
			print("\n\nDELETE USER --> 1 \nDELETE BANK --> 2 \nDELETE ATM --> 3 \nBACK --> 4")
			choice = input("\nENTER FROM ABOVE CHOICES: ")
			if choice == "1":
				user_delete()
			elif choice == "2":
				bank_delete()
			elif choice == "3":
				atm_delete()
			elif choice == "4":
				atm_machine()
			else:
				print("\nENTER FROM ABOVE CHOICES")

		elif response == "4":
			print("\n\nDETAIL USER --> 1 \nDETAIL BANK --> 2 \nDETAIL ATM --> 3 \nALL DETAILS --> 4\nBACK --> 5")
			choice = input("\nENTER FROM ABOVE CHOICES: ")
			if choice == "1":
				user_detail()
			elif choice == "2":
				bank_detail()
			elif choice == "3":
				atm_detail()
			elif choice == "4":
				all_detail()
			elif choice == "5":
				atm_machine()
			else:
				print("\nENTER FROM ABOVE CHOICES")

		elif response == "5":
			print("\n\nWITHDRAW --> 1 \nDEPOSIT --> 2 \nBACK --> 3")
			choice = input("\nENTER FROM ABOVE CHOICES: ")
			if choice == "1":
				withdraw()
			elif choice == "2":
				deposit()
			elif choice == "3":
				atm_machine()
			else:
				print("\nENTER FROM ABOVE CHOICES")
			deposit()

		elif response == "6":
			exit()

		else:
			print("RESPONSE NOT VALID")
# 
if __name__ == "__main__":
	initial_data()

