#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Product.h";
Product::Product() {
	count = 0;
	price = 0.0;
}
Product::Product(char* a, int n, int p, int d0, int m, int y):name(a), date(d0, m, y),count(n), price(p){ }
Product::Product(const Product& t):name(t.name),count(t.count),price(t.price),date(t.date) {}
Product::~Product(){}
Product* Product::copy()
{
	return new Product(*this);
}
int Product::equal(Product& t) // �������, ����������� ��������� �������� ����� �������. ������������ ��� ������
{
	int a = 1;
	a = a && ((t.price != 0) ? price == t.price : 1);
	a = a && ((t.count != 0) ? count == t.count : 1);
	a = a && ((t.date.get_day() != 0 && t.date.get_month() != 0 && t.date.get_year() != 0) ? date.equal(t.date) : 1);	
	a = a && ((t.name.length() != 0) ? name.equal(t.name) : 1);
	return a;
}
int Product::cmp(Product& t) // �������, ������������ ������ ������������ ��� ����������
{
	int cond;
	MyString s1(t.name);
	if (s1.length() != 0 && (cond = name.cmp(t.name))) return cond;
	else return count - t.count;
}
int Product::input()
{
	cout << "��������: ";
	name.input();
	cout << " ����������� : ";
	cin >> count;
	cout << "����: ";
	cin >> price;
	cout << "���� ���� ����� ���: ";
	date.input();
	return 1;
}
void Product::output()
{
	cout <<	"��������: ";
	name.output();
	cout <<	"����: ";
	cout << price << endl;
	cout <<	"�����: ";
	cout << count << endl;
	cout <<	"���� ���� ����� ���: ";
	date.output();
}