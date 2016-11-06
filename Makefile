#	Author: John Gibbons
#	Date: 2016.10.26


#Add needed Test.o
prog: main.o LinkedListOfInts.o TestSuite.o
	g++ -g -Wall -std=c++11 main.o LinkedListOfInts.o TestSuite.o -o prog


main.o: main.cpp 
	g++ -g -Wall -std=c++11 -c main.cpp

TestSuite.o: TestSuite.cpp TestSuite.h
	g++ -g -Wall -std=c++11 -c TestSuite.cpp

#DON'T delete LinkedList.o!
clean:
	rm main.o TestSuite.o prog
