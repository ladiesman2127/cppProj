﻿#include <iostream>
#include <cmath>
#include <functional>
#include <vector>


class Apple;

class point
{
	//Fields
	int x = 0;
	int y = 0;
public:

	//Constructor
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
		std::cout << "Конструктор\t" << this << '\n';
	}

	point(point& other_point)
	{
		this->x = other_point.x;
		this->y = other_point.y;
		std::cout << "Конструктор копирования\t" << this << '\n';
	}
	~point()
	{
		std::cout << "Деструктор\t" << this << '\n';
	}
	//Operators
	bool operator == (const point& other_point)
	{
		std::cout << "==\t\n";
		return this->x == other_point.x && this->y == other_point.y;

	}

	bool operator != (const point& other_point)
	{
		std::cout << "!=\t\n";
		return this->x != other_point.x || this->y != other_point.y;
	}

	point& operator + (const point& other_point)
	{
		std::cout << "+\t" << this << '\n';
		this->x += other_point.x;
		this->y += other_point.y;
		return *this;
	}

	point& operator ++()
	{
		std::cout << "prefix++\t" << this << '\n';
		this->x++;
		this->y++;
		return *this;
	}
	point& operator ++(int value)
	{
		std::cout << "postfix+++\t" << this << '\n';
		point temp(*this);
		this->x++;
		this->y++;
		return temp;
	}

	point& operator --(int val)
	{
		point temp(*this);
		this->x--;
		this->y--;
		return temp;
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
	void Print()
	{
		std::cout << "Print()\n" << this->x << this->y;
	}

	friend void change_x(point& val);

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

class test_class
{
	int ar[5]{ 1,872,9,22,4 };
public:
	int& operator[](const int& index)
	{
		return ar[index];
	}

};

class my_class
{
public:
	my_class();

	~my_class() = default;

	static void print_msg();
};

my_class::my_class()
= default;

void my_class::print_msg()
{
	std::cout << "GG\n";
}

void change_x(point & val)
{
	val.x = -1;
	val.y = -1;
}


class human
{
public:
	static void takeApple(Apple& a);
};


class Apple
{
	int weight;
	std::string color;
	friend human;
public:
	Apple(const int& weight, std::string color) : weight(weight), color(std::move(color)){}
	int GetWeight()
	{
		return weight;
	}
	std::string get_color()
	{
		return  color;
	}
};


void human::takeApple(Apple & a)
{
	a.color = "white";
	a.weight /= 2;

}

int main()
{
	setlocale(LC_ALL, "ru");
	/*myClass a(5);
	myClass b(6);
	a = b;*/


	/*int ball_x = 3, ball_y = 9;
	int goal_x = 3, goal_y = 9;
	int f_x = 5, f_y = 6;
	Point ball(ball_x, ball_y);
	Point goal(goal_x, goal_y);
	Point f(f_x, f_y);
	bool result = ball == goal;
	bool result2 = ball != goal;
	std::cout << result << '\n';
	std::cout << result2 << '\n';

	Point sum = ball + goal + f;
	std::cout << sum.GetX() << " " << sum.GetY() << '\n';
	ball++;
	++ball;*/

	//Point a(2,3);
	//changeX(a);
	//a.Print();

	/*my_class obj;
	obj.print_msg();*/
	Apple apl1(120,"red");
	human human;
	human.takeApple(apl1);
	std::cout << apl1.GetWeight() << " " << apl1.get_color() << '\n';
	return 0;

}