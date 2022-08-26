#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <map>
#include <numeric>

// IMPROVE
class Fibonacci {
public:
	static int get_remainder(long long n, int m) {
		assert(n >= 1);
		assert(m >= 2);
		int n0 = 0;
		int n1 = 1;
		int n2 = 0;
		std::vector<int> reminders{ 0,1 };
		while (n2 < 6 * m)
		{
			n2 = (n0 + n1) % m;
			reminders.push_back(n2);
			n0 = n1;
			n1 = n2;
			if (n0 == 0 && n1 == 1)
				break;
		}
		reminders.pop_back();
		reminders.pop_back();
		return reminders[n % reminders.size()];
	}
};
template <class T>
T gcd(T a ,T b)
{
	assert(a > 0);
	while(b > 0)
	{
		a %= b;
		std::swap(b, a);
	}
	return a;
}

#pragma region SLIDING WINDOW

void max_in_sliding_windows()
{
	int n, k;
	std::cin >> n;
	std::vector<int> nums(n);
	std::list<int> deque;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> nums[i];
	}
	std::cin >> k;
	for (int i = 0; i < n; ++i)
	{
		if (!deque.empty() && deque.front() == i - k)
			deque.pop_front();
		while (!deque.empty() && nums[i] > nums[deque.back()])
			deque.pop_back();
		deque.push_back(i);
		if (i >= k - 1)
			std::cout << nums[deque.front()] << ' ';
	}
}

std::vector<int> slidingWindowMaximum(std::vector<int> nums, int windowLength)
{
	std::vector<int> result;
	if (nums.empty())
		return result;
	std::deque<int> deque;
	for (int i = 0; i < windowLength; ++i)
	{
		while (!deque.empty() && nums[deque.back()] < nums[i])
			deque.pop_back();
		deque.push_back(i);
	}
	for (int i = windowLength; i < nums.size(); ++i)
	{
		result.push_back(nums[deque.front()]);
		while (!deque.empty() && deque.front() <= i - windowLength)
			deque.pop_front();
		while (!deque.empty() && nums[deque.back()] < nums[i])
			deque.pop_back();
		deque.push_back(i);
	}
	result.push_back(nums[deque.front()]);
	return result;
}

#pragma endregion

long* fib(const int n)
{
	assert(n >= 0);
	if (n == 1 || n == 0)
		return new long(n);
	const auto cache = new long[n];
	cache[0] = 0;
	cache[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		cache[i] = cache[i - 1] + cache[i - 2];
	}

	return cache;
}

void max_in_sliding_window()
{
	//O(n*k)
	/*int n, m;
	std::cin >> n;
	std::vector<int> arr(n);
	for(int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	std::cin >> m;
	int indexOfMax = 0;
	for(int i = 0; i <= n - m; ++i)
	{
		int startPos = i;
		int endPos   = i + m;
		if (indexOfMax < endPos && indexOfMax > startPos)
		{
			startPos = indexOfMax;
		}
		int max = arr[startPos];
		while(startPos < endPos)
		{
			if(max < arr[startPos])
			{
				max = arr[startPos];
				indexOfMax = startPos;
			}
			startPos++;
		}
		std::cout << max << " ";
	}*/
	int n, k;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	std::cin >> k;
	int max = arr[0];
	for (int i = 0; i < k; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
}


void stack_max()
{
	int n;
	std::string s;
	std::cin >> n;
	std::vector<int> stack;
	std::vector<int> ans;
	std::string line;
	std::getline(std::cin, s);
	for (int i = 0; i < n; ++i)
	{
		std::getline(std::cin, line);

		if (stack.empty())
		{
			const int NUM = std::stoi(line.substr(4));
			stack.push_back(NUM);
		}
		else
		{
			if (line[1] == 'u')
			{
				const int NUM = std::stoi(line.substr(4));
				if (NUM > stack.back())
					stack.push_back(NUM);
				else
					stack.push_back(stack.back());
			}
			else if (line[1] == 'o')
			{
				stack.pop_back();
			}
			else if (line[1] == 'a')
			{
				ans.push_back(stack.back());
			}
		}
	}
	for (const auto& el : ans)
	{
		std::cout << el << '\n';
	}
}

int tree_height(const int n, const int* tree)
{
	int max_lenght = 1;
	for (int i = 0; i < n; ++i)
	{
		int curIndex = i;
		int Lenght = 1;
		while (tree[curIndex] != -1)
		{
			Lenght++;
			curIndex = tree[curIndex];
		}
		if (Lenght > max_lenght)
			max_lenght = Lenght;
	}
	std::cout << max_lenght;
	return max_lenght;
}

void brackets_checker(std::string s)
{
	std::stack<std::pair<char, int>> open_brackets;
	int curr_pos = 0;
	for (auto ch : s)
	{
		++curr_pos;
		if (ch == '(' || ch == '[' || ch == '{')
		{
			open_brackets.emplace(ch, curr_pos);
		}
		else if (ch == ')' || ch == ']' || ch == '}')
		{
			if (open_brackets.empty())
			{
				std::cout << curr_pos;
				return;
			}
			const int top = open_brackets.top().first;
			open_brackets.pop();
			if (ch == ')' && top != '(' || ch == ']' && top != '[' || ch == '}' && top != '{')
			{
				std::cout << std::to_string(curr_pos);
				return;
			}
		}
	}
	if (open_brackets.empty())
	{
		std::cout << "Success";
	}
	else
	{
		std::cout << open_brackets.top().second;
	}
}


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

std::size_t duplicateCount(const char* in)
{
	std::map<char, size_t> counts;
	for (const char* c = in; *c != '\0'; ++c)
	{
		counts[tolower(*c)]++;
	}
	return std::count_if(cbegin(counts), cend(counts), [](const auto& count)
	{
		return count.second > 1;
	});
}

int Module(const int divider, const std::string& str2)
// Так как большое число не помещается в стандартные типы надо закинуть
//его в строку и делить по "школьному" и в конце получаем остаток от деления...
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
			return {it2->second, i};
		}
		hash.emplace(target - numbers[i], i);
	}
	return {-1, -1};
}


