# Define a function for printing particular messages
def display(Num):
    
    if Num % 3 == 0 and Num % 5 == 0 :
        print("Zoom")
        
    elif Num % 3 == 0 :
        print("Zip")
    
    elif Num % 5 == 0 :
        print("Zap")
        
    else :
        print("Invalid")
        

# Main code
if __name__ == "__main__" :
    
    Num = 9

    # Function call
    display(Num)
    
    Num = 10
    display(Num)
    
    Num = 15
    display(Num)

    Num = 19
    display(Num)
