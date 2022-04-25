#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>
#include <iostream>

std::size_t duplicateCount(const char* in)
{
	std::unordered_map<char, unsigned> counts;
	for(const char* c = in; *c != '\0'; ++c)
	{
		++counts[tolower(*c)];
	}
	return std::count_if(cbegin(counts), cend(counts), [](const auto& count)
						 {
							 return count.second > 1;
						 });
}



int main()
{
	std::string inp;
	std::cin >> inp;
	char* str = new char[std::size(inp)];
	for(size_t i = 0; i < std::size(inp); i++)
	{
		*(str + i) = inp[i];
	}
	std::cout << duplicateCount(str);
	return 0;
}