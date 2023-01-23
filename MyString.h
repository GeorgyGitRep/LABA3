#pragma once
#include <iostream>
using namespace std;
class MyString {
	char* s;
	int len;
public:
	MyString();
	MyString(const MyString&);
	MyString(char*);
	~MyString();
	int length() { return len; }
	int length() const
	{
		return len;
	}
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&);
	int equal(const MyString&);
	int input();
	int output();
};
