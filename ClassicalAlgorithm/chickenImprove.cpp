/*
�����㷨��1�� ��Ǯ��ټ�
����5��Ǯһֻ��ĸ��3��Ǯһֻ��С��3ֻһ��Ǯ��
��100��Ǯ��һ��ֻ��,���й�����ĸ����С��������Ҫ�У��ʹ�����ĸ����С��Ҫ�����ֻ�պô���100��Ǯ��
*/

#include<iostream>
using namespace std;

void calAnimals_1()
{
	for(int x=1; x<20; x++) // O��n^2��
	{
		for(int y=1; y<33; y++)
		{
			int z = 100-x-y;
			if((z%3==0) && (x*5 + y*3 + z/3 == 100))
			{
				cout << "������" << x << " ֻ��ĸ����" << y << " ֻ��С����" << z << "ֻ" << endl;
			}
		}
	}
}

void calAnimals_2() // �Ż������� O(n)
{
	for(int k = 1; k <4; k++)
	{
		int x = 4 * k;
		int y = 25 - 7 * k;
		int z = 75 + 3 * k;
		cout << "������" << x << "  ĸ����" << y << "  С����" << z << endl;
	}
	
	
}

int main()
{
	calAnimals_1();
	cout << "--------------------------------------" << endl;
	calAnimals_2();
	return 0;
}