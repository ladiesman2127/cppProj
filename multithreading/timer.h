#pragma once
#ifndef  TIMER_H
#define  TIMER_H
#include <chrono>

class timer
{
public:
	timer();
	~timer();
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};
#endif


