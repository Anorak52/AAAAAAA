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
	PTTabRecord * mas;// ������ ��� ������� �������
	int TabSize; // ����. ����.���������� ������� � �������
	int CurrPos; // ����� ������� ������ (��������� � 0)
public:
	TArrayTable(int Size = TabMaxSize) // �����������
	{
		mas = new PTTabRecord[Size];
		for (int i = 0; i < Size; i++) mas[i] = NULL;
		TabSize = Size; DataCount = CurrPos = 0;
	}
	~TArrayTable() {
		for (int i = 0; i < DataCount; i++)
			delete mas[i];
		delete[] mas;
	}// ����������
	// �������������� ������

	virtual int IsFull() const // ���������?
	{
		return DataCount >= TabSize;
	}
	int GetTabSize() const // �-�� �������
	{
		return TabSize;
	}
	// ������
	virtual TKey GetKey(TDataPos mode) const;
	virtual TKey GetKey(void) const;
	virtual PTDatValue GetValuePTR(TDataPos mode) const; // ��������� �� ��������
	virtual PTDatValue GetValuePTR() const;


	// �������� ������
	virtual PTDatValue FindRecord(TKey k) = 0; // ����� ������
	virtual void InsRecord(TKey k, PTDatValue pVal) = 0; // ��������
	virtual void DelRecord(TKey k) = 0; // ������� ������
	//���������
	virtual int Reset(void); // ���������� �� ������ ������
	virtual int IsTabEnded(void) const; // ������� ���������?
	virtual int GoNext(void); // ������� � ��������� ������
	//(=1 ����� ���������� ��� ��������� ������ �������)
	virtual int SetCurrentPos(int pos);// ���������� ������� ������
	int GetCurrentPos(void) const { return CurrPos; }; //�������� ����� ������� ������

	friend class TSortTable;
	friend class TTabRecord;
};

#endif