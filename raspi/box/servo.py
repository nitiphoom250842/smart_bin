import RPi.GPIO as GPIO
import time

servoPIN = 26
GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPIN, GPIO.OUT)

p = GPIO.PWM(servoPIN, 50) # GPIO 17 for PWM with 50Hz
p.start(8.0) # Initialization
time.sleep(1)
p.ChangeDutyCycle(3.5)
time.sleep(1)
p.ChangeDutyCycle(8.0)
time.sleep(1)
p.stop()