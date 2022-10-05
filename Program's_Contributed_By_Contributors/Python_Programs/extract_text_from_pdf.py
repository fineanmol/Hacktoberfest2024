# import module PyPDF2
import PyPDF2
# put 'example.pdf' in working directory
# and open it in read binary mode
pdfFileObj = open('example.pdf', 'rb')
# call and store PdfFileReader
# object in pdfReader
pdfReader = PyPDF2.PdfFileReader(pdfFileObj)
# to print the total number of pages in pdf
print(pdfReader.numPages)
# get specific page of pdf by passing
# number since it stores pages in list
# to access first page pass 0
pageObj = pdfReader.getPage(0)
# extract the page object
# by extractText() function
texts = pageObj.extractText()
# print the extracted texts
print(texts)