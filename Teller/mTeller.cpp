/* Nama File	: mTeller.cpp										*/
/* Deskripsi	: DRIVER ADT TELLER									*/

/*	File Include */
#include "Teller.h"
#include <iostream>
#include <string>

using namespace std;

/*	Program Utama */
int main() {
	/* Kamus */
	int N;
	cout << "Input jumlah Teller : ";
	cin >> N;
	Teller *T = new Teller(N);
	bool stop = false;
	while (!stop) {
		cout << *T;
		string s;
		cin >> s;
		if (s.compare("Add")==0) {
			int x;
			cin >> x;
			T->SearchThenAdd(x);
		} else if (s.compare("Del")==0) {
			int y;
			cin >> y;
			int x = T->SearchThenDel(y);
			cout << "elemen dihapus : " << x << endl;
		} else if (s.compare("Exit")==0) {
			cout << "Loop terminate" << endl;
			T->EndDel();
			stop = true;
		} else {
			cout << "Error" << endl;
		}
	}
	return 0;
}