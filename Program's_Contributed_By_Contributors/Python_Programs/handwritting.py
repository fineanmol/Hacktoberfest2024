import pywhatkit as pw
f = open("demo.txt")
txt = f.read()
pw.text_to_handwriting(txt,"demo.png",[0,0,138])