#ifndef _TTABLE_H
#define _TTABLE_H
#include <string>
#include "TDataCom.h"
#include "TDatValue.h"
#include "TTabRecord.h"
#define TabOk 0 // ошибок нет
#define TabEmpty -101 // таблица полна
#define TabFull -102 // таблица пуста
#define TabNoRec -103 // нет записи
#define TabRecDbl -104 // дублирование памяти
#define TabNoMem -105 // нет памяти

using namespace std;

typedef string TKey;
typedef int TValue;


class TTable : public TDataCom {
protected:
	int DataCount; // количество записей в таблице
	int Efficiency; // показатель эффективности выполнения операции
public:
	TTable() { DataCount = 0; Efficiency = 0; } // конструктор
	virtual ~TTable() {}; // деструктор
	// информационные методы
	int GetDataCount() const { return DataCount; } // к-во записей
	int GetEfficiency() const { return Efficiency; } // эффективность
	int IsEmpty() const { return DataCount == 0; } //пуста?
	virtual int IsFull() const = 0; // заполнена?
	// доступ
	virtual TKey GetKey(void) const = 0;
	virtual PTDatValue GetValuePTR() const = 0;
	// основные методы
	//virtual PTDatValue FindRecord(string k) = 0; // найти запись
	//virtual bool Find(TKey key) = 0;
	virtual void InsRecord(TKey k, PTDatValue pVal) = 0; // вставить
	virtual void DelRecord(TKey k) = 0; // удалить запись
	// навигация
	virtual int Reset(void) = 0; // установить на первую запись
	virtual int IsTabEnded(void) const = 0; // таблица завершена?
	virtual int GoNext(void) = 0; // переход к следующей записи
	// (=1 после применения для последней записи таблицы)
	//virtual TRecord GetCurr() const = 0;

	void Print() {
		for (Reset(); !IsTabEnded(); GoNext())
		{
			cout << "***" << endl;
			///cout << GetCurr().key << "  -  " << GetCurr().val << endl;
		}
	}

	// Чтение из файла
	void Read(char* pFileName)
	{
		string str = "";
		ifstream TxtFile(pFileName);

		//от 65 до 90 коды буквенных клавиш
		//32 - пробел
		for (int i = 0; i < str.length(); i++)
		{
			char tmp = str[i];
			if (((int)tmp >= 65) && ((int)tmp <= 90))
			{
				tmp += 32;
			}
			str[i] = tmp;
		}

		string tmp = "";
		//TRecord rec;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				//key = tmp;
				//rec.val = 1;
				//InsRecord(rec);
				tmp = "";
			}
			else
			{
				tmp += str[i];
			}
		}
	}
};
#endif