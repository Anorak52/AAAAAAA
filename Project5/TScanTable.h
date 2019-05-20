#ifndef _TSCANTABLE_H
#define _TSCANTABLE_H
#include "TTabRecord.h"

#include "TArrayTable.h"


class TScanTable : public TArrayTable {
public:
	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {}//конструктор
	// основные методы

	PTDatValue FindRecord(TKey _key)
	{
		for (int i = 0; i < DataCount; i++) {
			Efficiency++;
			if (mas[i]->GetKey() == _key) {
				CurrPos = i;
				return mas[i]->GetValuePTR();
			}
		}
		CurrPos = DataCount;
		return NULL;
	}

	virtual void InsRecord(TKey k, PTDatValue pVal)
	{
		//virtual void Insert(TRecord rec) {
		if (IsFull()) return;
		if (!FindRecord(k)) {
			mas[CurrPos] = new TTabRecord(k, pVal);
			DataCount++;
			Efficiency++;
		}
		else
		{
			mas[CurrPos]->GetValuePTR();// val++;
		}
	}

	virtual void DelRecord(TKey _key) {
		if (FindRecord(_key)) {
			DataCount--;
			Efficiency++;
			mas[CurrPos] = mas[DataCount];
		}
	}
};

#endif