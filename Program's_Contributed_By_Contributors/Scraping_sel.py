'''
Author - Seema Kumari Patel
Web scraping using selenium 
'''


# Import the library Selenium 
from selenium import webdriver 
from selenium.webdriver.common.action_chains import ActionChains 

# Make browser open in background 
options = webdriver.ChromeOptions() 
options.add_argument('headless') 

# Create the webdriver object 
browser = webdriver.Chrome( 
	executable_path="C:\chromedriver_win32\chromedriver.exe", 
options=options) 

# Obtain the Google Map URL 
url = ["https://www.google.com/maps/place/\ 
Papa+John's+Pizza/@40.7936551,-74.0124687,17z/data=!3m1!4b1!\ 
4m5!3m4!1s0x89c2580eaa74451b:0x15d743e4f841e5ed!8m2!3d40.\ 
7936551!4d-74.0124687", "https://www.google.com/maps/place/\ 
Lucky+Dhaba/@30.653792,76.8165233,17z/data=!3m1!4b1!4m5!3m4!\ 
1s0x390feb3e3de1a031:0x862036ab85567f75!8m2!3d30.653792!4d76.818712"] 
# Initialize variables and declare it 0 
i = 0

# Create a loop for obtaining data from URLs 
for i in range(len(url)): 

	# Open the Google Map URL 
	browser.get(url[i]) 

	# Obtain the title of that place 
	title = browser.find_element_by_class_name( 
		"x3AX1-LfntMc-header-title-title") 
	print(i+1, "-", title.text) 

	# Obtain the ratings of that place 
	stars = browser.find_element_by_class_name("aMPvhf-fI6EEc-KVuj8d") 
	print("The stars of restaurant are:", stars.text) 
	print("\n")