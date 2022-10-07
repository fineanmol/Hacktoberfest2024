from datetime import datetime



def current_time():
    return datetime.now().time().strftime("%H:%M:%S")

print(current_time())    