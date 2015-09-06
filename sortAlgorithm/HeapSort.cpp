#include<iostream>
using namespace std;

void HeapAdjust(int a[], int n, int size)
{
	int nChild = 2*n + 1; // 左孩子
	int t;
	while(nChild < size)
	{
		if((nChild+1 < size)&&(a[nChild+1]> a[nChild]))
			nChild++;
		if(a[nChild]<a[n])
			break;
		t = a[nChild];
		a[nChild] = a[n];
		a[n] = t;
		n = nChild;
		nChild = 2 * n + 1;
	}
}

/*
 这里的k指的是top-k问题吗，当k为size或(size-1)时，则是纯正完整的堆排序过程;
 k<size-1时，则表示取数据中前k大的元素, 没有对所有的元素进行排序，仅部分排序
*/
void HeapSort(int a[], int size, int k)  
{ 
	if(NULL == a || size < 0)
		return;
	int i;
	for(i = size/2-1; i>=0; i--) // 这里要理解好为什么是size/2-1的逻辑
		HeapAdjust(a, i, size); // 依次调整堆，其实就是建堆的过程，因此这里没有额外的建堆函数
	int t;
	int s = size - k;
	while(size>s) // 依次找到最大的放置在数组的末尾
	{
		t = a[size-1];
		a[size-1] = a[0];
		a[0] = t;
		size --;
		HeapAdjust(a, 0, size);
	}
}

void print(int a[], int n)
{
	if(NULL == a || n < 0)
		return;
	for(int i=0; i< n; i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	int a[16] = {2, 1, 3, 5,4, 4, 2, 6, 13, 12, 1, 10, 21, 20, 96, -1};
	HeapSort(a, 16, 16);
	
	print(a, 16); // 全部进行排序
	cout << endl;
	
	
	int b[6] = {2, 1, 3, 20, 96, -1};
	HeapSort(b, 6, 3); // 取top3，数组最后三个数是前三大的
	print(b, 6);
	cout << endl;
	
	int c[6] = {0, 12, 31, 20, 968, -1};
	HeapSort(c, 6, 2); // top2
	print(c, 6);
}