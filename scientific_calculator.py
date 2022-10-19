from tkinter import *
import math, struct, idlelib.tooltip

# Rizky Ananta - github.com/anantaristik

class Supercalculator(object):
    def __init__(self):
        win = Tk()
        win.title('Supercalculator by Rizky Ananta DDP1/A')
        # label tombol
        buttons = [[   'Clr',    'MC',     'M+',   'M-',     'MR'],
                   [    'd' ,     'e',      'f',    '+',      '-'],
                   [     'a',     'b',      'c',    '/',      '*'],
                   [     '7',     '8',      '9',   '**', '\u221a'],
                   [     '4',     '5',      '6',  'sin',    'cos'],
                   [     '1',     '2',      '3',  'tan',     'ln'],
                   [     '0',     '.', '\u00b1',    '~',     '2C'],
                   [     'x',     'o',      '^',    '|',      '&'],
                   ['\u03c0',   'int',    'rad',   '//',    'exp'],
                   [ '→IEEE', '←IEEE',   'asin', 'acos',   'atan'],
                   [   'bin',   'hex',    'oct',    '%',      '=']]
       
        # deskripsi tombol lagu
        description = [['Clear the display field', 'Clear memory', 'Add to memory', 'Substract from memory', 'Recall from memory'],
                        ['letter d', 'letter e', 'letter f', 'addition', 'subtraction'],
                        ['letter a', 'letter b', 'letter c', 'division', 'multiplication'],
                        ['digit 7', 'digit 8', 'digit 9', 'exponent', 'squareroot'],
                        ['digit 4', 'digit 5', 'digit 6', 'sin(x) in radians', 'cos(x) in radians'],
                        ['digit 1', 'digit 2', 'digit 3', 'tan(x) in radians', 'natural logarithm'],
                        ['digit 0', 'decimal point', 'sign toggle', "1's complement", "2's complement"],
                        ['letter x', 'letter o', 'bitwise xor', 'bitwise or', 'bitwise ans'],
                        ['pi', 'convert to integer', 'convert to radians', 'integer division', "Euler's nummber"],
                        ['decimal to 64-bit IEEE 754 representation (in hex)', '64-bit IEEE 754 representation (in hex) to decimal', 'arcsin(x) in radians', 'arccos(x) in radians', 'arctan(x) in radians'],
                        ['convert to base-2', 'convert to base-16', 'convert to base-8', 'modulus', 'evaluate']]
        
        # memasukkan entry widget untuk display
        self.entry = Entry(win, relief=RIDGE, borderwidth=5, width=24, font=('Helvetica', 18), fg='blue')
        self.entry.grid(row=0, column=0, columnspan=5, padx=16, sticky=N+S+E+W)

        # membuat dan menempatkan tommbol pada baris dan kolom
        for r in range(len(buttons)):
            for c in range(len(buttons[r])):
                def cmd(x=buttons[r][c]):
                    self.click(x)
                b = Button(win, text=buttons[r][c], width=6, relief=RAISED, command=cmd, font=('Helvetica', 18, 'bold'), bg='navy', fg='white')
                b.grid(row=r+1, column=c, sticky=N+S+E+W)
                idlelib.tooltip.Hovertip(b, description[r][c]) # memasukan description untuk setiap tombol

        self.memory = '' # memory
        self.expr = '' # current expression
        self.startOfNextOperand = True # start of new operand

        win.mainloop()

    def click(self, tombol):
        if tombol == '=':
            # menjalankan tombol '=' dengan menampilkan hasil di entry
            try:
                hasil = eval(self.expr + self.entry.get())
                self.entry.delete(0, END)
                self.entry.insert(END, hasil)
                self.expr = ''
                self.startOfNextOperand = True
            except:
                self.entry.delete(0,END)
                self.entry.insert(END, 'Error')
                self.startOfNextOperand = True

        elif tombol == 'Clr':
            # menghapus entry dan perhitungan
            self.entry.delete(0,END)
            self.expr = ''
        
        elif tombol == 'MC':
            # menghapus memori
            self.memory = ''
        
        elif tombol in ['M+', 'M-']:
            # M+ menambahkan nilai ke memori, M- mengurangi nilai ke memori
            try:
                if self.memory == '':
                    self.memory = '0'
                if tombol == 'M+':
                    self.memory = str(float(self.memory) + float(self.entry.get()))
                elif tombol == 'M-':
                    self.memory = str(float(self.memory) - float(self.entry.get()))
            except:
                self.entry.delete(0,END)
                self.entry.insert(END,'Error')
        
        elif tombol == 'MR':
            # menampilkan nilai di memori
            self.entry.delete(0,END)
            self.entry.insert(END,self.memory)
        
        elif tombol in ['+', '*', '/', '//', '%', '**', '^', '|', '&']:
            # menambahkan operator yang ditampilkan di entry dengan operator yang akan dimunculkan nantinya
            self.expr += self.entry.get()
            self.expr += tombol
            self.startOfNextOperand = True

        elif tombol in 'abcdef0123456789.xo':
            # memasukkan angka, huruf, atau titik sebagai operator selanjutnya
            if self.startOfNextOperand:
                self.entry.delete(0, END)
                self.startOfNextOperand = False
                
            self.entry.insert(END, tombol)
            
        elif tombol in ['rad','\u221a', 'exp','sin', 'cos', 'tan', 'ln','asin', 'acos', 'atan']:
            # menghitung radians, fungsi trigonometri dan logaritma, akar, dan eksponensial dengan nilai di entry dan menampilkan hasil
            try:
                if tombol == 'rad':
                    hasil = str(math.radians(float(self.entry.get())))
                if tombol == '\u221a':
                    hasil = str(math.sqrt(float(self.entry.get())))
                if tombol == 'exp':
                    hasil = str(math.exp(float(self.entry.get())))
                if tombol == 'sin':
                    hasil = str(math.sin(float(self.entry.get())))
                if tombol == 'cos':
                    hasil = str(math.cos(float(self.entry.get())))
                if tombol == 'tan':
                    hasil = str(math.tan(float(self.entry.get())))
                if tombol == 'ln':
                    hasil = str(math.log(float(self.entry.get())))
                if tombol == 'acos':
                    hasil = str(math.acos(float(self.entry.get())))
                if tombol == 'atan':
                    hasil = str(math.atan(float(self.entry.get())))
                if tombol == 'asin':
                    hasil = str(math.asin(float(self.entry.get())))
                self.entry.delete(0,END)
                self.entry.insert(END,hasil)
                self.expr = ''
                self.startOfNextOperand = True
            except:
                self.entry.delete(0,END)
                self.entry.insert(END,'Error')
                self.startOfNextOperand = True

        elif tombol == '\u00b1':
            # mengubah entry dari positif ke negatif dan sebaliknya, jika tidak ada value, maka tidak melakukan apa apa
            try:
                if self.entry.get()[0] == '-':
                    self.entry.delete(0)
                else:
                    self.entry.insert(0, '-')
            except IndexError:
                pass

        elif tombol == '\u03c0':
            # memunculkan nilai pi
            self.entry.delete(0, END)
            self.entry.insert(END,math.pi)
            self.startOfNextOperand = True
                  
        elif tombol == '~':
            # mengubah nilai entry menjadi 1's complement
            try:
                hasil = eval('~' + (self.entry.get()))
                self.entry.delete(0, END)
                self.entry.insert(END, hasil)
                self.expr = ''
                self.startOfNextOperand = True
            except:
                self.entry.delete(0, END)
                self.entry.insert(END, 'Error')
                self.startOfNextOperand = True
        
        elif tombol == '2C':
            # mengubah nilai di entry menjadi bentuk 32-bit biner, mengubah menjadi two's complement dari biner tersebut
            try:
                # mengubah menjadi two's complement
                temp = eval(self.entry.get())
                if temp > 0:
                    hasil = bin(temp)[2:]
                    hasil = "0b" + hasil.zfill(32)
                else:
                    hasil = bin(temp + 4294967296)
                self.entry.delete(0, END)
                self.entry.insert(END, hasil)
                self.expr = ''
                self.startOfNextOperand = True
            except:
                self.entry.delete(0, END)
                self.entry.insert(END, 'Error')
                self.startOfNextOperand = True

        elif tombol in ['int', 'bin', 'oct', 'hex']:
            # mengubah nilai di entry menjadi bilangan berbasis yang dipilih
            try:
                # mengubah ke desimal atau bilagan berbasis 10
                temp = eval(self.entry.get())
                # mengubah ke bilangan berbasis yang dipilih
                if tombol == 'int':
                    hasil = str(int(temp))
                elif tombol == 'bin':
                    hasil = bin(temp)
                elif tombol == 'oct':
                    hasil = oct(temp)
                elif tombol == 'hex':
                    hasil = hex(temp)
                
                self.entry.delete(0,END)
                self.entry.insert(END, hasil)
                self.expr = ''
                self.startOfNextOperand = True
            except:
                self.entry.delete(0, END)
                self.entry.insert(END, 'Error')
                self.startOfNextOperand = True
            
        elif tombol in ['→IEEE', '←IEEE']:  
            # mengubah nilai entry ke IEEE-754 dan sebaliknya
            try:
                temp = self.entry.get()
                hasil=''
                if tombol == '→IEEE':
                    temp = eval(self.entry.get())
                    hasil = hex(struct.unpack('Q',struct.pack('d',temp))[0])
                else :
                    hasil = struct.unpack('d',struct.pack('Q',int(self.entry.get(),16)))[0]
                self.entry.delete(0, END)
                self.entry.insert(END, hasil)
                self.expr = ''
                self.startOfNextOperand = True
            except:
                self.entry.delete(0, END)
                self.entry.insert(END, 'Error')
                self.startOfNextOperand = True

Supercalculator()