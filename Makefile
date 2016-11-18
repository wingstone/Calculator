CPP = g++
CC  = gcc
RM  = rm -rf

Objects = Linear_Stack.o main.o

Stack : $(Objects)
	$(CPP) -o Stack.exe $(Objects)
Linear_Stack.o : Linear_Stack.cpp
	$(CPP) -c Linear_Stack.cpp
main.o : main.cpp
	$(CPP) -c main.cpp

PHONY : clean
clean :
	rm $(Objects)
