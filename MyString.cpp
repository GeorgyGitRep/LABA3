#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
MyString::MyString()
{
	s = new char[1];
	*s = '\0';
	len = 0;
}
MyString::MyString(char*
	t)
{
	
		s = new char[strlen(
			t) + 1];
	*s = '\0'; strcpy(s,
		t);
	len = strlen(
		t);
}
MyString::MyString(const MyString&
	u)
{
	s = new char
		[
			u.len + 1];
	*s = '\0'; strcpy(s,
		u.s);
	len =
		u.len;
}
MyString::~MyString()
{
	delete[] s;
}
char& MyString::item(int
	t)
{
	char err = 'e';
	if (
		t <= len &&
		t >= 0)
		return s[
			t];
	else
		cout << "Error.";
	return err;
}
MyString* MyString::copy()
{
	return new MyString(*this);
}
void MyString::assign(const MyString&
	u)
{
	s = new char
		[
			u.len + 1];
	*s = '\0'; strcpy(s,
		u.s);
	len =
		u.len;
}
int MyString::cmp(const MyString&
	t)
{
	return strcmp(s,
		t.s);
}
int MyString::equal(const MyString&
	t)
{
	return strcmp(s,
		t.s) == 0;
}
int MyString::input()
{

	char buf1[256];
	cin.getline(buf1, 254, '\n');
	if (strlen(buf1) == 0) cin.getline(buf1, 254, '\n');
	if (cin.eof())return 0;
	
		s = new char[strlen(buf1) + 1]; len = strlen(buf1);
	*s = '\0';
	strcpy(s, buf1);
	return 1;
}
int MyString::output() {
	cout << s << endl;
	return 0;
}