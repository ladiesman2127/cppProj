#include <string>
#include <vector>
#include <iostream>

//std::string reverse_words(std::string str)
//{
//	std::string ans = "";
//	int cnt_of_intends = 0;
//	int prev_index;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] = ' ')
//		{
//			cnt_of_intends++;
//			for (int j = i;j > 0;j--)
//			{
//				ans = ans + std::string() + str[j];
//			}
//		}
//	}
//	return ans;
//}

int main()
{
	std::string ans;
	std::string str = "The quick brown fox jumps over the lazy dog.";
	int previous_index = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ' || i == str.size() - 1)
		{
			for (int j = i; j >= previous_index; j--)
			{
				ans += str[j];
			}
			previous_index = i;
		}
	}
	std::cout << ans;
	return 0;
}