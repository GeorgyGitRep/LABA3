#pragma once
#include <iostream>
#include "MyString.h"
#include "MyDate.h"
class Product
{
	// ��������
	MyString name;	
	long count; // ����������� �����
	double price; // ����
	MyDate date;
public:
	Product();
	Product(char* a,  int n, int p, int d, int m, int y);
	Product(const Product&);
	~Product(); // ����������� ���������� ������ ��� �������� Record
	Product* copy();
	void dispose() {}
	int equal(Product&); // �������, ����������� ��������� �������� ����� �������.������������ ��� ������
		int cmp(Product&); // �������, ������������ ������ ������������ ��� 	����������
		int input();
	void output();
	
};
typedef Product* T;