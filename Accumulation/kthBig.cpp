#include<iostream>
#include<cstdlib>
using namespace std;

/*
选取第kth大的数， 这里的第kth其实是按从小到大，可以按照需要进行降序排序以满足要求
参考网站： http://www.cricode.com/968.html
*/

void swap(int& a , int& b)
{
	a=a^b;  
	b=a^b;  
	a=a^b;  
}

/*函数作用：取待排序序列中low、mid、high三个位置上数据，选取他们中间的那个数据作为枢轴*/  
int SelectPivotMedianOfThree(int arr[],int low,int high)  
{  
    int mid = low + ((high - low) >> 1);//计算数组中间的元素的下标  
  
    //使用三数取中法选择枢轴  
    if (arr[mid] > arr[high])//目标: arr[mid] <= arr[high]  
    {  
        swap(arr[mid],arr[high]);  
    }  
    if (arr[low] > arr[high])//目标: arr[low] <= arr[high]  
    {  
        swap(arr[low],arr[high]);  
    }  
    if (arr[mid] > arr[low]) //目标: arr[low] >= arr[mid]  
    {  
        swap(arr[mid],arr[low]);  
    }  
    //此时，arr[mid] <= arr[low] <= arr[high]  
    return arr[low];  
    //low的位置上保存这三个位置中间的值  
    //分割时可以直接使用low位置的元素作为枢轴，而不用改变分割函数了  
}


/*
优化，可以使用三次取中的想法避免枢轴选择导致退化为冒泡排序问题
*/
int k_big(int arr[],int low,int high,int k)
{
	int pivot  = SelectPivotMedianOfThree(arr, low, high);
	int high_tmp = high;
	int low_tmp = low;
	while(low < high)
	{
		//从右向左查找，直到找到第一个小于枢纽元素为止
		while (low < high && arr[high] >= pivot)
		{
			--high;
		}
		arr[low] = arr[high];
		//从左向右查找，直到找到第一个大于枢纽元素为止
		while (low < high && arr[low] <= pivot)
		{
			++low;
		}
		arr[high] = arr[low];
	}
	
	arr[low] = pivot;

	if (low == k - 1)
	{
		return arr[low];
	}
	else if(low > k - 1)
	{
		return k_big(arr,low_tmp,low-1,k);
	}
	else
	{
		return k_big(arr,low+1,high_tmp,k);
	}
}


int main()
{
	int arr[20]={-91,0,6,82,15,18,7,46,-29,12, 12, 7, 6, 3, 6, 21, 9,10,3, 33};
	int i;
	for(i=0;i<20;++i)
		cout << arr[i] << ' ';
	cout << endl;
	int kthBig = k_big(arr,0,19,11);
	cout << kthBig << endl;

	for(i=0;i<20;++i)
		cout << arr[i] << ' ';
	cout << endl;
	system("pause");
}