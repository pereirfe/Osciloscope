import RPi.GPIO as GPIO
import sys
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)
last = 0
act = 1
while True:
	sys.stdout.flush()	
	act = GPIO.input(23)
	if(act == 1):
		sys.stdout.write('*')
		last = 1
	else:	
		sys.stdout.write('_')
		last = 0
