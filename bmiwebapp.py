from symbol import parameters
import pywebio
from pywebio.input import input, FLOAT
from pywebio.output import *

def bmi():
    height = input("Input your height(cm)：", type=FLOAT)
    weight = input("Input your weight(kg)：", type=FLOAT)

    BMI = weight / (height / 100) ** 2

    parameters = [(16, 'Severely underweight'), (18.5, 'Underweight'),
                  (25, 'Normal'), (30, 'Overweight'),
                  (35, 'Moderately obese'), (float('inf'), 'Severely obese')]

    for top, status in parameters:
        if BMI <= top:
            put_markdown("Results")
            put_html("<hr>")
            put_text('Your BMI: %.1f. Category: %s' % (BMI, status))
            put_html("<br><br>")
            put_table((["Your BMI","Status"],[BMI,status]))
            break

if __name__ == '__main__':
    bmi()