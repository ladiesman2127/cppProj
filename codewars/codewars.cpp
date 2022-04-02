#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> solution(const std::string& s)
{
	std::vector<std::string> answer;

	for (int i = 0; i < s.length(); i += 2)
	{
		if (s.length() % 2 != 0 && i == s.length() - 1)
		{
			answer.push_back(std::string() + s[i] + "_");
			return answer;
		}
		answer.push_back(std::string() + s[i] + s[i + 1]);
	}
	return answer;
}
int main()
{
	
	return 0;
}