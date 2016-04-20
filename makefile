#main: main.cpp Soft.o event.o calender.o newSleepTimeChang.o#
#	g++ main.cpp Soft.o event.o calender.o newSleepTimeChang.o -o main

#Soft.o: Soft.cpp
#	g++ -c Soft.cpp -o Soft.o

#event.o: event.cpp
#	g++ -c event.cpp -o event.o

#calender.o: calender.cpp
#	g++ -c calender.cpp -o calender.o

#newSleepTimeChang.o: newSleepTimeChang.cpp
#	g++ -c newSleepTimeChang.cpp -o newSleepTimeChang.o






main: newSleepTimeChang.cpp event.cpp Soft.cpp calender.cpp main.cpp
	g++ newSleepTimeChang.cpp event.cpp Soft.cpp calender.cpp main.cpp -o main

clean:
	rm main
