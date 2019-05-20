#ifndef _TTABRECORD_H
#define _TTABRECORD_H
#include <iostream>
#include "TDatValue.h"
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

typedef string TKey; // ��� ����� ������
					// ����� ��������-�������� �� ������� �������
class TTabRecord : public TDatValue {
protected: // ���
	TKey Key; // ���� ������
	PTDatValue pValue; // ��������� �� ��������
public: // ������
	TTabRecord(TKey k = "", PTDatValue pVal = NULL);// �����������

	void SetKey(TKey k) { Key = k; }// ���������� �������� �����
	TKey GetKey(void) { return Key; } // �������� �������� �����
	void SetValuePtr(PTDatValue p) { pValue = p; }// ���������� ��������� �� ������
	PTDatValue GetValuePTR(void) { return pValue; } // �������� ��������� �� ������
	virtual TDatValue * GetCopy() // ���������� �����
	{
		TDatValue* temp = (PTDatValue)new TTabRecord(Key, pValue);
		return temp;
	}
	TTabRecord & operator = (TTabRecord &tr)// ������������
	{
		Key = tr.Key; pValue = tr.pValue;
		return *this;
	}
	virtual int operator == (const TTabRecord &tr) { return Key == tr.Key; } // ��������� =
	virtual int operator < (const TTabRecord &tr) { return Key > tr.Key; } // ��������� �<�
	virtual int operator > (const TTabRecord &tr) { return Key < tr.Key; } // ��������� �>�
protected:
	virtual void Print(ostream& os) { os << Key << " " << pValue; }
	//������������� ������ �� ��������� ����� ������, ��. �����
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