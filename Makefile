#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, calendar.o, time.o, and date.o to executable main
main: main.o time.o date.o calendar.o
	g++ -g -o main main.o time.o date.o calendar.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp

#compile the time.cpp to time.o
time.o: time.cpp
	g++ -g -c -std=c++11 time.cpp

#compile the date.cpp to date.o
date.o: date.cpp
	g++ -g -c -std=c++11 date.cpp

#compile the calendar.cpp to date.o
calendar.o: calendar.cpp
	g++ -g -c -std=c++11 calendar.cpp

#remove built files
clean:
	rm -rf main main.o time.o date.o calendar.o *~
