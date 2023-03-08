
CXX = g++
CXXFLAGS = -Wall -g

driver: UTPodDriver.o UTPod.o Song.o
	$(CXX) $(CXXFLAGS) -o tests UTPodDriver.o UTPod.o Song.o
driver.o: UTPodDriver.cpp Song.h UTPod.h
	$(CXX) $(CXXFLAGS) -c UTPodDriver.cpp
Song.o: Song.h
UTPod.o: UTPod.h Song.h