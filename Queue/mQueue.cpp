/* Nama File	: mQueue.cpp										*/
/* Deskripsi	: DRIVER ADT QUEUE									*/

/*	File Include */
#include "Queue.h"
#include <iostream>

/*	Header Prosedur dan Fungsi */
void menu();

using namespace std;

/*	Program Utama */
int main() {
	/* Kamus */
	int MaxEl,opt;
	infotype X,Y;
	bool exit=false;
	/* Algoritma */
	cout << "Panjang Queue = ";
	cin >> MaxEl;
	Queue *Q = new Queue(MaxEl);
	do {
		menu();
		cin >> opt;
		switch (opt) {
			case 1 	: 	if (Q->IsEmpty()) {
							cout <<"Queue kosong.\n";
						} else {
							cout << "Queue tidak kosong.\n";	
							cout << "Jumlah elemen = " << Q->Count() << endl;
							cout << "Jumlah maksimum elemen = " << Q->MaxEl() << endl;
						}
						cout << endl;
						break;
			case 2 	:	if (Q->IsFull()) {
							cout << "Queue penuh.\n";
						} else {
							cout << "Queue tidak penuh.\n";	
							cout << "Jumlah elemen = " << Q->Count() << endl;
							cout << "Jumlah maksimum elemen = " << Q->MaxEl() << endl;
						}
						cout << endl;
						break;
			case 3	: 	cout << "Masukkan masukan yang mau ditambah ke queue = ";
						cin >> X;
						Q->Add(X);
						cout << "\n";
						break;
			case 4	:	Y = Q->Del();
						cout << "elemen : " << Y << endl;
						cout << "\n";
						break;
			case 5	:	cout << *Q;
						break;
			case 6	:	cout << "Bye.\n";
						exit=true;
						break;
		}
	} while (!exit);
	delete Q;
}

/*	Realisasi Prosedur dan Fungsi */
void menu() {
	/* Kamus */
	/* Algoritma */
	cout << "1. Cek Kosong\n";
	cout << "2. Cek Penuh\n";
	cout << "3. Cek void Add\n";
	cout << "4. Cek void Del\n";
	cout << "5. Print Queue\n";
	cout << "6. Exit\n";
	cout << "\n";
	cout <<"Pilihan = ";
}