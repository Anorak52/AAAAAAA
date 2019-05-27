#include "TDataCom.h"
#include "TDatValue.h"
#include "TTabRecord.h"
#include "TTable.h"
#include "TArrayTable.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "TArrayHash.h"

#include "Math.h"
#include "stdlib.h"
#include "time.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string word[10] = { "111","123","aaaa","fd","14", "xg", "10", "uysf", "15447", "hxhff" };
	int array[10] = { 1,2,3,1,2,4,2,5,1,2 };
	TSortTable B(100);
	TArrayHash A(100);
	TScanTable TMP(100);
	cout << "scan"<<TMP.GetTabSize();
	//cout << "sort"<<B.GetTabSize();
	int eff = 0;

	for (int i = 0; i < 10; i++)
	{
		B.InsRecord(word[i], (PTDatValue)&array[i]);
		TMP.InsRecord(word[i], (PTDatValue)&array[i]);
		A.InsRecord(word[i], (PTDatValue)&array[i]);
	}
	//TSortTable B(TMP);
	int number = 0;
	while (number != 4)
	{
		cin >> number;

		switch (number)
		{
		case 1:
		{

			int eff = 0;
			PTDatValue p = (PTDatValue)&eff;
			//TRecord rec;
			//TMP.Read("Text.txt");
			//A.Read("Text.txt");

			//eff = TMP.GetEfficiency();
			cout << TMP.GetDataCount();

			cout << "ScanTable:" << endl << endl;
			TMP.Print();

			/*cout << endl;
			cout << "Эффективность вставки " << TMP.GetDataCount() << " записей = " << TMP.GetEfficiency() << " (в среднем =  " << ((float)TMP.GetEfficiency() / (float)TMP.GetDataCount()) << ")" << endl;

			eff = TMP.GetEfficiency();

			cout << "SortTable: " << endl;

			cout << "ScanTable после удаления: (осталось " << TMP.GetDataCount() << " записей)" << endl;
			TMP.Print();*/
			PTDatValue p1 = TMP.FindRecord("Q");
			if (p1)
				cout << "Нашли";
			else cout << "Не Нашли";
			cout << "Эффективность поиска =  " << TMP.GetEfficiency() << endl;
			p1 = TMP.FindRecord("111");
			if (p1)
				cout << "Нашли";
			else cout << "Не Нашли";
			cout << "Эффективность поиска =  " << TMP.GetEfficiency() << endl;

			break; }
		///////////////////////////////////////////////////////////////

		case 2: {
			/*TSortTable B(100);
			TScanTable TMP(100);
			int eff = 0;
			string word[10] = { "111","123","aaaa","fd","14", "xg", "10", "uysf", "15447", "hxhff" };
			int array[10] = { 1,2,3,1,2,4,2,5,1,2 };
			for (int i = 0; i < 10; i++)
			{
				B.InsRecord(word[i], (PTDatValue)&array[i]);
				TMP.InsRecord(word[i], (PTDatValue)&array[i]);
			}*/
			//B.InsRecord("222", (PTDatValue)&array[1]);
			/*TMP.Read("Text.txt");
			B.Read("Text.txt");*/
			//eff = B.GetEfficiency();

			cout << B.GetDataCount();

			cout << "SortTable:" << endl << endl;
			B.Print();

			cout << endl;
			//cout << "Эффективности:\n";
			//cout << "Эффективность вставки " << B.GetDataCount() << " записей = " << B.GetEfficiency() << " (в среднем =  " << ((float)B.GetEfficiency() / (float)B.GetDataCount()) << ")" << endl;

			//eff = B.GetEfficiency();
			
			
			bool p1=	B.Find("q");
				
			if (p1)
				cout << "Нашли";
			else cout << "Не Нашли";
			cout << "Эффективность поиска =  " << B.GetEfficiency() << endl;
			p1 = B.Find("111");
			if (p1)
				cout << "Нашли";
			else cout << "Не Нашли";
			cout << "Эффективность поиска =  " << B.GetEfficiency() << endl;

		//	cout << "Эффективность поиска =  " << B.GetEfficiency() << endl;

			
			cout << endl;
			break;
		}
		case 3: {
			cout << A.GetDataCount();
			cout << "HashTable:" << endl << endl;
			A.Print();
			/*for (A.Reset(); !A.IsTabEnded();A.GoNext())
			{
				PTDatValue pp = A.GetValuePTR();
				int *pi = (int*)pp;
				//cout << "***" << endl;

				cout << A.GetKey() << "  -  " << *pi << endl;
			}*/
			PTDatValue p1 = A.FindRecord("Q");
			if (p1)
				cout << "Нашли";
			else cout << "Не Нашли";
			cout << "Эффективность поиска =  " << A.GetEfficiency() << endl;
			p1 = A.FindRecord("111");
			if (p1)
				cout << "Нашли";
			else cout << "Не Нашли";
			cout << "Эффективность поиска =  " << A.GetEfficiency() << endl;
			cout << endl;
			break;
		}
				/*cout << endl;
				int zzz;
				cin >> zzz;*/
				//break;
		}
	}
}