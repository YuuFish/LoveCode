#include <stdio.h>

void println(int array[], int len)
{
    int i = 0;
    
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    
    array[i] = array[j];
    
    array[j] = temp;
}

void SelectionSort(int array[], const int len) // O(n*n)
{
	if(NULL != array && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			int min = i;
			for(int j = i+1; j< len; j++)
			{
				if(array[j] < array[min])
					min = j;
			}
			swap(array, min, i);
		}
	}
}

int main()
{
    int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array); 
    
    println(array, len);
    
    SelectionSort(array, len);
    
    println(array, len);
    
    return 0;
}
