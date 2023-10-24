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
    if (began) {
    auto stop = steady_clock::now();
   
    time = ((duration_cast<milliseconds>(stop - start).count()) / 1000);
    began = false;   
    return time;
    }
    return 0;
}


int total_running_time(const bool get)
{
    static int firsttime = 1;
    static int start_time;
    if (firsttime) {
        start_time = time(NULL);
        firsttime = 0;
    }
    if (get) {
        return time(NULL) - start_time;
    }
    return 0;
}

int total_render_function_calls(const bool get)
{
    static int firsttime = 1;
    
    
