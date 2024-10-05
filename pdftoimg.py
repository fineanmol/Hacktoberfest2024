# PDF to Images

import fitz

pdf = 'sample_pdf.pdf'
doc = fitz.open(pdf)

for page in doc:
    pix = page.getPixmap(alpha=False)
    pix.writePNG('page-%i.png' % page.number)
