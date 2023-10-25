all: car

car: car.cpp nwardinsky.cpp  mabadi.cpp dayeni.cpp
	g++ car.cpp nwardinsky.cpp mabadi.cpp dayeni.cpp -Wall -lX11 -lGL -lGLU -lm ./libggfonts.a -ocar

clean:
	rm -f car
	rm -f *.o
