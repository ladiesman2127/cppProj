#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>



class person
{
public:
	std::string name;
	int score;
	person(const std::string& name, const int score)
	{
		this->name = name;
		this->score = score;
	}
	bool operator()(const person& p) const
	{
		return p.score > 200;
	}

};
int multiply(int x, int y)
{
	std::cout << x << " " << y << '\n';
	return x * y;
}
int main()
{

	/*std::vector<person> v =
	{
		 person("Opinya",200),
		 person("Vanya",440),
		 person("Oan",72),
		 person("Anna",233),
	};*/
	/*size_t cnt = std::count_if(v.begin(), v.end(), v.front());
	std::sort(v.begin(), v.end(), [](const person& a, const person& b)
		{
			return a.score < b.score;
		});
	for (const auto& person : v)
	{
		std::cout << person.score << "\t" << person.name << '\n';
	}
	auto it = std::find_if(v.begin(), v.end(), [](const person& a)
	{
			return a.score == 72;
	});
	std::cout << it->name;*/
	/*std::vector<person> result;
	std::copy_if(v.begin(), v.end(),std::back_inserter(result),[](const person& a)
		{
			return a.score > 200;
		});*/
		/*auto it = (std::remove_if(v.begin(), v.end(), [](const person& a)
					{
						return a.score == 72;
					}));
				v.erase(it, v.end());
				std::string ex = "ab  cc d d                f";
				ex.erase(std::remove(ex.begin(), ex.end(), ' '), ex.end());
				std::cout << ex;*/
				/*std::vector<int> v { 1,3,7,6,9,7,1,1,1,9,7 };
						std::list<int>     v { 1,3,7,6,9,7,1,1,1,9,7 };
						auto max = std::max_element(v.begin(), v.end());
						std::cout << *max << '\n';
						for (const auto& it : v)
						{
							std::cout << it << ' ';
						}
						*/

	std::vector<int>     v  { 1,2,4,3 };
	//std::vector<int>     v1 { 3,1,4   };
	//auto ans = std::accumulate(std::next(v.begin()), v.end(), std::to_string(v[0]), [](std::string a, int b)
	//	{
	//		return a + "-" + std::to_string(b);

	//	});
	//ans.erase(std::remove(ans.begin(), ans.end(), '-'),ans.end());
	//int arr[10]{ 1,-3,5,7,4,44,1,33,222,0 };
	//std::cout << *std::min_element(arr, arr + 10
	/*auto miss = std::mismatch(std::begin(v), std::end(v), std::begin(v1), std::end(v1));
	std::cout << std::equal(std::begin(v), std::end(v), std::begin(v1),std::end(v1));*/
	std::for_each(std::begin(v), std::end(v), [](int& a)
		{
			std::cout << a << '\n';
		});
}
