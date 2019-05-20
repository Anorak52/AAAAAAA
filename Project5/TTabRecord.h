#ifndef _TTABRECORD_H
#define _TTABRECORD_H
#include <iostream>
#include "TDatValue.h"
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

typedef string TKey; // тип ключа записи
					// †ласс объектов-значений дл§ записей таблицы
class TTabRecord : public TDatValue {
protected: // пол§
	TKey Key; // ключ записи
	PTDatValue pValue; // указатель на значение
public: // методы
	TTabRecord(TKey k = "", PTDatValue pVal = NULL);// конструктор

	void SetKey(TKey k) { Key = k; }// установить значение ключа
	TKey GetKey(void) { return Key; } // получить значение ключа
	void SetValuePtr(PTDatValue p) { pValue = p; }// установить указатель на данные
	PTDatValue GetValuePTR(void) { return pValue; } // получить указатель на данные
	virtual TDatValue * GetCopy() // изготовить копию
	{
		TDatValue* temp = (PTDatValue)new TTabRecord(Key, pValue);
		return temp;
	}
	TTabRecord & operator = (TTabRecord &tr)// присваивание
	{
		Key = tr.Key; pValue = tr.pValue;
		return *this;
	}
	virtual int operator == (const TTabRecord &tr) { return Key == tr.Key; } // сравнение =
	virtual int operator < (const TTabRecord &tr) { return Key > tr.Key; } // сравнение А<њ
	virtual int operator > (const TTabRecord &tr) { return Key < tr.Key; } // сравнение А>њ
protected:
	virtual void Print(ostream& os) { os << Key << " " << pValue; }
	//дружественные классы дл§ различных типов таблиц, см. далее
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TTreeNode;
	friend class TTreeTable;
	friend class TArrayHash;
	friend class TListHash;
};
typedef TTabRecord* PTTabRecord;
#endif