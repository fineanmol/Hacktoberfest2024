import pikepdf

# Opening the text files with all the files names which can be copied easily with the help of following youtube video
# https://www.youtube.com/watch?v=A9Z8AzSMAvs
file_name = open('File_names.txt')

# creating the list with the files name and we used strip() to remove \n
list_of_file_name = []
for each in file_name:
    list_of_file_name.append(each.strip())

# Opening the files saved Files folder which is in the present working directory 
#looping through files names in the list 
for i in list_of_file_name:
    pdf = pikepdf.open('Files\\'+i, password = 'password', allow_overwriting_input= True)
    pdf.save(i)

