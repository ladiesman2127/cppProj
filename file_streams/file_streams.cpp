#include <fstream>
#include <iostream>
#include <xlocmon>


class point
{


private:
	int x, y, z;

public:
	point(int x, int y, int z) : x(x), y(y), z(z)
	{ }
	point()
	{
		x = y = z = 0;
	}

	friend std::ostream& operator << (std::ostream& os, const point& p);
	friend  std::istream& operator >> (std::istream& is, point& p);
};

std::ostream& operator << (std::ostream& os, const point& p)
{
	os << p.x << " " << p.y << " " << p.z << '\n';
	return os;
}

std::istream& operator >> (std::istream& is, point& p)
{

	is >> p.x >> p.y >> p.z;

	return is;
}


class my_exception : public std::exception
{
public:
	my_exception(const char* msg,const int data_state) :exception(msg)
	{
		this->data_state_ = data_state;
	}

	int get_data_state()
	{
		return data_state_;
	}
private:
	int data_state_;
};


int foo(const int& x)
{
	if(x < 0)
		throw my_exception("Число меньше 0!",x);
	if(x == 1)
		throw my_exception("Число равно 1!",x);
	std::cout << x << '\n';
}
int main()
{
#pragma region ...
	/*std::ifstream fin;
	fin.open("file.txt");
	std::string str;
	while (!fin.eof())
	{
		std::getline(fin, str);
		std::cout << str << '\n';
	}
	fin.close();*/
	/*std::ofstream fout;

	point a(12321,5435,777);
	fout.open("file.txt");
	fout.write((char*)&a,sizeof(a));
	fout.close();*/
	/*std::fstream fs;
	fs.exceptions(std::fstream::badbit | std::fstream::failbit);

	try
	{
		fs.open("file.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	}
	catch (const std::exception& ex)
	{
		std::cout << "FF!\n";
	}

	fs.close();*/
#pragma endregion
	int a;
	std::cin >> a;
	try
	{
		foo(a);
	}
	catch(my_exception& ex)
	{

		std::cout << ex.what() << '\n';
	}
	return 0;
}