std::string duplicate_encoder(const std::string& word)
{
	std::unordered_map<char, size_t> map;
	std::string result;
	for (const auto& ch : word)
	{
		++map[tolower(ch)];
	}
	for (auto& ch : word)
	{
		if (map.find(tolower(ch))->second > 1)
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

std::string duplicate_encoder2(const std::string& word)
{
	std::unordered_map<char, size_t> map;

	for (const auto& ch : word)
		++map[tolower(ch)];

	std::string result;
	for (const auto& ch : word)
		result += (map[tolower(ch)] == 1) ? '(' : ')';

	return result;
}

int designerPdfViewer(std::vector<int> h, std::string word)
{
	std::vector<int> temp;
	for (const auto& ch : word)
	{
		temp.push_back(h[ch - 97]);
	}
	return *std::max_element(temp.begin(), temp.end()) * temp.size();
}

int reverse(int n)
{
	if (n < 10)
		return n;
	int result = 0;
	int power = 0;
	while (n > 0)
	{
		result = result * 10 + (n % 10);
		n /= 10;
	}
	return result;
}

int beautifulDays(int i, int j, int k)
{
	int result = 0;
	while (i <= j)
	{
		if (abs(i - reverse(i)) % k == 0)
		{
			++result;
		}
		i++;
	}
	return result;
}

int viralAdvertising(const int n)
{
	int shared = 5;
	int liked = std::floor(n / 2);
	int cumulative = liked;
	std::cout << "1" << " " << shared << " " << liked << " " << cumulative << '\n';
	for (int i = 0; i < n - 1; ++i)
	{
		std::cout << i + 2 << " " << shared << " " << liked << " " << cumulative << '\n';
		shared = liked * 3;
		liked = std::floor(shared / 2);
		cumulative += liked;
	}
	return cumulative;
}

void staircase(int n)
{
	for (int i = 0; i < n; ++i)
	{
		int j = 0;
		while (j < n - i - 1)
		{
			std::cout << " ";
			j++;
		}
		while (j < n)
		{
			std::cout << "#";
			j++;
		}

		std::cout << '\n';
	}
}

std::string timeConversion(std::string s)
{
	std::string result;
	int hours = std::stoi(s);
	if (s[8] == 'P' && s[9] == 'M' && hours == 12) result = std::to_string(hours);
	else if (s[8] == 'P' && s[9] == 'M') result = std::to_string(hours + 12);
	else if (s[s.size() - 2] == 'A' && s[9] == 'M' && hours == 12)result = "00";
	else
	{
		result.push_back(s[0]);
		result.push_back(s[1]);
	}
	for (int i = 2; i < s.size() - 2; ++i)
	{
		result += s[i];
	}
	return result;
}

void miniMaxSum(std::vector<int> arr)
{
	// max and min of sum of 4 element in 6 elements arr
	const long long sumOfElements = std::accumulate(arr.begin(), arr.end(), static_cast<long long>(0));
	std::sort(arr.begin(), arr.end());
	std::cout << sumOfElements - static_cast<long long>(arr[arr.size() - 1]) << " " << sumOfElements - static_cast<long
		long>(arr[0]);
}

std::vector<int> gradingStudents(std::vector<int> grades)
{
	std::vector<int> result;
	for (const auto& el : grades)
	{
		if (el < 40)
			result.push_back(el);
		else
		{
			int next5_multipliable = el;
			while (next5_multipliable % 5 != 0)
			{
				next5_multipliable++;
			}
			if (next5_multipliable - el < 3)
				result.push_back(next5_multipliable);
			else
				result.push_back(el);
		}
	}
	return result;
}

std::string kangaroo(int x1, int v1, int x2, int v2)
{
	while (true)
	{
		if (x1 == x2)
		{
			return "YES";
		}
		if ((x1 < x2 && v1 <= v2) || (x1 > x2 && v1 >= v2))
		{
			return "NO";
		}
		x1 += v1;
		x2 += v2;
	}
}

bool check(int i, std::vector<int> a, std::vector<int> b)
{
	for (const auto& el_a : a)
	{
		for (const auto& el_b : b)
		{
			if (i % el_a != 0 || el_b % i != 0)
				return false;
		}
	}
	return true;
}

int getTotalX(std::vector<int> a, std::vector<int> b)
{
	int count = 0;
	for (int i = a[a.size() - 1]; i <= b[0]; ++i)
	{
		if (check(i, a, b)) count++;
	}
	return count;
}

std::vector<int> breakingRecords(std::vector<int> scores)
{
	std::vector<int> result(2);
	int max, min;
	int max_count = 0, min_count = 0;
	max = min = scores[0];
	for (const auto& score : scores)
	{
		if (score > max)
		{
			max = score;
			max_count++;
		}
		else if (score < min)
		{
			min = score;
			min_count++;
		}
	}
	result[0] = max_count;
	result[1] = min_count;
	return result;
}

int birthday(std::vector<int> s, int d, int m)
{
	int sum;
	int countOfRes = 0;
	for (int i = 0; i <= s.size() - m; ++i)
	{
		sum = 0;
		for (int j = i; j < i + m; ++j)
		{
			sum += s[j];
		}
		if (sum == d)
			countOfRes++;
	}
	return countOfRes;
}


int main()
{
	//std::cout << countingValleys(12,"DDUUDDUDUUUD");
	//*std::cout << duplicateCount(&inp[0]);
	//last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651");
	//std::cout << last_digit("3", "10") << '\n';
	//std::cout << last_digit("6", "2") << '\n';
	//std::cout << last_digit("150", "53") << '\n';
	//std::cout << duplicate_encoder("Success");
	//std::cout << viralAdvertising(4);
	//staircase(6);
	//std::vector<int> arr{ 396285104, 573261094, 759641832, 819230764, 364801279 };
	//miniMaxSum(arr);
	//std::cout << timeConversion("12:40:22AM");
	//gradingStudents(std::vector<int>{ 22,
	//	86,
	//	30,
	//	0,
	//	16,
	//	51,
	//	53,
	//	42,
	//	48,
	//	22,
	//	69,
	//	12,
	//	27,
	//	34,
	//	24,
	//	95,
	//	16,
	//	32,
	//	22,
	//	52});
	//std::vector<int> b { 16, 32, 96 };
	//std::cout << getTotalX(a, b);
	//std::cout << kangaroo(0, 3, 4, 2);
	//std::vector<int> a { 4 };
	//birthday(a, 4, 1);
	//int n;
	//std::cin >> n;
	//int* arr = new int[n];
	//for (int i = 0; i < n; ++i)
	//	std::cin >> arr[i];
	//tree_height(n, arr);
	//delete[] arr;
	//stack_max();
	//auto fi =  fib(8);
	//for(auto i = 0; i <= 8; ++i)
	//	std::cout << fi[i] << ' ';
	//get_reminder(1025, 55);
	std::cout << gcd(125, 25);
	return 0;
}
