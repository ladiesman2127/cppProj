

#include <iostream>

void Merge(int* a, int p, int q, int r)
{
	int i = p - 1, j = q + 1;
	std::cout << p << " " << q << '\n';
	while(i < q && j < r)
	{
		if(a[i] > a[j])
		{
			//std::cout <<"before: " << a[i] << " " << a[j] << '\n';
			std::swap(a[i], a[j]);
			//std::cout <<"after: " << a[i] << " " << a[j] << '\n';
			i++;
		}
		else
		{
			j++;
		}
	}

}

void sort(int* a, int p, int r)
{
	if(p < r)
	{
		int q = (p + r) / 2;
		sort(a, p, q);
		sort(a, q + 1, r);
		Merge(a, p, q, r);

	}
}
int main()
{
	int a[] { 5, 2, 4, 6, 1, 3,6,2,5 };
	sort(a, 0, sizeof(a) / sizeof(a[0]));
	for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		std::cout << a[i] << " ";
	}
}
