#include <thread>
#include <iostream>
#include <mutex>

#include "timer.h"

class my_class
{
public:
	void doWork()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << std::this_thread::get_id() << "\tdoWork\n";
	}
	int doWork1(int a)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << std::this_thread::get_id() << "\tdoWork(a)\n";
		return a;
	}
	int doWork2(int a,int b)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << std::this_thread::get_id() << "\tdoWork(a,b)\n";
		return a + b;
	}
};

int sum(int& a, int& b)
{
	/*for (size_t i = 0; i < 10; ++i)
	{
		std::cout << std::this_thread::get_id() << " " << i << "\tvoid\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}*/

	std::this_thread::sleep_for(std::chrono::microseconds(3000));
	return a + b;

}

std::mutex mtx;

void print(char ch)
{
	//emulation of work
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	{
		std::lock_guard<std::mutex> guard(mtx);
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				std::cout << ch;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
}
void print(int a)
{
	std::this_thread::sleep_for(std::chrono::hours(1));
}

int main()
{
	timer t;
	std::recursive_mutex rm;
	//atan2(3.2, 8.9);
	//print('*');
	//print(2);
	//std::thread th1(&print, '*');
	//std::thread th2(&print, '#');
	/*my_class m;
	int res;
	std::thread th(&my_class::doWork2, &m, 3, 5);
	for(int i = 0;i < 10;++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << std::this_thread::get_id << "\tmain\n";
	}
	th.join();*/
	//th1.join();
	//th2.join();
	return 0;

}
