#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib> // exit()
using namespace std;

class String
{
public:
	String(const char *pstr=NULL);
	String(const String& other);
	~String();
	String& operator=(const String& other);

	String operator+(const String& other);
	int size();
	// int capacity();
	String subStr(int start, int end);
	
	bool operator==(const String& other);
	friend ostream& operator<<(ostream& out, const String& other);
	
private:
	char *m_data;
};


String::String(const char *pstr) // 主要在定义是不要加上形参默认值
{
	if(pstr == NULL) 
	{
		m_data = new char[1];
		if(m_data == NULL)
			exit(-1);
		*m_data = '\0';
	}
	else
	{
		int len = strlen(pstr);
		m_data = new char[len+1];
		if(m_data == NULL)
			exit(-1);
		strcpy(m_data, pstr);	
	}
}

String::String(const String& other)
{
	int len = strlen(other.m_data);
	m_data = new char[len+1];
	if(m_data ==NULL)
		exit(-1);
	strcpy(m_data, other.m_data);
}

String::~String()
{
	if(NULL != m_data)
	{
		delete m_data;
		m_data = NULL;
	}
}

String& String::operator=(const String& other)
{
	if(m_data != other.m_data)
	{
		String strTemp(other);
		char *pWant = strTemp.m_data;
		strTemp.m_data = m_data;
		m_data = pWant;
	}
	return *this;
}

String String::operator+(const String& other)
{
	String ret;
	delete[] ret.m_data; // 这就是前面为什么new char[1];的原因，同一delete[]来释放即可
	ret.m_data = new char[(strlen(m_data) + strlen(other.m_data) + 1)];
	if(m_data == NULL)
		exit(-1);
	strcpy(ret.m_data, m_data);
	strcpy(ret.m_data+strlen(m_data), other.m_data);
	return ret;
}

int String::size()
{
	return strlen(m_data);
}

String String::subStr(int start, int end)
{
	assert(start>=0 && end>=0);
	String ret;
	if(end > start)
	{
		delete[] ret.m_data;
		ret.m_data = new char[end - start+1];
		if(ret.m_data == NULL)
			exit(-1);
		for(int i=0; i+start < end; i++)
		{
			ret.m_data[i] = m_data[start+i];
		}
		ret.m_data[end-start] = '\0';
	}
	return ret;
}


bool String::operator==(const String& other)
{
	return strcmp(m_data, other.m_data) == 0;
}

ostream& operator<<(ostream& out, const String& other)
{
	out << other.m_data;
	return out;
}



void test()
{
	String s = "abcd";
	String t = "abcd";
	cout << s << (s==t ?" == ":" != ") << t << endl;
	
	String s2 = "Hello";
	String s3 = "China";
	cout << s2 + s3 << endl;
	cout << (s2+s3).subStr(0, s2.size() + s3.size()) << endl;
	cout << (s2+s3).subStr(4, 5) << endl;
	
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