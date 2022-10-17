# makefile for PasswordManager class with three files:
# PasswordManager.h, PasswordManager.cpp, PasswordDriver.cpp
# Try "-std=gnu++0x" or "-std=c++11"

all: PasswordDriver.o PasswordManager.o
	g++ PasswordDriver.o PasswordManager.o

PasswordDriver.o: PasswordDriver.cpp PasswordManager.h
	g++ -c -std=c++11 PasswordDriver.cpp

PasswordManager.o: PasswordManager.cpp PasswordManager.h
	g++ -c -std=c++11 PasswordManager.cpp

clean: 
	rm a.out

