import threading

def write_alpha(inputText):
    with open('output1.txt','w')as file1:
        for char in inputText:
            if char.isalpha():
                file1.write(char)

def write_digit(inputText):
    with open('output2.txt','w')as file2:
        for char in inputText:
            if char.isdigit():
                file2.write(char)

def write_symb(inputText):
    with open('output3.txt','w')as file3:
        for char in inputText:
            if not char.isalnum():
                file3.write(char)


if __name__ == "__main__":
    with open('input.txt','r') as file:
        inputText = file.read()

t1 = threading.Thread(target=write_alpha(inputText,),name="WriteAlpha")
t2 = threading.Thread(target=write_digit(inputText,),name="Thread2")
t3 = threading.Thread(target=write_symb(inputText,),name="Thread3")

t1.start()
t2.start()
t3.start()
t1.join()
t2.join()
t3.join()
