#include "TArrayHash.h"

TArrayHash::TArrayHash(int Size, int Step)
{
	TabSize = Size;
	HashStep = Step;
	mas = new PTTabRecord[Size];
	//Curr = -1;
	CurrPos = 0;
	for (int i = 0; i < TabSize; i++)
		mas[i] = NULL;
	pMark = new TTabRecord(string(""), NULL);
}

int TArrayHash::IsFull() const
{
	return DataCount >= TabSize;
}

TKey TArrayHash::GetKey(void) const
{
	return ((CurrPos < 0) || (CurrPos >= TabSize)) ? string("") : mas[CurrPos]->Key;
}

PTDatValue TArrayHash::GetValuePTR(void) const
{
	return ((CurrPos < 0) || (CurrPos >= TabSize)) ? NULL : mas[CurrPos]->pValue;
}

PTDatValue TArrayHash::FindRecord(TKey k)
{
	PTDatValue pValue = NULL;
	FreePos = -1; Efficiency = 0;
	CurrPos = HashFunc(k) % TabSize;
	for (int i = 0; i < TabSize; i++)
	{
		Efficiency++;
		if (mas[CurrPos] == NULL) break;
		else if (mas[CurrPos]==pMark)
		{
			if (FreePos == -1) FreePos = CurrPos;
		}
		else if (mas[CurrPos]->Key==k)
		{
			pValue = mas[CurrPos]->pValue; break;
		}
		CurrPos = GetNextPos(CurrPos);
	}
	return pValue;
}

void TArrayHash::InsRecord(TKey k, PTDatValue pVal)
{
	if (IsFull()) SetRetCode(TabFull);
	else {
		PTDatValue temp = FindRecord(k);
		if (temp != NULL) SetRetCode(TabRecDbl);
		else {
			if (FreePos != -1) CurrPos = FreePos;
			mas[CurrPos] = new TTabRecord(k, pVal);
			DataCount++;
		}
	}
}

void TArrayHash::DelRecord(TKey k)
{
	PTDatValue temp = FindRecord(k);
	delete mas[CurrPos];
	mas[CurrPos] = pMark;
	DataCount--;
}

int TArrayHash::Reset(void)
{
	CurrPos = 0;
	while (CurrPos < TabSize)
		if ((mas[CurrPos] != NULL) && (mas[CurrPos] != pMark)) break;
		else CurrPos++;
	return IsTabEnded();
}

int TArrayHash::IsTabEnded(void) const
{
	return CurrPos >= TabSize;
}

int TArrayHash::GoNext(void)
{
	if (!IsTabEnded()) {
		while (++CurrPos < TabSize)
			if ((mas[CurrPos] != NULL) && (mas[CurrPos] != pMark)) break;
	}
	return IsTabEnded();
}


