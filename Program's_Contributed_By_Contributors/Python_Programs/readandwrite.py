data = "data for appending..."

with open('input.txt','r') as file:
    content = file.read()

with open('output.txt','w') as file:
    file.write(content)
print("Write completed!!\n\n")


with open('output.txt','a') as file:
    file.write('\n'+ data)
print("Appending finished")