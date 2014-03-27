#include <iostream>
#include "Date.h"

using namespace std;

void mainmenu();

/* PROGRAM UTAMA */
int main () {
	Date D1, D2;
	int pilihan;
	cin >> D1 >> D2;
	do {
		cout << endl << "D1 : " << D1 << endl;
		cout << "D2 : " << D2 << endl;
		mainmenu();
		cout << "Pilihan anda : ";
		cin >> pilihan;
		switch (pilihan) {
			case 1	:	int D,M,Y;
						do {
							cout << "Masukkan hari yang diinginkan : ";
							cin >> D;
							cout << "Masukkan bulan yang diinginkan : ";
							cin >> M;
							cout << "Masukkan tahun yang diinginkan : ";
							cin >> Y;
						} while (!Date::IsTanggalValid(D,M,Y));
						D1.SetDay(D);
						D1.SetMonth(M);
						D1.SetYear(Y);
						break;
			case 2	:	do {
							cout << "Masukkan hari yang diinginkan : ";
							cin >> D;
							cout << "Masukkan bulan yang diinginkan : ";
							cin >> M;
							cout << "Masukkan tahun yang diinginkan : ";
							cin >> Y;
						} while (!Date::IsTanggalValid(D,M,Y));
						D2.SetDay(D);
						D2.SetMonth(M);
						D2.SetYear(Y);
						break;
			case 3	:	if (D1 == D2)
							cout << "true" << endl;
						else
							cout << "false" << endl;
						break;
			case 4	:	if (D1 < D2)
							cout << "true" << endl;
						else
							cout << "false" << endl;
						break;
			case 5	:	if (D1 > D2)
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
	cout << "1. Ubah Tanggal, Bulan, dan Tahun pada D1" << endl;
	cout << "2. Ubah Tanggal, Bulan, dan Tahun pada D2" << endl;
	cout << "3. IsEqual?" << endl;
	cout << "4. IsSmaller?" << endl;
	cout << "5. IsBigger?" << endl;
	cout << "6. Exit" << endl;
}

