#include<iostream>
using namespace std;

void Merge(int a[], int tmp[], int lPos, int rPos, int rEnd)
{ // 这里merge类似归并两个有序数组，可以参考merge two sorted array方法，减少重复的移动次数，
	int i, lEnd, numElements, tmpPos;
	lEnd = rPos - 1;
	tmpPos = lPos;
	numElements = rEnd - lPos + 1;
	
	while(lPos <= lEnd && rPos <= rEnd)
	{
		if( a[lPos] <= a[rPos] )
			tmp[tmpPos++] = a[lPos++];
		else
			tmp[tmpPos++] = a[rPos++];
	}
	while(lPos <= lEnd)
		tmp[tmpPos++] = a[lPos++];
	while(rPos <= rEnd)
		tmp[tmpPos++] = a[rPos++];
	for(i = 0; i<numElements; i++, rEnd--)
		a[rEnd] = tmp[rEnd];
}

void mSort(int a[], int tmp[], int low, int high)
{
	if(low < high && low >= 0)
	{
		int mid = (low+high)/2;
		mSort(a, tmp, low, mid);
		mSort(a, tmp, mid+1, high);
		Merge(a, tmp, low, mid+1, high);
	}
	
}

void MergeSort(int a[], int len)
{
	int *tmp = NULL;
	tmp = new int[len];
	if(tmp != NULL)
	{
		mSort(a, tmp, 0, len -1);
		delete[] tmp;
	}
}

void print(int a[], int n)
{
	if(a != NULL && n >= 0)
	{
		for(int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int a[10] = {3, 2, 54,12, 2, 5,7, 9, 5, 45};
	print(a, 10);
	MergeSort(a, 10);
	print(a, 10);
	cout << endl;
}