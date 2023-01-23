#include "Tabl.h"
Tabl::Tabl(int sz) :v(sz) {
	cur = v.begin();
}
Tabl::~Tabl()
{
	clear();

} T* Tabl::begin() {
	return v.begin();
} T* Tabl::end() { return cur; }
int Tabl::length() { return cur - begin(); }
int Tabl::getSize() { return v.get_size(); } T* Tabl::insert(const T& item)
{
	int sz = getSize();
	if (length() >= sz)v.resize(2 * sz);
	*cur++ = item->copy();
	return cur;
} T* Tabl::erase(	T* pos)
{
	T* i;
	(*pos)->dispose();
	for (i = pos; i < cur; i++)
		*i = *(i + 1);
	cur--;
	return pos;
}
void Tabl::clear()
{
	T* i;
	for (i = begin(); i < cur; i++)
	{
		(*i)->dispose();
		delete (*i);
		
	}
	cur = begin();
}
int Tabl::remove(const
	T& item)
{
	T* i, * j = begin(); int n = 0;
	for (i = begin(); i < cur; i++)
		if (!(*i)->equal(*item))
			*j++ = *i;
		else { (*i)->dispose(); n++; }
	cur = j;
	return n;
}
int Tabl::find(const
	T& item)
{
	T* i;
	for (i = begin(); i < cur; i++)
		if ((*i)->equal(*item)) return i - begin();
	return -1;
}
int Tabl::replace(const
	T& Old, const
	T& New)
{
	T* i; int count = 0;
	for (i = begin(); i < cur; i++)
		if ((*i)->equal(*Old))
		{
			(*i)->dispose();
			(*i) = (New)->copy();
			count++;
		}
	return count;
}
void Tabl::sort() {
	int i, j, len = length();
	for (j = 0; j < len - 1; j++)
		for (i = 0; i < len - 1 - j; i++)
			if (v.item(i)->cmp(*v.item(i + 1)) > 0)
			{

				T tmp = v.item(i);
				v.item(i) = v.item(i + 1);
				v.item(i + 1) = tmp;
			}
}
int Tabl::Input(
	T buf)
{
	int count;
	for (count = 0; count < getSize() && buf->input(); count++)
		insert(buf);
	return count;
}
void Tabl::Output()
{
	
		T * i;
	for (i = begin(); i != end(); i++)
		(*i)->output();
}