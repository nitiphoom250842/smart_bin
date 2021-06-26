'''
sudo apt-get update
sudo apt-get install build-essential python-dev
git clone https://github.com/adafruit/Adafruit_Python_DHT.git
cd Adafruit_Python_DHT
sudo python setup.py install
'''

import time
import Adafruit_DHT

sensor = Adaruit_DHT.DHT22
pin = 'GPIO1_19'

def getvalue():
  humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
  return humidity

while True:
    print(getvalue())