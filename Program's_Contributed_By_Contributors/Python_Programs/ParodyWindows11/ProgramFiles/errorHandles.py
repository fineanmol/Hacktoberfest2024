PRESETS_DICT = {
     'APP_NOT_FOUND_ERROR' : "The specified app doesn't exist!",
     'MODULE_NOT_FOUND_ERROR' : "The requested module wasn't found!",
     'INTERNET_ERROR' : "The specified website took too long to respond!",
     'LOGIN_ERROR' : "Cannot login due to a technical issue with the Account configuration\\User Folder\\Landing Page problem",
     'DESKTOP_APP_PIN_ERROR' : "Cannot pin the apps due to technical glitch!",
     'LOGIN_INCORRECT' : "Either the username or the password or the user number is wrong! Please try again!",
     'DESKTOP_APP_FULL': 'The desktop is unable to pin anymore items to the taskbar or desktop\nTo add moore, please clear up some icons then add icons!',}
def find_item(preset):
     if preset in PRESETS_DICT: return PRESETS_DICT[preset]
     else: return " "