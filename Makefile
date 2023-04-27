main: main.o profile.o network.o
	g++ -o main -std=c++11 main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -o tests -std=c++11 tests.o profile.o network.o


profile.o: profile.cpp profile.h

network.o: network.cpp network.h

main.o: main.cpp profile.h network.h

tests.o: tests.cpp doctest.h profile.h network.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main.o profile.o network.o tests.o