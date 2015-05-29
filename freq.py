import RPi.GPIO as GPIO
import sys

pin = 23
GPIO.setmode(GPIO.BCM)
GPIO.setup(pin, GPIO.IN, pull_up_down = GPIO.PUD_UP)
last = 0
act = 1
ch = 0
cl = 0
while True:	
	act = GPIO.input(pin)
	if(act == last):
		if(act == 1):
			ch = ch+1
		else:
			cl = cl+1	
	else:	
		last = act
		if(act == 0):
			print 'Rate high/low: %s / %s \n' % (ch, cl)
			ch = cl = 0
