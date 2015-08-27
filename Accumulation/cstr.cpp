#include<iostream>
#include<cassert>
#include<cstring>

using namespace std;

void *my_memcpy(void *dst, const void *src, size_t count) // 这也是memmove的实现了
{
	assert((dst != NULL) && (src != NULL));
	if(dst == src)
		return dst;
	// 不能对boid*指针进行算数运算，所以强制类型转换为char*,进行逐个字节的copy
	if(dst<src || (char*)dst >= ((char*)src+count)) 
	{
		char *p = (char*)dst;
		char * q = (char*)src;
		while(count--)
		{
			*p++ = *q++;
		}
	}
	else
	{
		char *p = (char*)dst + count;
		char *q = (char*)src + count;
		while(count--)
		{
			*--p = *--q;
		}
	}
	return dst;
		
}

int my_strlen(const char *str)
{
	assert(str != NULL);
	int len = 0;
	while(*str++ != '\0')
	{
		++len;
	}
	return len;
}


int my_strlen_recurse(const char *str) // 递归实现，不用借助其它变量
{
	assert(str != NULL);
	return *str == '\0' ? 0 : (1+my_strlen_recurse(++str));
}

int my_strcmp(const char *strLeft, const char *strRight)
{
	assert(strLeft  != NULL);
	assert(strRight != NULL);
	while(*strLeft && *strRight && *strLeft == *strRight)
	{
		++strLeft;
		++strRight;
	}
	int ret = *strLeft - *strRight;
	if(ret > 0)
		ret = 1;
	else if(ret < 0)
		ret = -1;
	else 
		ret = 0;
	return ret;
}


char *my_strcat(char *dst, const char *src)
{
	assert((dst != NULL) && (src != NULL));
	char *ret = dst;
	while(*dst != '\0')
	{
		dst++;
	}
	while((*dst++ = *src++) != '\0' );
	return ret;
}

/* strstr() 函数搜索一个字符串在另一个字符串中的第一次出现。找到所搜索的字符串，则该函数返回第一次匹配的字符串的地址；
如果未找到所搜索的字符串，则返回NULL。
*/
char *my_strstr (const char *str1, const char *str2)
{
	assert((str1 != NULL) && (str2 != NULL));
	char *cp = (char *) str1;
	char *s1, *s2;

	if ( !*str2 )
		return((char *)str1);

	while (*cp)
	{
		s1 = cp;
		s2 = (char *) str2;

		while ( *s1 && *s2 && (*s1==*s2) )
			s1++, s2++;

		if (!*s2)
			return(cp);

		cp++;
	}

	return(NULL);

}


char *my_strcpy(char *dst, const char *src)
{
	if(dst == src)
	{
		return dst;
	}
	assert(dst != NULL);
	assert(src != NULL);
	
	char *ret = dst;
	int count = my_strlen(src)+1;
	// int count = my_strlen_recurse(src)+1;
	
	if (dst <= src || dst >= (src + count)) 
	{
		/*
		 * Non-Overlapping Buffers
		 * copy from lower addresses to higher addresses
		 */
		while((*dst++=*src++)!='\0');
	}
	else 
	{
		/*
		 * Overlapping Buffers
		 * copy from higher addresses to lower addresses
		 */
		dst = dst + count;
		src = src + count;

		while (count--)
		{
			*--dst = *--src;
		}
	}
	
	return ret;
}



int main()
{	
	char a1[6]="Hello";

	cout << a1 << endl;
	char a2[10]={0};
	cout << "a1= " << a1 << endl;
	cout << "a2= " << a2 << endl;
	cout << "before copy-----\n";
	my_strcpy(a1+2, a1);
	// strcpy(a1+2, a1);
	my_strcpy(a2, a1);
	cout << "after copy\n";
	cout << "a1= " << a1 << endl; // HeHello
	cout << "a2= " << a2 << endl; // HeHello
	
	cout << "--------strcmp Test-------------" << endl;
	cout << my_strcmp("Hello", "Hello WORLD") << endl;
	cout << strcmp("Hello", "Hello WORLD") << endl;
		
	cout << my_strcmp("Hello", "hELLO") << endl;
	cout << strcmp("Hello" , "hELLO") << endl;
	
	cout << my_strcmp("Hello WORLD", "Hello") << endl;
	cout << strcmp("Hello WORLD", "Hello") << endl;
	
	cout << my_strcmp("abc", "abc") << endl;
	cout << strcmp("abc", "abc") << endl;
	
	// cout << my_strcmp(NULL, " ") << endl;
    // cout << strcmp(NULL, " ") << endl;
	
	cout << "---------------------" << endl;
	
	cout << "----------strcat Test-----------------" << endl;
	char s1[15] = "Hello";
	// strcat(s1, " Worldfefegagag");
	my_strcat(s1, " World");
	// strcat(s1, " World");
	// my_strcat(s1, " Worldfefegagag");
	cout << s1 << endl;
	cout << "--------------------------------------" << endl;
	
	cout << "----------------memcpy TEST-------------" << endl;
	char s2[12] = {0};
	const char *s3 = "Hello";
	// memcpy(s2, s3, strlen(s3)+1);
	my_memcpy(s2, s3, strlen(s3)+1);
	cout << "s3= " << s3 << " " << "s2= " << s2 << endl;
	
	char s4[10] = "Hello";
	cout << "before: s4= " << s4 << endl;
	// memcpy(s4+3, s4, strlen(s4)+1);
	my_memcpy(s4+2, s4, strlen(s4)+1);
	cout << "aftet copy:s4= " << s4 << endl;
	cout << "---------------------------------------------------" << endl;
	
	
	cout << "---------------------strstr test---------------------------\n";
	// char *strFind = strstr("HeHello", "l");
	char *strFind = my_strstr("HeHello", "l");  // llo
	cout << "test" << endl;
	cout << strFind << endl; //llo 注意：cout<< (char*)NULL,后面的所有输出语句都没效果,cout << NULL;// 则输出一个0
	cout << 13  << endl;
	cout << "----------------------test End-----------------------------" << endl;
	
	
	return 0;
	
}


















