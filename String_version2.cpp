#include<iostream>
#include<string.h>
#include<cstdlib> // exit()



/*
* to be improved by my own strcpy, strlen, strcmp 
* 实现说明： 实现说明：字符串类String的简单实现，内部采用字符数组实现
* 经验说明：经验说明：拷贝构造函数、重载赋值运算符、实现析构函数三个操作在实现自定义类时往往同时出现。
* 参考资料： http://rsljdkt.iteye.com/blog/774188 , 《剑指offer》
*/

using namespace std;

class String
{
public:
	String(const char *str=NULL);
	String(const String &other);
	~String(void);
	String& operator=(const String &other);
	bool operator==(const String &str);
	friend ostream& operator<<(ostream &o, const String &str);
	
	String operator+(const String &str);
	int Length();
	String SubStr(int start, int end);
	
	
private:
	char *m_data;
};

/*
	构造，拷贝构造，析构， operator=, operator==, operator<<
*/

String::String(const char *str)
{
	if(NULL == str)
	{
		m_data = new char[1];
		if(NULL == m_data)
		{
			cout << "allocate memory failed" << endl;
			exit(-1);
		}
		*m_data = '\0';
	}
	else
	{
		int len = strlen(str);
		m_data = new char[len +1];
		strcpy(m_data, str);
	}
	
}

String::String(const String &other)
{
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
}

String::~String(void)
{
	if(m_data != NULL)
	{
		delete[] m_data;
		m_data = NULL;
	}
}

String& String::operator=(const String &other)
{
	/*
	if(this != &other)
	{
		delete[] m_data;
		int len = strlen(other.m_data);
		m_data = new char[len + 1];
		strcpy(m_data, other.m_data);
	}
	*/
	if(this != &other)
	{
		String strTemp(other); // 考虑到异常安全性，使用临时变量，再交换临时变量实例和原来的实例，
		// 确保当内存分配失败时String原来的内容不被修改，因为new分配不足，会抛出诸如bad_allo等异常；
		
		char *pTemp = strTemp.m_data;
		strTemp.m_data = m_data;
		m_data = pTemp;
	}
	return *this;
}

bool String::operator==(const String &str)
{
	return strcmp(m_data, str.m_data) == 0;
}


ostream& operator<<(ostream &o, const String &str)
{
	o << str.m_data;
	return o;
}

String String::operator+(const String &str)
{
	String ret;
	delete[] ret.m_data; // 释放原空间
	ret.m_data = new char[strlen(m_data) + strlen(str.m_data) + 1];
	strcpy(ret.m_data, m_data);
	strcpy(ret.m_data + strlen(m_data), str.m_data);
	return ret;
	
}

int String::Length()
{
	return strlen(m_data);
}

String String::SubStr(int start, int end)
{
	String ret;
	if(end > start)
	{
		delete[] ret.m_data; // 释放原有空间
		ret.m_data = new char[end-start+1]; // 重新申请内存
		for(int i=0; i+start < end; i++)
		{
			ret.m_data[i] = m_data[start+i];
		}
		// 最后占了一个空字符，所以对于start, end的关系是含头不含尾，start, end对应的也是索引号，从0开始
		ret.m_data[end-start] = '\0'; 
	}
	return ret;
}



void test()
{
	String s = "abcd";
	String t = "abcd";
	cout << s << (s==t ?" == ":" != ") << t << endl;
	
	String s2 = "Hello";
	String s3 = "China";
	cout << s2 + s3 << endl;
	cout << (s2+s3).SubStr(0, s2.Length() + s3.Length()) << endl;
	cout << (s2+s3).SubStr(4, 5) << endl;
	
	String s4;
	String s5;
	s4 = s5 = s2 = s;
	cout << "s4= " << s4 << endl;
	cout << "s5= " << s5 << endl;
	cout << "s2= " << s2 << endl;
	
	
}



int main()
{
	String s1 = "hello test";
	String s2 = s1; // 隐式调用拷贝构造函数
	String s3 = "hello test";
	String s4("stringDemo"); // 显式调用拷贝构造函数
	String s5(s4);
	String s6;
	String s7 =s6;
	cout << "s1= " << s1 << endl;
	cout << "s2= " << s2 << endl;
	cout << "s4= " << s4 << " s5= " << s5 << endl;
	cout << "s6= " << s6 << endl;
	cout << "s7= " << s7 << endl;
	cout << (s1 == s3) << endl;
	
	cout << "------------------------------\n";
	test();
	cout << "------------------------------" << endl;
	
	return 0;
}
