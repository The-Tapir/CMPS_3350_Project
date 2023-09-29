//Program: Jerry the Race Car Driver
//Author: Nathan Wardinsky
//Date started: 9/25/2023
#include"nwardinsky.h"

using namespace std::chrono;

int timer() {

    static bool began = false;
    static auto start = steady_clock::now();
    int time;

    if (!began) {
    //start timing
    start = steady_clock::now();
    began = true;
    return 0;
    }

    // stop timing
    else {
    auto stop = steady_clock::now();
    
    // stop - start will give you the time that passed
    /* std::cout << "It took " 
              << (duration_cast<milliseconds>(stop - start).count()) / 1000
              << " seconds!\n";*/
	//ggprint8b(&r, 16, 0x00887766, "apples and oranges");
    //std::cin.get();
    time = ((duration_cast<milliseconds>(stop - start).count()) / 1000);
    //std::cout << "It took " << time << "  seconds!\n";
    began = false;   
    return time;
    }
}

