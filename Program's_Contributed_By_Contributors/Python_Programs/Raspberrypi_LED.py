#Created by Akshar Singh
#IMPORTANT - CAN ONLY WORK ON RASPBERRY PI OPERATING SYSTEM
import RPi.GPIO as GPIO
from time import sleep

#GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD) #use phyical pin numbering
 
c = 0
#Light on
def lighton():
 GPIO.setup(8,GPIO.OUT,initial=GPIO.LOW)#spicifies the pin number to be the output pin
#initial value is low(OFF)
 c=c+1
 while True:
    GPIO.output(8,GPIO.HIGH)

#Light off
def lightoff():
 if(c==1):
    GPIO.output(8,GPIO.LOW)
  
#Blinking
def lightblink():
 GPIO.setup(8,GPIO.OUT,initial=GPIO.LOW)
 while True: #running forever
    GPIO.output(8,GPIO.HIGH) #Turn on 
    sleep(1) 
    GPIO.output(8,GPIO.LOW) #Turn off
    sleep(1)
    #light is on for 1 sec and then gets off for 1 second

#Control Brightness
def brightness():
#GPIO.PWM(PIN NUMBER,MAX BRIGHTNESS)
 GPIO.setup(8,GPIO.OUT,initial=GPIO.HIGH)
 P = GPIO.PWM(8,100) #PWM - Pulse width modulation(reducing avg power delivered by an electrical signal)
 P.start(0) #LED starts with 0 % brightness

 while True:
    #LED's brightness is increasing gradually
    for i in range(100):
        P.start(i)
        sleep(0.5)
    #LED's brightness is decreasing gradually
    for i in range(100):
        P.start(100-i)
        sleep(0.5)
