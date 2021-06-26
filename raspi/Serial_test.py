import os
from time import sleep
from serial import Serial
import json

def senddata():
    port = '/dev/ttyUSB0'
    allport = os.popen('ls /dev/ttyUSB*').read()
    for p in allport.split('\n'):
        if 'ttyUSB_DEVICE1' not in p:
            port = p
            break

    ser = Serial(
            port=port,
            baudrate = 9600,
            timeout = 5
        )

    sleep(2)

    while True:
        send = str(input("type : ")) + '\n'
        
        ser.write(send.encode())
        
        output = ser.readline().decode().rstrip()
        print("output :",output)
        #j = json.loads(output.replace("'",'"'))
        #print("json :",j)
        #print("value :",j['ultra0'])

senddata()
'''     
try:
    senddata()
except:
    senddata()
'''