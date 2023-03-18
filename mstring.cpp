#include "mstring.h"
#include<string.h>

mstring::mstring() : array(nullptr)
{
	array = new char[1];
	array[0] = '\0';
};

mstring::mstring(size_t size) : array{ new char[size + 1] } {};

mstring::mstring(const mstring& orig) :
	array(orig.array)
{
	array = new char(strlen(orig.array) + 1);
	strcpy_s(array, strlen(orig.array) + 1, orig.array);
	array[strlen(orig.array)] = '\0';
}

mstring::mstring(const char* s)
{
	if (s == nullptr) 
	{
		array = new char[1];
		array[0] = '\0';
	}
	else
	{
		array = new char[strlen(s) + 1];
		strcpy_s(array, strlen(s) + 1, s);
		array[strlen(s)] = '\0';
	}
	
}

std::ostream& operator<<(std::ostream& os, const mstring& str)
{
	os << str.array;
	return os;
}

mstring& mstring::operator=(const mstring& right)
{
	if (this == &right)
		return *this;

	if (array != nullptr)
		delete[] array;

	array = new char[strlen(right.array) + 1];
	strcpy_s(array,strlen(right.array) + 1, right.array);
	return *this;
}

mstring& mstring::operator+=(const mstring& source)
{
	char* temp = new char[strlen(array) + 1];
	strcpy_s(temp, strlen(array) + 1, array);

	delete[] array;
	array = new char[strlen(temp) + strlen(source.array) + 1];
	
	for (size_t i = 0; i < strlen(temp); i++)
		array[i] = temp[i];

	for (size_t i = 0; i < strlen(source.array); i++)
		array[strlen(temp) + i] = source.array[i];

	
	array[strlen(temp) + strlen(source.array)] = '\0';

	delete[] temp;
	return *this;
}

char& mstring::operator[](int i)
{
	if (i > strlen(array) - 1)
	{
		std::cout << "there is no index like this";
	}
	else
	{
		return array[i];
	}
}

int mstring::Size()
{
	return strlen(array);
}

mstring::~mstring()
{
	if (array != nullptr)
		delete[] array;
}

void mstring::check()
{
	mstring s1("cos");
	mstring s2;
	s2 = s1;
	s2 += s1;
	for (int i = 0; i < s2.Size(); i++)
		std::cout << s2[i];
	std::cout << std::endl << s1;
	
}