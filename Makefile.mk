CXXFLAGS = -g -Wall -Wextra -std=c++11
CXX = g++

#executable
project=main

all: ${project}

#linking
${project} : UptimeCpp/UptimeCpp.o UptimeCpp/TimeConverter.o
	${CXX} $^ -o ${project}

#compile object files
TimeConverters.o : UptimeCpp/TimeConverter.h
UptimeCpp.o : UptimeCpp/UptimeCpp.cpp UptimeCpp/TimeConverter.h
TimeConverter.o : UptimeCpp/TimeConverter.cpp

clean:
	rm -f *~ *.o ${project}