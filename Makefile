#Makefile for main.cpp,Book.cpp, Student.cpp 

#Since miniStack, Queue, List are templates, they compile/call themselves

#Rule for making main
main: main.o Book.o Student.o
	g++ main.o Book.o Student.o -o main

#Rule for making main.o
main.o: main.cpp
	g++ -c main.cpp

#Rule for making Student.o
Student.o: Student.cpp Student.h Book.h
	g++ -c Student.cpp

#Rule for making Book.o
Book.o: Book.cpp Book.h
	g++ -c Book.cpp

#Clean up
clean: rm main.o Book.o Student.o
