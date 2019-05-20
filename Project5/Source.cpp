#include "TDataCom.h"
#include "TDatValue.h"
#include "TTabRecord.h"
#include "TTable.h"
#include "TArrayTable.h"
#include "TScanTable.h"
//#include "TSortTable.h"


#include "Math.h"
#include "stdlib.h"
#include "time.h"

using namespace std;

int main()
{

	TScanTable A(1000), TMP(1000);
	int eff = 0;
	string word[10]={"111","123","aaaa"};
	int array[10] = { 1,2,3,1,2,4,2,5,1,2 };
	PTDatValue p = (PTDatValue)&eff;
	//TRecord rec;
	//TMP.Read("Text.txt");
	//A.Read("Text.txt");
	A.InsRecord(word[2], (PTDatValue)&array[0]);
	A.InsRecord("222", (PTDatValue)&array[1]);
	eff = A.GetEfficiency();

	cout << "ScanTable:" << endl << endl;
	A.Print();

	cout << endl;
	cout << "Ёффективность вставки " << A.GetDataCount() << " записей = " << A.GetEfficiency() << " (в среднем =  " << ((float)A.GetEfficiency() / (float)A.GetDataCount()) << ")" << endl;

	eff = A.GetEfficiency();
	/*for (int i = 0; i < 100; i++)
	{
		rec = TMP.GetMas((rand() % TMP.GetDataCount()));
		A.Find(rec.key);
	}
	cout << "Ёффективность поиска =  " << ((float)(A.GetEff() - eff) / 100) << endl;


	eff = A.GetEff();
	for (int i = 0; i < 100; i++)
	{
		rec = TMP.GetMas((rand() % TMP.GetDataCount()));
		A.Delete(rec.key);
		TMP.Delete(rec.key);
	}
	cout << "Ёффективность удалени¤ = " << ((float)(A.GetEff() - eff) / 100) << endl << endl;*/
	cout << "ScanTable после удалени¤: (осталось " << A.GetDataCount() << " записей)" << endl;
	A.Print();

	cout << endl;
	int zzz;
	cin >> zzz;
	//break;
}