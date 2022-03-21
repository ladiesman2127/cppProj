#include <iostream>
#include <cmath>
#include <vector>

class Point
{
	//Fields
	int x = 0;
	int y = 0;
public:

	//Constructor
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
		std::cout << "Конструктор\t" << this << '\n';
	}

	Point(Point& other_point)
	{
		this->x = other_point.x;
		this->y = other_point.y;
		std::cout << "Конструктор копирования\t" << this << '\n';
	}
	~Point()
	{
		std::cout << "Деструктор\t" << this << '\n';
	}
	//Operators
	bool operator == (const Point& other_point)
	{
		std::cout << "==\t\n";
		return this->x == other_point.x && this->y == other_point.y;

	}

	bool operator != (const Point& other_point)
	{
		std::cout << "!=\t\n";
		return this->x != other_point.x || this->y != other_point.y;
	}

	Point& operator + (const Point& other_point)
	{
		std::cout << "+\t" << this << '\n';
		this->x += other_point.x;
		this->y += other_point.y;
		return *this;
	}

	Point& operator ++()
	{
		std::cout << "prefix++\t" << this << '\n';
		this->x++;
		this->y++;
		return *this;
	}
	Point& operator ++(int value)
	{
		std::cout << "postfix+++\t" << this << '\n';
		Point temp(*this);
		this->x++;
		this->y++;
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
class testClass
{
	int ar[]{1,872,9,22,4};

};

int main()
{
	setlocale(LC_ALL, "ru");
	//myClass a(5);
	//myClass b(6);
	//a = b;


	//int ball_x = 3, ball_y = 9;
	////int goal_x = 3, goal_y = 9;
	////int f_x = 5, f_y = 6;
	//Point ball(ball_x, ball_y);
	////Point goal(goal_x, goal_y);
	////Point f(f_x, f_y);
	////bool result = ball == goal;
	////bool result2 = ball != goal;
	////std::cout << result << '\n';
	////std::cout << result2 << '\n';

	////Point sum = ball + goal + f;
	////std::cout << sum.GetX() << " " << sum.GetY() << '\n';
	// ball++;
	// ++ball;
	 return 0;
}