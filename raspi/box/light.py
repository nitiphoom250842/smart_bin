import RPi.GPIO as GPIO
import time
 
GPIO.setmode(GPIO.BCM)
 
GPIO_TRIGGER = 13
 
GPIO.setup(GPIO_TRIGGER, GPIO.OUT)
GPIO.output(GPIO_TRIGGER, False)