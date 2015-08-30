#include<iostream>
using namespace std;

/*
	实现strtok，理解其中其中的实现以及static变量的使用，以记录相应的位置
	参考网站：
		http://www.cppblog.com/yinquan/archive/2009/06/01/86411.html
*/

char*  my_strtok (char* string_org, const char* demial)
{
	static unsigned char* last; //保存分隔后剩余的部分
	unsigned char* str;         //返回的字符串
	const unsigned char* ctrl = (const unsigned char*)demial;//分隔字符
	//把分隔字符放到一个索引表中。定义32是因为ASCII字符表最多是0~255个，也是说用最大的255右移3位，
	//也就是除以8一定会是32中的一个数。

	unsigned char map[32]; 

	int count;

	//把map全部清为0，之后相与的操作，与0的都为0

	for (count =0; count <32; count++)
    {
		map[count] = 0;
    }
	//把匹配字符放入表中
	//放入的算法是把匹配字符右移3位，相当于除以8，的数值 并上(加上)
	//匹配字符与7，得到低3位，得出的结果，是把1左移的位数。最大左移位数是7，也就是所表示的最大值是128,    
	do 
    {
		map[*ctrl >> 3] |= (1 << (*ctrl & 7));
    } while (*ctrl++);
	//原始字符串是否为空，如果为空表示第二次获取剩余字符的分隔部分。    
	if (string_org)
    {
		str = (unsigned char*)string_org;
    } 
	else
    {
		str = last;
    }
	//在表中查找是否有匹配的字符，如果有略过    
	while ((map[*str >> 3] & (1 << (*str & 7)))  && *str)
    {
		str++;
    }
	//重置需要扫描的字符串    
	string_org = (char*)str;
	//开始扫描
	for (;*str; str++)
    {
		if ( map[*str >> 3] & (1 << (*str & 7)))
	    {
			*str++ = '\0';//当找到时，把匹配字符填为0，并且把str指向下一位。	
			break; //退出循环             
	   }		  
    }   
	last =str; // 把剩余字符串的指针保存到静态变量last中。
	if (string_org == (char*)str)
	{
		return NULL; //没有找到，也就是没有移动指针的位置，返回NULL
	}
	else
	{
		return string_org; //找到了，返回之前字符串的头指针
	}
}

int main()
{
	char sentence[]="This is a sentence with 7 tokens test haha bucuo ";
    cout << "The string to be tokenized is:\n" << sentence << "\n\nThe tokens are:\n\n";
    char *tokenPtr=my_strtok(sentence," ");
    while(tokenPtr != NULL) {
        cout<< tokenPtr <<'\n';
        tokenPtr = my_strtok(NULL," ");
    }
    //cout << "After strtok,sentence=" << tokenPtr<<endl;
    return 0;
	
		
}
