#include<iostream>
using namespace std;

template<typename T>
int bSearch( T x, T v[ ], int n )
{
	int low, high;
	low = 0;
	high = n - 1;
	while( low <= high )
	{
		int mid = (low + high)/2;
		if( x < v[mid])
			high = mid - 1;
		else if( x > v[mid] )
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}

int main()
{
	int array[] = {1,3,6,8,10,12,24,35,56,88,90,99};
	cout << bSearch(1, array, 12) << endl;
	cout << bSearch(3, array, 12) << endl;
	cout << bSearch(7, array, 12) << endl;
	
	char string[] = "abcdegh";
	cout << bSearch('g', string, 7) << endl;
	cout << bSearch('f', string, 7) << endl;
}
