#include <iostream>
#include "Time.h"

using namespace std;

void mainmenu();

/* PROGRAM UTAMA */
int main () {
	Time T1, T2;
	int pilihan;
	cin >> T1 >> T2;
	do {
		cout << endl << "T1 : " << T1 << endl;
		cout << "T2 : " << T2 << endl;
		mainmenu();
		cout << "Pilihan anda : ";
		cin >> pilihan;
		switch (pilihan) {
			case 1	:	int H,M,S;
						do {
							cout << "Masukkan jam yang diinginkan : ";
							cin >> H;
							cout << "Masukkan menit yang diinginkan : ";
							cin >> M;
							cout << "Masukkan menit yang diinginkan : ";
							cin >> S;
						} while (!Time::IsJamValid(H,M,S));
						T1.SetHour(H);
						T1.SetMinute(M);
						T1.SetSecond(S);
						break;
			case 2	:	do {
							cout << "Masukkan jam yang diinginkan : ";
							cin >> H;
							cout << "Masukkan menit yang diinginkan : ";
							cin >> M;
							cout << "Masukkan detik yang diinginkan : ";
							cin >> S;
						} while (!Time::IsJamValid(H,M,S));
						T2.SetHour(H);
						T2.SetMinute(M);
						T2.SetSecond(S);
						break;
			case 3	:	if (T1 == T2)
							cout << "true" << endl;
						else
							cout << "false" << endl;
						break;
			case 4	:	if (T1 < T2)
							cout << "true" << endl;
						else
							cout << "false" << endl;
						break;
			case 5	:	if (T1 > T2)
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
	cout << "1. Ubah Jam, Menit, dan Detik pada T1" << endl;
	cout << "2. Ubah Jam, Menit, dan Detik pada T2" << endl;
	cout << "3. IsEqual?" << endl;
	cout << "4. IsSmaller?" << endl;
	cout << "5. IsBigger?" << endl;
	cout << "6. Exit" << endl;
}
