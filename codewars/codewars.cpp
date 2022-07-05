#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>

int countingValleys(int steps, std::string path)
{
	constexpr int sea_level = 0;
	int current_level = 0;
	int count_sea_eq_current = 0;
	for (auto&& step : path)
	{
		if (step == 'D')
			--current_level;
		else if (step == 'U')
		{
			++current_level;
			if (current_level == sea_level)
				++count_sea_eq_current;
		}


	}
	return count_sea_eq_current;
}

std::size_t duplicateCount(const char* in) {
	std::map<char, size_t> counts;
	for (const char* c = in; *c != '\0'; ++c) {
		counts[tolower(*c)]++;

	}
	return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
		return count.second > 1;
		});
}

int Module(const int divider, const std::string& str2)
{
	int mod = 0;
	for (int i = 0; i < str2.length(); ++i)
	{
		mod = (mod * 10 + str2[i] - '0') % divider;
	}
	return mod;
}

int last_digit(const std::string& str1, const std::string& str2)
{
	if (str1.length() == 1 && str1[0] <= 1)
		return str1[0];
	if (str2.length() == 1 && str2[0] == 0)
		return 1;
	const int power = Module(4, str2) == 0 ? 4 : Module(4, str2);
	return std::pow(str1[str1.length() - 1] - '0', power);

}

//std::string brainLuck(const std::string& code, std::string& input) {
//	std::string result;
//	char* ptr = &input[0];
//	for(auto ch : code)
//	{
//		switch (ch)
//		{
//			case '>':
//				ptr++;
//				break;
//			case '<':
//				ptr--;
//				break;
//			case '+':
//				++*ptr;
//				break;
//			case '-':
//				--*ptr;
//				break;
//			case '.':
//				putchar(*ptr);
//				break;
//			case ',':
//				*ptr = getchar();
//				break;
//			case '[':
//				while(*ptr)
//				{
//					if (ch == ']')
//						break;
//
//				}
//			default:
//				break;
//
//		}
//	}
//}

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) //  O(n2);
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		for (int j = 1; j < numbers.size(); ++j)
		{
			if (i + j == target)
				return std::pair<size_t, size_t>(i, j);
		}
	}
}


std::pair<std::size_t, std::size_t> two_sum2(const std::vector<int>& numbers, int target) //  O(n2);
{
	std::unordered_map<int, std::size_t> hash;
	for (int i = 0; i < numbers.size(); ++i)
	{
		auto it2 = hash.find(numbers[i]);
		if (it2 != hash.end())
		{
			return { it2->second,i };
		}
		hash.emplace(target - numbers[i], i);
	}
	return { -1,-1 };
}


std::string duplicate_encoder(const std::string& word) {
	std::unordered_map<char, size_t> map;
	std::string result;
	for (const auto& ch : word)
	{
		++map[tolower(ch)];
	}
	for(auto& ch : word)
	{
		if(map.find(tolower(ch))->second > 1)
		{
			result += ')';
		}
		else
		{
			result += '(';
		}
	}
	return result;
}

std::string duplicate_encoder2(const std::string& word) {

	std::unordered_map<char, size_t> map;

	for (const auto& ch : word)
		++map[tolower(ch)];

	std::string result;
	for (const auto& ch : word)
		result += (map[tolower(ch)] == 1) ? '(' : ')';

	return result;
}

int main()
{
	//std::cout << countingValleys(12,"DDUUDDUDUUUD");
	//*std::cout << duplicateCount(&inp[0]);
	//last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651");
	//std::cout << last_digit("3", "10") << '\n';
	//std::cout << last_digit("6", "2") << '\n';
	//std::cout << last_digit("150", "53") << '\n';
	std::cout << duplicate_encoder("Success");
	return 0;
}
