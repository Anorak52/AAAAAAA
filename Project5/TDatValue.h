#ifndef _TDATVALUE_H
#define _TDATVALUE_H
class TDatValue {
public:
	virtual TDatValue * GetCopy() = 0; // �������� �����
	~TDatValue() {}
};
typedef TDatValue* PTDatValue;
#endif;