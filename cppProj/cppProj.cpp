﻿#include <iostream>
#include <cmath>
#include <vector>

class Point
{
	//Fields
	int x = 0;
	int y = 0;
public:

	//Constructor
	Point(int& x, int& y) : x(x), y(y)
	{

	}

	//Operators
	bool operator == (const Point& other_point)
	{
		return this->x == other_point.x && this->y == other_point.y;
	}

	bool operator != (const Point& other_point)
	{
		return this->x != other_point.x || this->y != other_point.y;
	}
	//Getters and Setters
	int GetX()
	{
		return x;
	}
	void SetX(int x)
	{
		this->x = x;
	}
	int GetY()
	{
		return y;
	}
	void SetY(int y)
	{
		this->y = y;
	}
		//Methods
	static void Print()
	{
		std::cout << "Print()\n";
	}

};
class myClass
{
	//Fields
	int Size;
	int* data;

public:
	//Contructors
	myClass(int Size) : Size(Size), data(new int[Size])
	{
		std::cout << "Конструктор " << this << '\n';
		std::cout << data << '\n';
		for (int i = 0; i < this->Size; i++)
		{
			data[i] = i;
		}
	}
	//Copy constructor
	myClass(const myClass& other_myClass) : Size(other_myClass.Size), data(new int[Size])
	{
		std::cout << "Конструктор копирования " << this << '\n';
		std::cout << data << '\n';
		for (int i = 0; i < Size; i++)
		{
			this->data[i] = other_myClass.data[i];
		}
	}

	//Operator =
	myClass& operator = (const myClass& other_myClass)
	{
		this->Size = other_myClass.Size;
		this->data = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			this->data[i] = other_myClass.data[i];
		}
		return *this;
	}

	//Destructor
	~myClass()
	{
		delete[] data;
		std::cout << "Деструктор " << this << '\n';
	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	myClass a(5);
	myClass b(6);
	a = b;
	int Ball_x = 3, Ball_y = 9;
	int goal_x = 3, goal_y = 9;
	Point Ball(Ball_x, Ball_y);
	Point goal(goal_x, goal_y);
	bool result =  Ball == goal;
	bool result2 = Ball != goal;
	std::cout << result << '\n';
	std::cout << result2 << '\n';
	return 0;
}