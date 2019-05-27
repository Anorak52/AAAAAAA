#define TabMaxSize 25
#define TabHashStep 5
#include <string>
#include <iostream>
#include "TTable.h"
#include "THashTable.h"
using namespace std;

class TArrayHash : public THashTable {
protected:
	PTTabRecord *mas; // ������ ��� ������� �������
	int TabSize; // ����. ����. �-�� �������
	int Curr;
	int HashStep; // ��� ���������� �������������
	int FreePos; // ������ ��������� ������, ������������ ��� ������
	int CurrPos; // ������ ������ ��� ���������� ������
	PTTabRecord pMark; // ������ ��� ��������� ����� � ���������� ��������
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; };// ����. �����.
public:
	TArrayHash(int Size = TabMaxSize, int Step = TabHashStep); // �����������
	~TArrayHash()
	{
		delete[] mas;
	};
	// �������������� ������
	virtual int IsFull() const; // ���������?
		// ������
	virtual TKey GetKey(void) const;
	virtual PTDatValue GetValuePTR(void) const;
	// �������� ������
	virtual PTDatValue FindRecord(TKey k); // ����� ������
	virtual void InsRecord(TKey k, PTDatValue pVal); // ��������
	virtual void DelRecord(TKey k); // ������� ������
	// ���������
	virtual int Reset(void); // ���������� �� ������ ������
	virtual int IsTabEnded(void) const; // ������� ���������?
	virtual int GoNext(void); // ������� � ��������� ������
	virtual int GetCurrPos() {
		return CurrPos;
	}
	//(=1 ����� ���������� ��� ��������� ������ �������)
};