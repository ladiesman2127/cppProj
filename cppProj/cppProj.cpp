#include <iostream>
#include <cmath>
#include <vector>


class Point
{
	//Fields
	int x = 0;
	int y = 0;
	int Size;
	int *data;

public:
	//Contructors
	Point(int Size) : Size(Size), data(new int[Size])
	{
		std::cout << "Конструктор " << this << '\n';
		std::cout << data << '\n';
		for (int i = 0; i < this->Size;i++)
		{
			data[i] = i;
		}
	}
	//Copy constructor
	Point(const Point& other_point) : Size(other_point.Size), data(new int[Size])
	{
		std::cout << "Конструктор копирования " << this << '\n';
		std::cout << data << '\n';
		for (int i = 0; i < Size;i++)
		{
			this->data[i] = other_point.data[i];
		}
	}

	//Destructor
	~Point()
	{
		delete[] data;
		std::cout << "Деструктор " << this << '\n';
	}
	
	//Methods
	static void Print()
	{
		std::cout << "Print()\n";
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


};

int main()
{
	setlocale(LC_ALL, "ru");
	Point a(5);
	Point b(a);
	return 0;
}