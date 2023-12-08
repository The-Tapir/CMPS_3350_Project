all: car

car: car.cpp nwardinsky.cpp  mabadi.cpp dayeni.cpp azurita.cpp
	g++ car.cpp nwardinsky.cpp mabadi.cpp dayeni.cpp azurita.cpp global.cpp -Wall -lX11 -lGL -lGLU -lopenal -lalut -lm ./libggfonts.a -ocar

clean:
	rm -f car
	rm -f *.o
