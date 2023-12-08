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
    static int count = 0;

    if (get) {
        return count;
    }

    count += 1;

    return 0;
} 
    
int total_physics_function_calls(const bool get)
{
    static int count = 0;

    if (get) {
        return count;
    }

    count += 1;

    return 0;
}

int key_presses(const bool get) {
	static int count = 0;

	if (get) {
		return count;
	}

	count += 1;
	
	return 0;
}

float car_acceleration(bool gas) {

	static float velocity = 0.0;

	if (velocity < 0) {
		velocity = 0;
	}

	if (gas) {
		velocity += .05;
	}

	else {
		if (velocity > 0) {
			velocity -= .01;
		}

	}
	return velocity;
}

float car_slow_down() {

	float velocity = 0.0;

	velocity -= .03;

	return velocity;
}

void PlaySound(const char* AudioFile) {
	ALuint buffer, source;

	buffer = alutCreateBufferFromFile(AudioFile);
	alGenSources(1,&source);
	alSourcef(source, AL_GAIN, 0.05f);
	alSourcei(source, AL_BUFFER, buffer);
	alSourcePlay(source);
}

void cleanupAL() {
	ALCcontext *Context = alcGetCurrentContext();
	ALCdevice *Device = alcGetContextsDevice(Context);

	//ALCcontext Context = alcGetCurrentContext();
	//ALCdevice Device = alcGetContextsDevice(Context);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(Context);
	alcCloseDevice(Device);
}

