//Program: Jerry the Race Car Driver
//Author: Nathan Wardinsky
//Date started: 9/25/2023
#include"nwardinsky.h"

using namespace std::chrono;

/*
int main() {
 
    int num;
    std::cout << "First call of timer()\n";
    timer();
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << "Second call of timer()\n";
    timer();

    return 0;
}
*/
void timer() {

    static bool began = false;
    static auto start = steady_clock::now();

    if (!began) {
    //start timing
    start = steady_clock::now();
    began = true;
    }

    // stop timing
    else {
    auto stop = steady_clock::now();
    
    // stop - start will give you the time that passed
    std::cout << "It took " 
              << (duration_cast<milliseconds>(stop - start).count()) / 1000
              << " seconds!\n";

    std::cin.get();
    began = false;   
    }
}

