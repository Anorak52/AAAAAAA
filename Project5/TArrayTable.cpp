#include "TArrayTable.h"

TKey TArrayTable::GetKey(TDataPos mode) const
{
	int pos = -1;
	if (!IsEmpty())
	{
		switch (mode)
		{
		case FIRST_POS: pos = 0; break;
		case LAST_POS: pos = DataCount - 1; break;
		default: pos = CurrPos; break;
		}
	}
	return (pos == -1) ? string("") : mas[pos]->Key;
}
PTDatValue TArrayTable::GetValuePTR(TDataPos mode) const
{
	int pos = -1;
	if (!IsEmpty())
	{
		switch (mode)
		{
		case FIRST_POS: pos = 0; break;
		case LAST_POS: pos = DataCount - 1; break;
		default: pos = CurrPos; break;
		}
	}
	return (pos == -1) ? NULL : mas[pos]->pValue;

}
TKey TArrayTable::GetKey(void) const { return GetKey(CURRENT_POS); }

PTDatValue TArrayTable::GetValuePTR() const { return GetValuePTR(CURRENT_POS); }
int TArrayTable::Reset(void)
{
	CurrPos = 0;
	return IsTabEnded();
}
int TArrayTable::IsTabEnded(void) const
{
	return CurrPos >= DataCount;
}
int TArrayTable::GoNext(void)
{
	if (!IsTabEnded()) CurrPos++;
	return IsTabEnded();
}
int TArrayTable::SetCurrentPos(int pos)
{
	CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
	return IsTabEnded();
}