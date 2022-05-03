
#include <iostream>
#define debug
void merge(int* a, int p, int q, const int r)
{
	const int l_s = q - p + 1;
	const int r_s = r - q;
	int* left = new int[l_s];
	int* right = new int[r_s];
	std::cout << "left: ";
	for(int i = 0; i < l_s; i++)
	{
		left[i] = a[i + p ];
#ifdef debug
		std::cout << left[i] << " ";
#endif
	}
	std::cout << "\tRight: ";
	for(int j = 0; j < r_s; j++)
	{
		right[j] = a[j + q + 1] ;
#ifdef debug
		std::cout << right[j] << " ";
#endif
	}
	std::cout << '\n';
	int i = 0;
	int j = 0;
	int k = p;

	while(i < l_s && j < r_s)
	{
		if(left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < l_s)
	{
		a[k] = left[i];
		i++;
		k++;
	}
	while(j < r_s)
	{
		a[k] = right[j];
		j++;
		k++;
	}
}

void sort(int* a, int p, int r)
{
	if(p < r)
	{
		int q = (p + r) / 2;
		sort(a, p, q);
		sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
int main()
{
	int a[] { 5, 2, -4, 6, 1, 3 ,6, 2, 5 };
	sort(a, 0, std::size(a) - 1);
	std::cout << '\n';
	for(const int i : a)
	{
		std::cout << i << " ";
	}
}
