#include <ctime>
#include <iostream>
#include <vector>

//BUBBLE SORT
int* bubble_sort(int* arr, const int SIZE)
{
	for(int i = 0; i < SIZE - 1; i++)
	{
		for(int j = 0; j < SIZE - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
	return arr;
}


//SELECTION SORT
int* selection_sort(int* arr, const int SIZE)
{
	int min, index_of_min = 0;
	for(int i = 0; i < SIZE; i++)
	{
		min = arr[i];
		for(int j = i; j < SIZE; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				index_of_min = j;
			}
		}
		std::swap(arr[index_of_min], arr[i]);
	}
	return arr;
}


//QUICK SORT
int* quick_sort(int* arr, const int SIZE)
{
	int i = 0;
	int j = SIZE - 1;
	int mid = arr[SIZE / 2];
	while(i <= j)
	{
		while(arr[j] > mid)
		{
			j--;
		}

		while(arr[i] < mid)
		{
			i++;
		}

		if(i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if(j > 0)
	{
		quick_sort(arr, j + 1);
	}
	if(i < SIZE)
	{
		quick_sort(&arr[i], SIZE - i);
	}
	return arr;
}


//INSERT SORT
int* insert_sort(int* arr, const int SIZE)
{
	for(int i = 1; i < SIZE; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[i] < arr[j])
			{
				std::swap(arr[i], arr[j]);
				i--;
			}

		}
	}
	return arr;
}


//MERGE SORT
int* merge_sort(int* arr, const int SIZE)
{
	if(SIZE < 2) return arr;
	int rSize;
	if(SIZE % 2 == 0)
		rSize = SIZE / 2;
	else
		rSize = SIZE / 2 + 1;
	int* left = new int[SIZE / 2];
	int* right = new int[rSize];
	for(int i = 0; i < SIZE / 2; i++)
	{
		left[i] = arr[i];
	}
	for(int i = 0; i < rSize; i++)
	{
		right[i] = arr[i + SIZE / 2];
	}
	merge_sort(left, SIZE / 2);
	merge_sort(right, rSize);

	int i = 0, k = 0, n = 0;
	while(i < SIZE / 2 && k < rSize)
	{
		if(left[i] <= right[k])
		{
			arr[n++] = left[i++];
		}
		else
		{
			arr[n++] = right[k++];
		}
	}

	while(i < SIZE / 2)
	{
		arr[n++] = left[i++];
	}
	while(k < rSize)
	{
		arr[n++] = right[k++];
	}
	delete[] left;
	delete[] right;

	return arr;
}


//COUNTING SORT
int* counting_sort(int* arr, const int SIZE)
{
	int count_arr[1000] {};
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			if(arr[i] == j)
			{
				count_arr[j]++;
			}
		}
		arr[i] = 0;
	}
	int i = 0;
	while(i < SIZE)
	{
		for(int k = 0; k < 1000; k++)
		{
			for(int j = 0; j < count_arr[k]; j++)
			{
				arr[i] = k;
				i++;
			}
		}

	}
	return arr;
}

int main()
{
	const unsigned int start_time = clock();
	const int N = 11;
	int arr[N];
	for(int& i : arr)
	{
		std::cin >> i;
	}

	bubble_sort(arr, N);

	for(int i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}