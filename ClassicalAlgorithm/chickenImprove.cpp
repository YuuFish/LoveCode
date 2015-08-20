/*
经典算法题1： 百钱买百鸡
公鸡5文钱一只，母鸡3文钱一只，小鸡3只一文钱，
用100文钱买一百只鸡,其中公鸡，母鸡，小鸡都必须要有，问公鸡，母鸡，小鸡要买多少只刚好凑足100文钱。
*/

#include<iostream>
using namespace std;

void calAnimals_1()
{
	for(int x=1; x<20; x++) // O（n^2）
	{
		for(int y=1; y<33; y++)
		{
			int z = 100-x-y;
			if((z%3==0) && (x*5 + y*3 + z/3 == 100))
			{
				cout << "公鸡：" << x << " 只，母鸡：" << y << " 只，小鸡：" << z << "只" << endl;
			}
		}
	}
}

void calAnimals_2() // 优化的做法 O(n)
{
	for(int k = 1; k <4; k++)
	{
		int x = 4 * k;
		int y = 25 - 7 * k;
		int z = 75 + 3 * k;
		cout << "公鸡：" << x << "  母鸡：" << y << "  小鸡：" << z << endl;
	}
	
	
}

int main()
{
	calAnimals_1();
	cout << "--------------------------------------" << endl;
	calAnimals_2();
	return 0;
}