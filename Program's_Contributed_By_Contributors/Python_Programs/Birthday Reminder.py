# Python program For
# Birthday Reminder Application

# time module is must as reminder
# is set with the help of dates
import time

# os module is used to notify user
# using default "Ubuntu" notification bar
import os

# Birthday file is the one in which the actual birthdays
# and dates are present. This file can be
# manually edited or can be automated.
# For simplicity, we will edit it manually.
# Birthdays should be written in this file in
# the format: "MonthDay Name Surname" (Without Quotes)

birthdayFile = '/path/to/birthday/file'

def checkTodaysBirthdays():
	fileName = open(birthdayFile, 'r')
	today = time.strftime('%m%d')
	flag = 0
	for line in fileName:
		if today in line:
			line = line.split(' ')
			flag =1
			# line[1] contains Name and line[2] contains Surname
			os.system('notify-send "Birthdays Today: ' + line[1]
			+ ' ' + line[2] + '"')
	if flag == 0:
			os.system('notify-send "No Birthdays Today!"')

if __name__ == '__main__':
	checkTodaysBirthdays()
