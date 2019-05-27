#ifndef _TSORTTABLE_H
#define _TSORTTABLE_H
#include "TScanTable.h"
enum TSortMethod { INSERT_SORT, MERGE_SORT, QUICK_SORT };
class TSortTable : public TScanTable {
protected:
	TSortMethod SortMethod; // метод сортировки
	void SortData(void); // сортировка данных
	void InsertSort(PTTabRecord *pMem, int DataCount); // метод вставок

	//void MergeSort(PTTabRecord *pMem, int DataCount); // метод слияния
	//void MergeSorter(PTTabRecord * &pData, PTTabRecord * &pBuff, int Size);
	//void MergeData(PTTabRecord *&pData, PTTabRecord *&pBuff, int n1, int n2);
	//void QuickSort(PTTabRecord *pMem, int DataCount); // быстрая сортировка
	//void QuickSplit(PTTabRecord *pData, int Size, int &Pivot);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) { SortData(); };// конструктор
	TSortTable(const TScanTable &tab); // из просматриваемой таблицы
	TSortTable & operator=(const TScanTable &tab); // присваивание
	virtual void InsRecord(TKey k, PTDatValue pVal);
	//TSortMethod GetSortMethod(void); // получить метод сортировки
	//void SetSortMethod(TSortMethod sm);// установить метод сортировки
									   // основные методы
	virtual bool Find(TKey k) {
		Efficiency=0;
		int first = 0, last = (DataCount - 1), mid = 0;
		while (first <= last) {
			Efficiency++;
			mid = (first + last) / 2;
			if (mas[mid]->Key == k) {
				CurrPos = mid;
				return true;
			}
			if (mas[mid]->Key < k) {
				first = (mid + 1);
			}
			else {
				last = (mid - 1);
			}
		}
		CurrPos = first;
		return false;
	} // найти запись

	/*virtual void InsRecord(TKey k, PTDatValue pVal) // вставить
	{
		if (IsFull()) SetRetCode(TabFull);
		else {
			PTDatValue temp = FindRecord(k);
			if (RetCode == TabOk) SetRetCode(TabRecDbl);
			else {
				SetRetCode(TabOk);
				for (int i = DataCount; i > CurrPos; i--) mas[i] = mas[i - 1];
				mas[CurrPos] = new TTabRecord(k, pVal);
				DataCount++;
			}
		}
	}*/
	//virtual void DelRecord(TKey k); // удалить запись
};
#endif