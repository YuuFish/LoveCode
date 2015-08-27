#include <iostream>
using namespace std;

/*

三次取中作为枢轴，避免了当排序数组有序时时间复杂度退化为O(N^2)的情况
	注：STL中sort的实现当元素个数少于10个时，调用插入排序
参考网站：
	http://blog.csdn.net/insistgogo/article/details/7785038
	http://baike.baidu.com/link?url=cskKnDW-StS4kn8P_Q_n69RDxqcKcF46JNMdLcALdxWPoTsOO5ZEi-b3FKBocA3ScARIgiVx4ZuiEjXMw2qHa_
	
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

void Qsort(int a[], int low, int high)
{
	if(a==NULL)
		return;
	
	// if (high - low + 1 < 10)   // STL中的代码，如果元素个数比较少，使用插入排序
    // {  
    //     InsertSort(arr,low,high);  
    //     return;  
    // }  
	
	SelectPivotMedianOfThree(a, low, high);
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];
 
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
 
        a[first] = a[last];
 
        while(first < last && a[first] <= key)
        {
            ++first;
        }
         
        a[last] = a[first];    

    }
    a[first] = key;
	
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

int main()
{
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24, -90};
	for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }
	cout << endl;
 
    Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
 
    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }
	cout << endl;
     
    return 0;
}

