import PyPDF2

template = PyPDF2.PdfFileReader(open('Combined.pdf','rb')) #Enter name of PDF to be watermarked in place of Combined.pdf
watermark = PyPDF2.PdfFileReader(open('wtr.pdf','rb')) #Enter the name of PDF containing the watermark in place of wtr.pdf
output = PyPDF2.PdfFileWriter()

for i in range(template.getNumPages()):
	page = template.getPage(i)
	page.mergePage(watermark.getPage(0))
	output.addPage(page)

	with open('CombinedWatermark.pdf','wb') as file:
		output.write(file)

#The resultant PDF is saved as CombinedWatermark.pdf 