##################### Extra Hard Starting Project ######################
import pandas
import random
import datetime as dt
import smtplib

my_email = "4testingcode@gmail.com"
password = "testingcode4@()"

now = dt.datetime.now()
today = (now.month, now.day)
data = pandas.read_csv("birthdays.csv")
data_dict = {(data_row.month, data_row.day): data_row for (index, data_row) in data.iterrows()}
# 2. Check if today matches a birthday in the birthdays.csv

if today in data_dict:
    birthday_person = data_dict[today]
    print(birthday_person["name"])
    file_path = f"letter_templates/letter_{random.randint(1, 3)}.txt"
    with open(file_path) as letter_file:
        content = letter_file.read()
        new_content = content.replace("[NAME]", birthday_person["name"])
        with smtplib.SMTP("smtp.gmail.com", 587) as connection:
            connection.starttls()
            connection.login(user=my_email, password=password)
            connection.sendmail(from_addr=my_email, to_addrs=birthday_person["email"],
                                msg=f"Subject:Happy Birthday\n\n{new_content}")

# 4. Send the letter generated in step 3 to that person's email address.
