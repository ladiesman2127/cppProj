#include "timer.h"
#include <iostream>

timer::timer()
{
	start = std::chrono::high_resolution_clock::now();
}

timer::~timer()
{
	end = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<float> duration = end - start;
	std::cout << '\n' << duration.count();
}
