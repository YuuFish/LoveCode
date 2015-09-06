#include<iostream>
using namespace std;

template<class T>
void InsertionSort(T *a, int n)
{
	int in , out;
	for(out = 1; out < n; ++out)
	{
		T  temp = a[out];
		in = out;
		while(in > 0 && a[in-1] >= temp)
		{
			a[in] = a[in -1];
			--in;
		}
		a[in] = temp;
	}
}

template<typename T>
void print(T *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[5] = {3, 4, 2, 5, 1};
	print(a, 5);
	
	InsertionSort(a, 5);
	print(a, 5);
}
