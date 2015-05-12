
TARGET = shuffle
CPP = g++
CXXFLAGS  = -Wall -O3 -march=native -std=c++11

OBJ = main.o
LDFLAGS =

$TARGET: $(OBJ)
	$(CPP) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CPP) $(CXXFLAGS) -c $<

clean:
	rm -f main.o *.~ $(TARGET) *~

