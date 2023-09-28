# importing csv module
import csv
 
# csv file name
answer = input("What is the name of the file (add .csv to the end): ")

filename = answer

    
# initializing the titles and rows list
fields = []
rows = []
     
# reading csv file
with open(filename, 'r') as csvfile:
    # creating a csv reader object
    csvreader = csv.reader(csvfile)
         
    # extracting field names through first row
    fields = next(csvreader)
     
    # extracting each data row one by one
    for row in csvreader:
        rows.append(row)
     
    # get total number of rows
    print("Total no. of rows: %d"%(csvreader.line_num))
     
# printing the field names
print('Field names are:' + ', '.join(field for field in fields))
     
# printing first 5 rows
print('\nFirst 100 rows are:\n')
for row in rows[:100]:
    # parsing each column of a row
    for col in row:
        print("%10s"%col,end=" "),
    print('\n')
input("press enter to close")


    



