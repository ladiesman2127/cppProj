#include <iostream>
#include <cmath>
#include <string>
#include <functional>
#include <vector>

#pragma region classes
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
	static unsigned int count;
	Apple(const int& weight, std::string color) : weight(weight), color(std::move(color))
	{
	}
	int GetWeight()
	{
		return weight;
	}
	std::string get_color()
	{
		return  color;
	}
	static void ChangeColor(Apple& apl, std::string color)
	{
		apl.color = color;
	}
};
unsigned int Apple::count = 2;


void human::takeApple(Apple & a)
{
	a.color = "white";
	a.weight /= 2;

}

class Person
{
private:
	unsigned int PersonID;
	static unsigned int ID;
public:
	Person()
	{
		PersonID = ID;
		ID++;
	}
	unsigned int GetID()
	{
		return PersonID;
	}
	static unsigned int GetCount()
	{
		return ID;
	}

};
unsigned int Person::ID = 0;

class Pixel
{
private:
	int r_, g_, b_;
public:
	Pixel()
	{
		r_ = b_ = g_ = 0;
	}
	Pixel(const int r, const int g, const int b) : r_(r), g_(g), b_(b) {}
	std::string info()
	{
		return "Pixel: r = " + std::to_string(r_) + " " + "Pixel: g = " + std::to_string(g_) + " " + "Pixel: b = " + std::to_string(b_);
	}
};
class Image
{
private:
	static constexpr unsigned int length = 5;
	Pixel arr_[length]{};
public:
	void get_pixel_info()
	{
		for (auto& i : arr_)
		{
			std::cout << i.info();
			std::cout << '\n';
		}
	}
};

#pragma endregionпше
class human1
{
public:
	void think()
	{
		brain.think();
	}
private:
	class brain
	{
	public:
		void think()
		{
			std::cout << "Thinking\n";
		}
	};
	brain brain;
};

int main()
{
	setlocale(LC_ALL, "ru");
	#pragma region Other
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
obj.print_msg();

Apple apl1(120,"red");
human human;
human.takeApple(apl1);
std::cout << apl1.GetWeight() << " " << apl1.get_color() << '\n';*/


//Person p1;
//Person p2;
//Person p3;
//std::cout << p1.GetID() << '\n'
//			<< p2.GetID() << '\n'
//			<< p3.GetID();
//std::cout << '\n' << Person::GetCount();
//int ap1_w = 12;
//std::string apl1_c = "red";
//Apple ap1(ap1_w,apl1_c);
//Apple ap2(ap1_w, apl1_c);
//ap1.ChangeColor(ap1, "white");
//std::cout << ap1.get_color() << " " << ap2.get_color();


	//Image img;
	//img.GetPixelInfo();


	//unsigned int length;
	//std::cin >> length;
	//Pixel* arr = new Pixel[length];
	//for (int i = 0; i < length; i++)
	//{
	//	std::cout << arr[i].info() << '\n';
	//}

#pragma endregion
	human1 human;
	human.think();
	return 0;

}