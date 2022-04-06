#include <fstream>
#include <iostream>

int main()
{
	std::ofstream fout;
	fout.open("file.txt", std::ofstream::app);
	fout << "GG!   asdasd asd ";
	fout.close();

	return 0;
}