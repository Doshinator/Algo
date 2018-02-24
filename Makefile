CC = g++
CFLAG = -c -std=c++11
OBJ = main.o


main: $(OBJ)
	$(CC) $(OBJ) -o main
main.o: master_method.cpp
	$(CC) master_method.cpp $(CFLAG) -o main.o
clean:
	rm *.o main