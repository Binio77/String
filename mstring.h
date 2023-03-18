#pragma once
#include<iostream>
class mstring
{
private:
	char* array;
	friend std::ostream& operator<<(std::ostream& os, const mstring& str);
public:
	mstring();
	mstring(size_t _size);
	mstring(const mstring& orig);
	mstring(const char* s);
	mstring& operator=(const mstring& right);
	mstring& operator+=(const mstring& source);
	char& operator[](int i);
	int Size();
	~mstring();
	void check();
};

