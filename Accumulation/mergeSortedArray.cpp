/*
题目： LeetCode 88 
Merge Sorted Array  合并两个有序数组，使得合并后有序
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 
are m and n respectively.
*/

#include<iostream>
using namespace std;

// 假设aDst有足够的内存存储两个数组合并后的结果
void MergeSortedArray(int dst[], int src[],  int dstLength , int srcLength)
{
    int iSrc = srcLength - 1;
    int iDst = dstLength - 1;
    int iTarget = srcLength + dstLength - 1;
    while(iSrc >= 0 && iDst >= 0)
    {
        dst[iTarget--] = src[iSrc] > dst[iDst] ? src[iSrc--] : dst[iDst--];
    }
    while(iSrc >= 0)
    {
        dst[iTarget--] = src[iSrc--];
    }

}

int main()
{
    int a[10] = {3,5, 6};
    int b[4] = {2, 2, 4, 8};
    for(int i = 0; i<10; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    MergeSortedArray(a, b, 3, 4);

    for(int i = 0; i<10; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

}