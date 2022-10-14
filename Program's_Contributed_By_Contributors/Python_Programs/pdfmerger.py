'''This program is a pdf merging tool which can combine multiple pdf documents into one document'''
'''The mechanism is very simple, consider 5 pdfs to be merged, so you'll name them as:
    1,2,3,4,5 according to the sequence you want to merge them in.
    Then, you'll enter 1 as the first doc number and 5 as the last doc number.
    Enter the name with which you want to save that document.
    After filling these inputs, the program will combine the pdfs and save it with the name provided.
'''
import PyPDF2
mergeFile = PyPDF2.PdfFileMerger()
first=int(input('The first document number'))
last=int(input('The last document number'))+1
name=input('Enter document name')
for i in range(first,last):
    mergeFile.append(PyPDF2.PdfFileReader(f'{i}.pdf', 'rb'))
mergeFile.write(f'{name}.pdf')
print('PDF Merger successful')

'''Code provided by Akshaj Vishwanathan'''
