#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>


class point
{
private:
	int x, y, z;
public:
	point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	point()
	{
		x = y = z = 0;
	}

};

std::ostream &operator << (std::ostream &os, const point &p)
{

	return os;
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
	fs.open("file.txt", std::fstream::in | std::fstream::out | std::fstream::app);


		return 0;
}
