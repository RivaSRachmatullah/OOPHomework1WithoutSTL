#include <iostream>
#include "DateTime.h"

using namespace std;

void mainmenu();

/* PROGRAM UTAMA */
int main () {
	DateTime DT1, DT2;
	Date D;
	Time T;
	int pilihan;
	cin >> DT1 >> DT2;
	do {
		cout << endl << "DT1 : " << DT1 << endl;
		cout << "DT2 : " << DT2 << endl;
		mainmenu();
		cout << "Pilihan anda : ";
		cin >> pilihan;
		switch (pilihan) {
			case 1	:	do {
							cout << "Masukkan tanggal yang diinginkan : ";
							cin >> D;
							cout << "Masukkan waktu yang diinginkan : ";
							cin >> T;
						} while (!DateTime::IsDTValid(D,T));
						DT1.SetTanggal(D);
						DT1.SetWaktu(T);
						break;
			case 2	:	do {
							cout << "Masukkan tanggal yang diinginkan : ";
							cin >> D;
							cout << "Masukkan waktu yang diinginkan : ";
							cin >> T;
						} while (!DateTime::IsDTValid(D,T));
						DT1.SetTanggal(D);
						DT1.SetWaktu(T);
						break;
			case 3	:	if (DT1 == DT2)
							cout << "true" << endl;
						else
							cout << "false" << endl;
						break;
			case 4	:	if (DT1 < DT2)
							cout << "true" << endl;
						else
							cout << "false" << endl;
						break;
			case 5	:	if (DT1 > DT2)
							cout << "true" << endl;
						else
							cout << "false" << endl;
						break;
			case 6	: 	break;
			default	:	cout << "Input salah" << endl;
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
	cout << "4. IsSmaller?" << endl;
	cout << "5. IsBigger?" << endl;
	cout << "6. Exit" << endl;
}

