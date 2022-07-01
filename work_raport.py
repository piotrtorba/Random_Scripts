#This simple program is to calculate and convert work time from clock format (1h = 60min)
# to decimal fromat (1h = 100*1.666min.)
#My employer demands monthly work raports in decimal format. OMG!

#Simply enter start time value and finish time value and the program will give you
#two results: 1st the raw result and 2nd the result minus breaktime (45min.)
#To 'Exit' the program type 'stop' and hit 'ENTER'.
print()
print("|-------------------------GAGA_COMPANY-----------------------|")
print("|---------------------WORKHOUR-CALCULATOR--------------------|")
print("|To calculate working hours enter start time and finish time.|")
print("|         !!!Each entry accept with 'ENTER' key!!!           |")
print()
run = True
while run:
	startH = int(input("Start hour: "))
	startM = float(input("Start minute: "))
	startM = (startM * 1.67)*0.01
	stopH = int(input("Finish hour: "))
	stopM = float(input("Finish minute: "))
	stopM = (stopM * 1.67)*0.01
	wynik = (stopH + stopM) - (startH + startM)
	wynikPause = wynik - 0.75
	print()
	print("Total work time: ", "%.2f"%wynik)
	print("Total work time minus break (45min): ", "%.2f"%wynikPause)
	print()
	exit = input("To quit the program type \'stop\', to continue hit \'ENTER\'...")
	print()
	if exit == ("stop"):
		print()
		print("Shutting down")
		run = False
