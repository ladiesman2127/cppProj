#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

void sift_down(int* arr, const int index, const int n)
{
	// Initialize largest as root
	int largest = index;

	// left = 2*i + 1
	int l = 2 * index + 1;

	// right = 2*i + 2
	int r = 2 * index + 2;

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != index) {
		std::swap(arr[index], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		sift_down(arr, largest, n);
	}
}

//BUBBLE SORT
int* bubble_sort(int* arr, const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
	return arr;
}


//SELECTION SORT
int* selection_sort(int* arr, const int SIZE)
{
	int minIndex = 0;
	for (int i = 0; i < SIZE; i++)
	{
		minIndex = i;
		for (int j = i; j < SIZE; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		std::swap(arr[minIndex], arr[i]);
	}
	return arr;
}


//QUICK SORT
int* quick_sort(int* arr, const int SIZE)
{
	int i = 0;
	int j = SIZE - 1;
	int mid = arr[SIZE / 2];
	while (i <= j)
	{
		while (arr[j] > mid)
		{
			j--;
		}

		while (arr[i] < mid)
		{
			i++;
		}

		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (j > 0)
	{
		quick_sort(arr, j + 1);
	}
	if (i < SIZE)
	{
		quick_sort(&arr[i], SIZE - i);
	}
	return arr;
}


//INSERT SORT
int* insert_sort(int* arr, const int SIZE)
{
	for (int i = 1; i < SIZE; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j])
			{
				std::swap(arr[i], arr[j]);
				i--;
			}

		}
	}
	return arr;
}

int partition(int* arr, int l, int r)
{
	const int pivot = arr[l];
	int i = l + 1;
	int j = l;
	while (i < r)
	{
		if (arr[i] <= pivot)
		{
			j++;
			std::swap(arr[i], arr[j]);
		}
		i++;
	}
	std::swap(arr[j], arr[l]);
	return j;
}

void partition3(int* arr, const int l, const int r, int& i, int& j)
{
	i = l;
	j = r;
	int mid = l + 1;
	const int pivot = arr[l];
	while(mid <= j)
	{
		if(arr[mid] < pivot)
		{
			std::swap(arr[mid++], arr[i++]);
		}
		else if(arr[mid] > pivot)
		{
			std::swap(arr[mid], arr[j--]);
		}
		else
			mid++;
	}
}

void quick_sort(int* arr, const int l, const int r)
{
	if (l < r)
	{
		const int pivot = partition(arr, l, r);
		quick_sort(arr, l, pivot - 1);
		quick_sort(arr, pivot + 1, r);
	}
}

void quick_sort3(int* arr, int l, int r)
{
	if (l < r)
	{
		int k = rand() % (r - l + 1) + l;
		std::swap(arr[k], arr[l]);
		int i; int j;
		partition3(arr, l, r, i, j);
		quick_sort3(arr, l, i - 1);
		quick_sort3(arr, j + 1, r);
	}
}


//MERGE SORT
int* merge_sort(int* arr, const int SIZE) // Recursive method
{
	if (SIZE < 2) return arr;
	int rSize;
	if (SIZE % 2 == 0)
		rSize = SIZE / 2;
	else
		rSize = SIZE / 2 + 1;
	int* left = new int[SIZE / 2];
	int* right = new int[rSize];
	for (int i = 0; i < SIZE / 2; i++)
	{
		left[i] = arr[i];
	}
	for (int i = 0; i < rSize; i++)
	{
		right[i] = arr[i + SIZE / 2];
	}
	merge_sort(left, SIZE / 2);
	merge_sort(right, rSize);

	int i = 0, k = 0, n = 0;
	while (i < SIZE / 2 && k < rSize)
	{
		if (left[i] <= right[k])
		{
			arr[n++] = left[i++];
		}
		else
		{
			arr[n++] = right[k++];
		}
	}

	while (i < SIZE / 2)
	{
		arr[n++] = left[i++];
	}
	while (k < rSize)
	{
		arr[n++] = right[k++];
	}
	delete[] left;
	delete[] right;

	return arr;
}

std::vector<int> merge2(const std::vector<int>& ar1, const std::vector<int>& ar2)
{
	std::vector<int> result(ar1.size() + ar2.size());
	int i = 0;
	int j = 0;
	int n = 0;
	while (i < ar1.size() && j < ar2.size())
	{
		if (ar1[i] < ar2[j])
		{
			result[n++] = ar1[i];
			i++;
		}
		else
		{
			result[n++] = ar2[j];
			j++;
		}
	}
	while (i < ar1.size())
	{
		result[n++] = ar1[i++];
	}
	while (j < ar2.size())
	{
		result[n++] = ar2[j++];
	}
	return result;
}

std::vector<int> iterative_merge_sort(std::vector<int>& ar)
{
	std::queue<std::vector<int>> q;
	for (int& el : ar)
	{
		q.push(std::vector<int> {el});
	}
	while (q.size() > 1)
	{
		auto ar1 = q.front();
		q.pop();
		auto ar2 = q.front();
		q.pop();
		q.push(merge2(ar1, ar2));
	}
	return q.front();

}

//COUNTING SORT
int* counting_sort(int* arr, const int SIZE)
{
	int count_arr[1000]{};
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (arr[i] == j)
			{
				count_arr[j]++;
			}
		}
		arr[i] = 0;
	}
	int i = 0;
	while (i < SIZE)
	{
		for (int k = 0; k < 1000; k++)
		{
			for (int j = 0; j < count_arr[k]; j++)
			{
				arr[i] = k;
				i++;
			}
		}

	}
	return arr;
}

//SHAKING SORT
void shaker_sort(int* arr, const int SIZE)
{
	int left = 0;
	int right = SIZE - 1;
	while (left <= right)
	{
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
			}
		}
		right--;
		for (int j = right; j > left; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
			}
		}
		left++;
	}
}


void heap_sort(int* arr,const int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		sift_down(arr, i, n);

	int size = n - 1;
	for (int i = n - 1; i > 0; i--) {

		// Move current root to end
		std::swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		sift_down(arr, 0, i);
	}
}

int main()
{
	const unsigned int start_time = clock();
	constexpr int N = 10;
	int arr[N];
	for (int& i : arr)
	{
		std::cin >> i;
	}

	heap_sort(arr, N);

	for (const int el : arr)
	{
		std::cout << el << " ";
	}

	return 0;
}