#ifndef _TARRAYTABLE_H
#define _TARRAYTABLE_H
#define TabMaxSize 25
#include <string>
#include "TDatValue.h"
#include "TTable.h"

using namespace std;
enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };
class TArrayTable : public TTable {
protected:
	PTTabRecord * mas;// память для записей таблицы
	int TabSize; // макс. возм.количество записей в таблице
	int CurrPos; // номер текущей записи (нумерация с 0)
public:
	TArrayTable(int Size = TabMaxSize) // конструктор
	{
		mas = new PTTabRecord[Size];
		for (int i = 0; i < Size; i++) mas[i] = NULL;
		TabSize = Size; DataCount = CurrPos = 0;
	}
	~TArrayTable() {
		for (int i = 0; i < DataCount; i++)
			delete mas[i];
		delete[] mas;
	}// деструктор
	// информационные методы

	virtual int IsFull() const // заполнена?
	{
		return DataCount >= TabSize;
	}
	int GetTabSize() const // к-во записей
	{
		return TabSize;
	}
	// доступ
	virtual TKey GetKey(TDataPos mode) const;
	virtual TKey GetKey(void) const;
	virtual PTDatValue GetValuePTR(TDataPos mode) const; // указатель на значение
	virtual PTDatValue GetValuePTR() const;


	// основные методы
	virtual PTDatValue FindRecord(TKey k) = 0; // найти запись
	virtual void InsRecord(TKey k, PTDatValue pVal) = 0; // вставить
	virtual void DelRecord(TKey k) = 0; // удалить запись
	//навигация
	virtual int Reset(void); // установить на первую запись
	virtual int IsTabEnded(void) const; // таблица завершена?
	virtual int GoNext(void); // переход к следующей записи
	//(=1 после применения для последней записи таблицы)
	virtual int SetCurrentPos(int pos);// установить текущую запись
	int GetCurrentPos(void) const { return CurrPos; }; //получить номер текущей записи

	friend class TSortTable;
	friend class TTabRecord;
};

#endif