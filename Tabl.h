#pragma once
#include "vec.h"
class Tabl {
	vec v;
	T* cur;
public:
	Tabl(int sz = 10);
	~Tabl(); T* begin(); T* end();
	int length();
	
		int getSize(); T* insert(const
			T& item);
	T* erase(
		T* pos);
	void clear();
	int remove(const
		T& item);
	int find(const
		T& item);
	int replace(const
		T& Old, const
		T& New);
	void sort();
	int Input(
		T buf);
	void Output();
};