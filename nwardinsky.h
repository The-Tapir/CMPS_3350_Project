//Only definitions or prototypes
//No executables
#ifndef _nwardinsky_H_
#define _nwardinsky_H_

#include <iostream>
#include <chrono>
#include <typeinfo>
#include <string>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
//#include <openal-soft/AL/alc.h>

int timer();
int total_running_time(bool);
int total_render_function_calls(bool);
int total_physics_function_calls(bool);
int key_presses(bool);
float car_acceleration(bool);
float car_slow_down();
void cleanupAL();
void PlaySound(const char* SoundFile);
#endif
