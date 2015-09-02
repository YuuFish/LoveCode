#include<iostream>
using namespace std;

long long Fibonacci_1(unsigned int n)
{
	if(n <= 0 )
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	return Fibonacci_1(n-1) + Fibonacci_1(n-2);
}

long long Fibonacci_2(unsigned int n)
{
	int result[2] = {0, 1};
	if(n < 2)
	{
		return result[n];
	}
	long long nFirst = 0;
	long long nNext  = 1;
	long long nRet = 0;
	for(unsigned int i = 2; i <= n; i++)
	{
		nRet = nFirst + nNext;
		nFirst = nNext;
		nNext = nRet;
	}
	return nRet;
}

int main()
{
	cout << Fibonacci_2(8) << endl;
}