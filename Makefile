all: car

car: car.cpp nwardinsky.cpp
	g++ car.cpp nwardinsky.cpp -Wall -lX11 -lGL -lGLU -lm ./libggfonts.a -ocar

clean:
	rm -f car
	rm -f *.o

