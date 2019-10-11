CXX = g++
DEPINHERITANCE = person.o student.o testInheritance.o
DEPABSTRACT = rectangle.cpp square.cpp testAbstract.o

all: testInheritance testAbstract

testInheritance: ${DEPINHERITANCE}
	${CXX} -std=c++11 $^ -o $@

testAbstract: ${DEPABSTRACT}
	${CXX} -std=c++11 $^ -o $@

clean:
	rm *.o
	rm ./testInheritance
	rm ./testAbstract



