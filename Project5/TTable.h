#ifndef _TTABLE_H
#define _TTABLE_H
#include <string>
#include "TDataCom.h"
#include "TDatValue.h"
#include "TTabRecord.h"
#define TabOk 0 // ������ ���
#define TabEmpty -101 // ������� �����
#define TabFull -102 // ������� �����
#define TabNoRec -103 // ��� ������
#define TabRecDbl -104 // ������������ ������
#define TabNoMem -105 // ��� ������

using namespace std;

typedef string TKey;
typedef int TValue;


class TTable : public TDataCom {
protected:
	int DataCount; // ���������� ������� � �������
	int Efficiency; // ���������� ������������� ���������� ��������
public:
	TTable() { DataCount = 0; Efficiency = 0; } // �����������
	virtual ~TTable() {}; // ����������
	// �������������� ������
	int GetDataCount() const { return DataCount; } // �-�� �������
	int GetEfficiency() const { return Efficiency; } // �������������
	int IsEmpty() const { return DataCount == 0; } //�����?
	virtual int IsFull() const = 0; // ���������?
	// ������
	virtual TKey GetKey(void) const = 0;
	virtual PTDatValue GetValuePTR() const = 0;
	// �������� ������
	//virtual PTDatValue FindRecord(string k) = 0; // ����� ������
	//virtual bool Find(TKey key) = 0;
	virtual void InsRecord(TKey k, PTDatValue pVal) = 0; // ��������
	virtual void DelRecord(TKey k) = 0; // ������� ������
	// ���������
	virtual int Reset(void) = 0; // ���������� �� ������ ������
	virtual int IsTabEnded(void) const = 0; // ������� ���������?
	virtual int GoNext(void) = 0; // ������� � ��������� ������
	// (=1 ����� ���������� ��� ��������� ������ �������)
	//virtual TRecord GetCurr() const = 0;

	void Print() {
		for (Reset(); !IsTabEnded(); GoNext())
		{
			cout << "***" << endl;
			///cout << GetCurr().key << "  -  " << GetCurr().val << endl;
		}
	}

	// ������ �� �����
	void Read(char* pFileName)
	{
		string str = "";
		ifstream TxtFile(pFileName);

		//�� 65 �� 90 ���� ��������� ������
		//32 - ������
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