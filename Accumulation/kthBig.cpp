#include<iostream>
#include<cstdlib>
using namespace std;

/*
ѡȡ��kth������� ����ĵ�kth��ʵ�ǰ���С���󣬿��԰�����Ҫ���н�������������Ҫ��
�ο���վ�� http://www.cricode.com/968.html
*/

void swap(int& a , int& b)
{
	a=a^b;  
	b=a^b;  
	a=a^b;  
}

/*�������ã�ȡ������������low��mid��high����λ�������ݣ�ѡȡ�����м���Ǹ�������Ϊ����*/  
int SelectPivotMedianOfThree(int arr[],int low,int high)  
{  
    int mid = low + ((high - low) >> 1);//���������м��Ԫ�ص��±�  
  
    //ʹ������ȡ�з�ѡ������  
    if (arr[mid] > arr[high])//Ŀ��: arr[mid] <= arr[high]  
    {  
        swap(arr[mid],arr[high]);  
    }  
    if (arr[low] > arr[high])//Ŀ��: arr[low] <= arr[high]  
    {  
        swap(arr[low],arr[high]);  
    }  
    if (arr[mid] > arr[low]) //Ŀ��: arr[low] >= arr[mid]  
    {  
        swap(arr[mid],arr[low]);  
    }  
    //��ʱ��arr[mid] <= arr[low] <= arr[high]  
    return arr[low];  
    //low��λ���ϱ���������λ���м��ֵ  
    //�ָ�ʱ����ֱ��ʹ��lowλ�õ�Ԫ����Ϊ���ᣬ�����øı�ָ����  
}


/*
�Ż�������ʹ������ȡ�е��뷨��������ѡ�����˻�Ϊð����������
*/
int k_big(int arr[],int low,int high,int k)
{
	int pivot  = SelectPivotMedianOfThree(arr, low, high);
	int high_tmp = high;
	int low_tmp = low;
	while(low < high)
	{
		//����������ң�ֱ���ҵ���һ��С����ŦԪ��Ϊֹ
		while (low < high && arr[high] >= pivot)
		{
			--high;
		}
		arr[low] = arr[high];
		//�������Ҳ��ң�ֱ���ҵ���һ��������ŦԪ��Ϊֹ
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