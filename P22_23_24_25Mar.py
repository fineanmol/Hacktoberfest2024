from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time, pyperclip, re
print('Fetch Attendance Details using Python')
print('                               -by botbaba_bbc')
print('\n')
username=input('Enter Username: ')
username=username.upper()
pswd=input('Enter Password: ')
term=input('Enter Term: ')

#Sign-In Process
browser=webdriver.Chrome()
browser.get('http://180.233.120.196:35321/ps/signon.html')
time.sleep(2)
rollnum=browser.find_element_by_name('userid')
rollnum.send_keys(username)
password=browser.find_element_by_name('pwd')
password.send_keys(pswd)
signin=browser.find_element_by_name('submit')
signin.click()
time.sleep(1)

#Navigating to Attendance Roaster
browser.find_element_by_link_text('Curriculum Management').click()
browser.switch_to.frame('ptifrmtgtframe')
browser.find_element_by_link_text('Attendance Roster By Student').click()
browser.switch_to.frame('ptifrmtgtframe')
browser.find_element_by_link_text(term).click()
time.sleep(5)
browser.find_element_by_tag_name('html').send_keys(Keys.CONTROL + 'a')
browser.find_element_by_tag_name('html').send_keys(Keys.CONTROL + 'c')
str=pyperclip.paste()
regex=re.compile(r'Total Attendance in %:\n\d+\S\d+', re.DOTALL)
percen=regex.findall(str)
print('Total Attendance in %: ', end='')
print(len(percen))
#browser.quit()
