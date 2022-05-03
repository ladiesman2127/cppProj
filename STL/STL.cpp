#include <algorithm>
#include <list>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> my_vector { 1,-1,0,72,144,3 };
	auto it = my_vector.begin();
	//my_vector.push_back(2);
	//std::cout << my_vector.capacity() << '\n';
	//std::cout << my_vector.size();
	std::sort(my_vector.begin(), my_vector.end());
	std::advance(it, 6);

	my_vector.insert(it, 72);
	const auto it_erase = my_vector.cbegin();
	my_vector.erase(it_erase);
	for(auto i = my_vector.begin(); i != my_vector.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::list<int>int_list;
	int_list.push_back(2);
	int_list.push_back(5);
	int_list.push_back(-1);
	auto i = int_list.begin();
	std::advance(i,1);
	std::cout << *i;

}
