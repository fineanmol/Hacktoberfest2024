from tkinter import *
from tkinter import ttk

root=Tk()
root.title("BMI Calculator")
root.geometry("668x400")

#label to display the BMI Value
ans=ttk.Label(root, text="")
ans.grid(row=5,column=1)

#label to display the status if healthy or overweight
label2= ttk.Label(root, text="")
label2.grid(row=6, column=1)

#label to display error message
label=ttk.Label(root,text="")
label.grid(row = 4, column=1)

#Function to check if the entry is float or not
def isfloat(x):
    try:
        float(x)
        return True
    except:
        return False

#Enter Weight:
ttk.Label(root, text="Enter Your Weight").grid(row=0, column=0, padx=20)
weight=ttk.Entry(root, width=45)
weight.grid(row = 0, column = 1, padx=30, pady = 20)
weight_options=["Select a Unit","Weight in Kilograms (kg)","Weight in Pounds (lb)"]
weight_value=StringVar(root)
ttk.OptionMenu(root, weight_value, *weight_options).grid(row=0, column=2)
def enter_wt():
    wtg=weight.get()
    if(weight_value.get()==weight_options[1]):
        label.config(text="")
        if isfloat(wtg):
            ret = float(weight.get())
            return ret
        else:
            weight.delete(0,END)
            weight.insert(0,"SNYTAX ERROR")
    elif(weight_value.get()==weight_options[2]):
        label.config(text="")
        if isfloat(wtg):
            ret = float(weight.get())*0.453592
            return ret
        else:
            weight.delete(0,END)
            weight.insert(0,"SNYTAX ERROR")
    else:
        label.config(text="Please select a valid unit for weight")

#Enter Height:
ttk.Label(root, text="Enter Your Height").grid(row=1, column=0)
height=ttk.Entry(root, width=45)
height.grid(row=1, column=1, padx=30, pady=20)
height_options=["Select a Unit","Height in Metres (m)","Height in Feet (ft)", "Height in Centimetres (cms)"]
height_value=StringVar(root)
ttk.OptionMenu(root, height_value, *height_options).grid(row=1, column=2)
def enter_ht():
    htg =height.get()
    if(height_value.get()==height_options[1]):
        if isfloat(htg):
            ret= float(height.get())
            return ret
        else:
            height.delete(0,END)
            height.insert(0,"SYNTAX ERROR")
    elif(height_value.get()==height_options[2]):
        if isfloat(htg):
            ret= float(height.get())*0.3048
            return ret
        else:
            height.delete(0,END)
            height.insert(0,"SYNTAX ERROR")
    elif(height_value.get()==height_options[3]):
        if isfloat(htg):
            ret= float(height.get())/100
            return ret
        else:
            height.delete(0,END)
            height.insert(0,"SYNTAX ERROR")
    else:
        label.config(text="Please select a valid unit for height")

#Function to calculate BMI
def fun():
    wt=enter_wt()
    ht=enter_ht()
    bmi=None
    try:
        bmi= float(wt)/(float(ht)*float(ht))
        ans.config(text = "The BMI is: " + str(bmi))
        if( int(wt) > 0 and round(ht) > 0):
            if( bmi <= 16 ):
                label2.config(text="You are severely underweight")
            elif( round(bmi) <= 17 ):
                label2.config(text="You are moderately underweight")
            elif( round(bmi) <= 18.5 ):
                label2.config(text="You are mildly underweight")
            elif ( round(bmi) <= 25 ):
                label2.config(text="You are healthy")
            elif ( round(bmi) <= 30 ):
                label2.config(text="You are overweight")
            elif ( round(bmi) <= 35 ):
                label2.config(text="You belong to obesity class I")
            elif ( round(bmi) <= 40 ):
                label2.config(text="You belong to obesity class II")
            else:
                label2.config(text="You belong to obesity class III")
        else:
            ans.config(text="")
            label2.config(text="Enter valid details")
    except:
        ans.config(text="")
        label2.config(text="")
        pass  

button =ttk.Button(root, text='''    
    Calculate BMI    
                    ''', command=fun)
button.grid(row=3, column=1)

root.mainloop()