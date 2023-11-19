#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;
//opredelaem strukturu
struct Train
{
	char station[100];
	int number;
	float time;
};
struct Spisok
{
	char Fam[4];
	int Exam[5];
	int Ball[5];
};
int main()
{
	const int n = 4;
	Spisok stud[4]; // sozdaem massiv strok
	int mas[n] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cout << "vvedite familijy: \n";
		cout << "\n";
		cin >> stud[i].Fam;
		cout << "vvedite baly po predmetam: \n";
		cout << "\n";
		cout << "matematika | russkiy yazyk | informatika | literatura | fizra \n";

		for (int j = 0; j < 5; j++)
		{
			cout << "\n";
			cin >> stud[i].Ball[j];
		}
	}

	char namePredmets[5][32];
	strcpy_s(namePredmets[0], "matematika");//Присваиваем namePredmets[0] строку "matematika"
	strcpy_s(namePredmets[1], "fizika");
	strcpy_s(namePredmets[2], "informatika");
	strcpy_s(namePredmets[3], "etika");
	strcpy_s(namePredmets[4], "psihologiya");
	for (int j = 0; j < 5; j++)//j - текущий предмет, 5 - всего предметов
	{
		int badRes = 0, goodRes = 0;

		for (int i = 0; i < n; i++)//i - текущий студент, n - всего студентов
		{
			if ((stud[i].Ball[j] == 4) || (stud[i].Ball[j] == 5))
			{
				goodRes++;
			}
			else
			{
				badRes++;
			}
		}

		cout << namePredmets[j] << ": " << (goodRes * (100 / 4)) << endl;
		//100 / 4, 100 количество процентов (т.е. всегда сто), 4 - количество студентов, 1 студент - 25 процентов от всех студентов
	}

	
	{
		const int s = 3;
		Train t[s];
		int change;
		int n = 0;
		for (int i = 0; i < s; i++)
		{
			cout << "vvedite punkt naznacheniya: ";
			cin >> t[i].station;
			cout << "vvedite nomer poezda: ";
			cin >> t[i].number;
			cout << "vvedite vremya otpravleniya: ";
			cin >> t[i].time;
		}
		while (true) {
			cout << "\n1-vivesti vec spicok" << endl;
			cout << "1-poisk poezda po vremeni" << endl;
			cout << "3-vixod" << endl;
			cout << "viberite destvie: ";
			cin >> change;
			switch (change)
			{
			case 1:cout << "nomer\tvremya\tpunkt naznacheniya" << endl;
				for (int i = 0; i < s; i++)
					cout << t[i].number << "\t" << t[i].time << "\t" << t[i].station << endl; break;
			case 2:float time;
				cout << "vvedite vremya: ";
				cin >> time;
				for (int i = 0; i < s; i++)
				{
					if (time == t[i].time) {
						cout << t[i].station;
						n++;
					}
				}
				if (n == 0)
					cout << "poezda na dannoe vremya net!" << endl; break;
			case 3:exit(0);
			default: cout << "viberite snova!";
			}
		}
	}
	return 0;
}