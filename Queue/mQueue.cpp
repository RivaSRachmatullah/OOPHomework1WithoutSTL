/* Nama File	: mQueue.cpp										*/
/* Deskripsi	: DRIVER ADT QUEUE									*/

/*	File Include */
#include "Queue.h"
#include <iostream>

/*	Header Prosedur dan Fungsi */
void Menu();

using namespace std;

/*	Program Utama */
int main() {
	/* Kamus */
	int MaxEl,opt;
	int X,Y;
	bool exit=false;
	/* Algoritma */
	cout << "Panjang Queue = ";
	cin >> MaxEl;
	Queue *Q = new Queue(MaxEl);
	do {
		Menu();
		cin >> opt;
		switch (opt) {
			case 1 	: 	if (Q->IsQueueEmpty()) {
							cout <<"Queue kosong.\n";
						} else {
							cout << "Queue tidak kosong.\n";	
							cout << "Jumlah elemen = " << Q->Effective() << endl;
							cout << "Jumlah maksimum elemen = " << Q->Size() << endl;
						}
						cout << endl;
						break;
			case 2 	:	if (Q->IsQueueFull()) {
							cout << "Queue penuh.\n";
						} else {
							cout << "Queue tidak penuh.\n";	
							cout << "Jumlah elemen = " << Q->Effective() << endl;
							cout << "Jumlah maksimum elemen = " << Q->Size() << endl;
						}
						cout << endl;
						break;
			case 3	: 	cout << "Masukkan masukan yang mau ditambah ke queue = ";
						cin >> X;
						Q->Enqueue(X);
						cout << "\n";
						break;
			case 4	:	Y = Q->Dequeue();
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
void Menu() {
	cout << "1. Cek Kosong\n";
	cout << "2. Cek Penuh\n";
	cout << "3. Add\n";
	cout << "4. Del\n";
	cout << "5. Print Queue\n";
	cout << "6. Exit\n";
	cout << "\n";
	cout <<"Pilihan = ";
}