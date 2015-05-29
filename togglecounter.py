import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)

last = 0
c = 0
act = 1
while True:
	while c < 10000:
		act = GPIO.input(23)
		if(act <> last):
			print(last)
			print(act)
			c=c+1
			last = act
	print("Got 10000")
	
