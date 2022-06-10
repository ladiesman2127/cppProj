#include <iostream>
#include <functional>
#include <vector>

//std::string dataFromBd()
//{
//	return "dataFromBd";
//}
//std::string dataFromServer()
//{
//	return "dataFromServer";
//}
//
//void print(const std::vector<std::function<std::string()>> foo)
//{
//	for(auto &el : foo)
//	std::cout << el();
//}
void doWork(std::vector<int>& v,std::function<void(int)> f)
{
	for(auto element : v)
	{
		f(element);
	}
}

int main()
{
	//std::vector<std::function<std::string()>> func;
	//func.emplace_back(dataFromBd);
	//func.emplace_back(dataFromServer);
	//print(func);
	std::vector<int> v         = { 1,3,5,6,-1,6,72 };
	std::function<void(int)> f = [](int a)
	{
		std::cout << "Lamba function: " << a << '\n';
	};
	std::vector<int> vc;
	auto fl = [&vc]()
	{
		for (int i = 0; i < 20; ++i)
		{
			vc.push_back(i);
		}
	};
	fl();
	doWork(v, f);
}