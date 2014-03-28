#include <iostream>
#include "DateTime.h"

using namespace std;

void mainmenu();

/* PROGRAM UTAMA */
int main () {
	Date D;
	Time T;
	DateTime DT1, DT2;
	cin >> DT1 >> DT2;
	int pilihan;
	do {
		cout << endl << "DT1 : " << DT1 << endl;
		cout << "DT2 : " << DT2 << endl;
		mainmenu();
		cout << "Pilihan anda : ";
		cin >> pilihan;
		switch (pilihan) {
			case 1	:	
				cout << "Date : ";
				cin >> D;
				cout << "Time : ";
				cin >> T;
				DT1.SetDate(D);
				DT1.SetTime(T);
				break;
			case 2	:
				cout << "Date : ";
				cin >> D;
				cout << "Time : ";
				cin >> T;
				DT2.SetDate(D);
				DT2.SetTime(T);
				break;
			case 3	:
				if (DT1 == DT2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 4	:
				if (DT1 < DT2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 5	:
				if (DT1 > DT2)
					cout << "true" << endl;
				else
					cout << "false" << endl;
				break;
			case 6	: 
				break;
			default	:
				cout << "Input salah" << endl;
				break;
		}
	} while (pilihan != 6);
	return 0;
}

void mainmenu() {
	cout << endl << "-----------------------------------" << endl;
	cout << "1. Ubah Tanggal dan Waktu pada DT1" << endl;
	cout << "2. Ubah Tanggal dan Waktu pada DT2" << endl;
	cout << "3. IsEqual?" << endl;
	cout << "4. IsEarlierThan?" << endl;
	cout << "5. IsLaterThan?" << endl;
	cout << "6. Exit" << endl;
}

