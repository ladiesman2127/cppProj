
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to find b % a
int Modulo(int a, const std::string& b)
{

	int mod = 0;

	for (const char i : b)
		mod = (mod * 10 + i - '0') % a;

	return mod;
}

int last_digit(const std::string& a, const std::string& b)
{
	int len_a = a.size(), len_b = b.size();

	// if a and b both are 0
	if (len_a == 1 && len_b == 1 && b[0] == '0' && a[0] == '0')
		return 1;

	// if exponent is 0
	if (len_b == 1 && b[0] == '0')
		return 1;

	// if base is 0
	if (len_a == 1 && a[0] == '0')
		return 0;
	if (len_b == 1 && b[0] == '1')
		return a[a.size() - 1] - '0';

	// if exponent is divisible by 4 that means last
	// digit will be pow(a, 4) % 10.
	// if exponent is not divisible by 4 that means last
	// digit will be pow(a, b%4) % 10
	int exp = (Modulo(4, b) == 0) ? 4 : Modulo(4, b);

	// Find last digit in 'a' and compute its exponent
	int res = pow(a[len_a - 1] - '0', exp);

	// Return last digit of result
	return res % 10;
}

static std::vector<int> sqInRect(int lng, int wdth)
{
	std::vector<int> ans;
	if (lng == wdth) return {};
	while (lng >= 1)
	{
		ans.push_back(std::min(lng, wdth));
		if (lng < wdth)
			wdth -= lng;
		else
			lng -= wdth;
	}
	return ans;
}

union my_union
{
	short int a;
	int       b;
	float     c;
};

int main()
{
	////std::cout << Modulo(5, "248779246");
	//std::string str2 = "248779246";
	//std::cout << std::stoi(str2.substr(str2.size() - 2)) ;
	sqInRect(20, 14);
	my_union mu;
	mu.a = 5;
	mu.b = 440000;
	mu.c = 22.4444;
	std::cout << mu.a << " " << mu.b << " " << mu.c;


}