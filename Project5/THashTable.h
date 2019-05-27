#ifndef _THASHTABLE_H
#define _THASHTABLE_H


#include "TTable.h";
class THashTable : public TTable {
protected:
	virtual unsigned long HashFunc(const TKey key); // hash-функция
public:
	THashTable() : TTable() {} //конструктор
};

#endif // !_THASHTABLE_H
