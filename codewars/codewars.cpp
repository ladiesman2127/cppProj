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

int last_digit(const std::string& str1, const std::string& str2)
{
	int first  = str1[str1.size() - 1] - '0';
	int second = str2[str2.size() - 1] - '0';
	int ans = first;
	int mult = first;
	for(int i = 1; i < second; i++)
	{
		ans *= mult;
		ans %= 10;
	}
	std::cout << ans << '\n';
	return ans;
}

int main()
{
	/*std::string inp;
	std::cin >> inp;
	char* str = new char[std::size(inp)];
	for(size_t i = 0; i < std::size(inp); i++)
	{
		*(str + i) = inp[i];
	}
	std::cout << duplicateCount(str);*/

	last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651");
	return 0;
}
