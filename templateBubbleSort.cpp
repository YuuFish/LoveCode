#include<iostream>
#include<cstring>

using namespace std;

template<class T>
void BubbleSort(T* a, int n);

template<class T>
void Print(T*, int );

int main()
{
	int a[6] = {2,1,4,3,42,2};
	Print<int>(a, sizeof(a)/sizeof(a[0]));
	
	BubbleSort(a, sizeof(a)/sizeof(a[0]));
	Print(a, sizeof(a)/sizeof(a[0]));
	
	char str[] = "hello world";
	Print(str, strlen(str));
	
	BubbleSort(str, strlen(str));
	Print(str, strlen(str));
	
	
	
}

template<typename T>
void BubbleSort(T a[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		bool isSwap = false;
		for(int j = 0; j < n-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				// swap(a[j], a[j+1]);
				T temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				isSwap = true;
			}
		}
		if(!isSwap)
		{
			return;
		}
	}
}

template<typename T>
void Print(T *a, int n)
{
	for(int i= 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}


























