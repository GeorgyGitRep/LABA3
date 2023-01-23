#pragma once
#include "Product.h"
class vec
{
	T* v;
	int size;
public:
	T* begin() { return v; };
	T* end() { return v + size; }
	int get_size() { return size; }
	vec();
	~vec();
	vec(int sz);
	vec(const vec&);
	T& item(int);
	void resize(int);
};

