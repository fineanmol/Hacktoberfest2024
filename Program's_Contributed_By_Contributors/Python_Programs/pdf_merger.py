from PyPDF2 import PdfMerger

pdfs = ['1.pdf', '2.pdf', '3.pdf'] ## ordered

merger = PdfMerger()

for pdf in pdfs:
    if pdf == '3.pdf':
        merger.append(pdf, pages=(0,1))
    else:
        merger.append(pdf)

merger.write("merged.pdf")
merger.close()
