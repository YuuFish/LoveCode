#include<iostream>
using namespace std;

/*
	Description: find top2, consider the duplicate
	Author: Yuu
*/

void find2Max(const int *num, int n, int& nMax, int& nSecondMax)
{
	nMax = num[0];
	nSecondMax = num[0];
	for(int i= 1; i<n ; i++)
	{
		if(nMax==num[i])
			continue;
		if(nMax==nSecondMax && num[i]<nMax)
		{
			nSecondMax = num[i];
		}
		if(nMax<num[i])
		{
			if(nSecondMax<nMax)
			{
				nSecondMax = nMax;
			}
			nMax = num[i];
		}
		else if(nSecondMax < num[i])
		{
			nSecondMax = num[i];
		}
	}
}

int main()
{
	int d[5] = {2,4,2,3,4};
	//int d[10] = {10, 3, 1, 4, 4, 4, 5, 2, 1,10};
	//int nMax, nSecondMax;
	//find2Max(d, 10, nMax, nSecondMax);
	int nMax, nSecondMax;
	find2Max(d, 5, nMax, nSecondMax);
	cout << nMax << " " << nSecondMax << endl;
	return 0;
}