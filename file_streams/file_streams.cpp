#include <fstream>
#include <iostream>


class point
{


private:
	int x, y, z;

public:
	point(int x, int y, int z) : x(x), y(y), z(z)
	{
	}
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

int main()
{
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
	std::fstream fs;
	fs.exceptions(std::fstream::badbit | std::fstream::failbit);

	try
	{
		fs.open("file.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	}
	catch (const std::exception& ex)
	{
		std::cout << "FF!\n";
	}

	fs.close();


	return 0;
}
