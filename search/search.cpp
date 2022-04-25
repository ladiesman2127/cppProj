
#include <iostream>

int binary_search(const int* arr, int size, const int guess)
{
	int low = 0;
	int mid;
	int high = size - 1;
	while(low <= high)
	{
		mid = (high + low) / 2;
		if(arr[mid] == guess)
		{
			return mid;
		}
		if(arr[mid] > guess)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return NULL;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int guess;
	std::cin >> guess;
	std::cout << binary_search(arr, std::size(arr), guess);
}

