#include "TSortTable.h"


TSortTable::TSortTable(const TScanTable & tab)
{
	*this = tab;

}

TSortTable & TSortTable::operator=(const TScanTable & tab)
{
	if (mas != NULL)
	{
		for (int i = 0; i < DataCount; i++) delete mas[i];
		delete[] mas; mas = NULL;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	mas = new PTTabRecord[TabSize];
	for (int i = 0; i < DataCount; i++)
		mas[i] = (PTTabRecord)tab.mas[i]->GetCopy();
	SortData();
	CurrPos = 0;
	return *this;
}

void TSortTable::InsRecord(TKey k, PTDatValue pVal)

{
if (IsFull()) SetRetCode(TabFull);
else
{	//PTDatValue
bool temp = Find(k);
	//if (RetCode == TabOk) SetRetCode(TabRecDbl);
if (temp);
	else
	{
		SetRetCode(TabOk);
		for (int i = DataCount; i > CurrPos; i--) mas[i] = mas[i - 1];
		mas[CurrPos] = new TTabRecord(k, pVal);
		DataCount++;
	}
}
}

void TSortTable::SortData(void)
{
	Efficiency = 0;
	InsertSort(mas, DataCount); // включение
	
	
}

void TSortTable::InsertSort(PTTabRecord * pMem, int DataCount)
{
	PTTabRecord pR;
	Efficiency = DataCount;
	for (int i = 1, j; i < DataCount; i++)
	{
		pR = mas[i];
		for (j = i - 1; j > -1; j--)
			if (mas[j]->Key > pR->Key)
			{
				mas[j + 1] = mas[j]; // сдвиг вправо
				Efficiency++;
			}
			else break;
		mas[j + 1] = pR; // вставка
	}
}

//void TSortTable::MergeSort(PTTabRecord * pMem, int DataCount)
//{
//	PTTabRecord* pData = mas;
//	PTTabRecord*  pBuff = new PTTabRecord[DataCount];
//	PTTabRecord* pTemp = pBuff;
//	MergeSorter(pData, pBuff, DataCount);
//	if (pData == pTemp) // сортированные данные находятся в буфере
//		for (int i = 0; i < DataCount; i++) pBuff[i] = pData[i];
//	delete pTemp;
//}
//
//void TSortTable::MergeSorter(PTTabRecord *& pData, PTTabRecord *& pBuff, int Size)
//{
//	int n1 = (Size + 1) / 2;
//	int n2 = Size - n1;
//	if (Size > 2)
//	{
//		PTTabRecord* pData2 = pData + n1, *pBuff2 = pBuff + n1;
//		MergeSorter(pData, pBuff, n1);
//		MergeSorter(pData2, pBuff2, n2);
//	}
//	MergeData(pData, pBuff, n1, n2); // слияние упорядоч
//}
//
//void TSortTable::MergeData(PTTabRecord *& pData, PTTabRecord *& pBuff, int n1, int n2)
//{
//
//}
//
//void TSortTable::QuickSort(PTTabRecord * pMem, int DataCount)
//{
//	int pivot; // ведущий элемент
//	int n1, n2; // размеры разделенных блоков данных
//	if (DataCount > 1)
//	{
//		QuickSplit(mas, DataCount, pivot); // разделение
//		n1 = pivot + 1;
//		n2 = DataCount - n1;
//		QuickSort(mas, n1 - 1); // сортировка разделенных
//		QuickSort(mas + n1, n2);
//	}
//}
//
//void TSortTable::QuickSplit(PTTabRecord * pData, int Size, int & Pivot)
//{
//}
