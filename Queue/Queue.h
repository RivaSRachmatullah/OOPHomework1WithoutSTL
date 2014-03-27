/**\class Queue
 *
 * \brief Class Queue
 *
 * Class ini digunakan untuk merepresentasikan bentuk antrian pada dunia nyata.
 * Berisi tentang prosedur dan fungsi yang diakses untuk mengelola antrian.
 * Definisi Queue kosong: Head = Nil; TAIL = Nil. Catatan implementasi: Q[0] tidak pernah dipakai
 *
 * \note Class belum Generic
 *
 * $Author: Riva Syafri Rachmatullah (.h and .cpp) <br>Indam Muhammad (generic type queue) $
 *
 * \version 1.0 $Revision: 1.2 $
 *
 * $Date: 2014/03/21 00:30:33 $
 *
 * Contact		:	<br>13512026@std.stei.itb.ac.id
 *					<br>13512036@std.stei.itb.ac.id
 *
 * Created on	: 8 Maret 2014 10:00:00
 *
 */

#include <iostream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H
	
/*	PENENTUAN TIPE INFOTYPE DAN ADDRESS */
	typedef int infotype; // untuk elemen
	typedef int address; //	untuk indeks tabel

class Queue{
public:
	/// Constructor (CTOR)
	/**	<br>I.S.	: Bebas
	 *	<br>F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue
	 *	<br>Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak 26
	 */
	Queue();
	
	/// Constructor Parameter (CTORPARAM)
	/**	<br>I.S.	: MaxEl terdefinisi
	 *	<br>F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue sesuai MaxEl+1
	 *	<br>Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak MaxEl+1
	 */
	Queue(int MaxEl);
	
	/// Copy Constructor (CCTOR)
	/*	<br>I.S.	: Q terdefinisi
	 *	<br>F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue sesuai Q.N+1
	 *	<br>Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak Q.N+1
	 */
	Queue(const Queue& Q);
	
	/// Operator Overloading '='
	/*	<br>I.S.	: Q terdefinisi
	 *	<br>F.S. 	: Sebuah variabel kosong terbentuk dengan tabel memori untuk queue sesuai Q.N+1
	 *	<br>Proses 	: Membuat sebuah variabel berclass Queue kosong dengan alokasi memori sebanyak Q.N+1
	 */
	Queue& operator=(const Queue& Q);
	
	/// Destructor (DTOR)
	/**	<br>Proses 	: Mengembalikan memori Q
	 *	<br>I.S.	: Objek berclass Queue ada
	 *	<br>F.S.	: Objek dihapus dari memori dengan tabel penyimpanan didealokasi
	 */
	~Queue();
	

	///	Getter Head
	/** Mengambil alamat head pada variabel berclass Queue */
	address Head();
	
	///	Getter Tail
	/** Mengambil alamat tail pada variabel berclass Queue */
	address Tail();
	
	///	Getter Elemen Head
	/** Mengambil isi dari alamat head pada variabel berclass Queue */
	infotype InfoHead();
	
	///	Getter Elemen Tail
	/** Mengambil isi dari alamat tail pada variabel berclass Queue */
	infotype InfoTail();
	
	///	Getter Panjang Queue
	/** Mengambil N yang ada pada variabel berclass Queue */
	int MaxEl();
	
	/// Pemeriksa kosong tidaknya suatu Queue
	/**	Fungsi yang akan mengirim true apabila Q kosong dan false jika sebaliknya.
	 *	Disebut kosong apabila HEAD dan TAIL berada di indeks array ke-0.
	 */
	bool IsEmpty ();
	
	/// Pemeriksa penuh tidaknya suatu Queue
	/**	Fungsi yang akan mengirim true apabila array penampung elemen Q penuh
	 *	dan false jika sebaliknya.
	 *	Disebut penuh apabila jumlah elemen sama dengan N.
	 */
	bool IsFull ();
	
	/// Penghitung jumlah elemen queue
	/**	Fungsi yang menghitung banyaknya elemen yang ada pada Queue.
	 *	Mengirimkan 0 jika Q kosong. */
	int Count ();
	

	/// Operasi Dasar Add
	/**	Prosedur yang melakukan penambahan elemen pada queue
	 *	<br>Proses 	: Menambahkan X pada variabel berclass Queue dengan aturan FIFO
	 *	<br>I.S.	: Variabel berclass Queue mungkin kosong dan tabel penampung elemen TIDAK penuh 
	 *	<br>F.S.	: X menjadi TAIL yang baru, TAIL "maju".
	 *			  Jika TAIL baru = MaxEl + 1, maka TAIL diset = 1. 
	 */
	void Add (infotype X);
	
	/// Operasi Dasar Delete
	/**	<br>Proses 	: Menghapus elemen pertama pada variabel berclass Queue dengan aturan FIFO 
	 *	<br>I.S.	: Variabel berclass Queue tidak kosong
	 *	<br>F.S.	: X = nilai elemen HEAD pada <br><br>I.S., Jika Queue masih isi : HEAD "maju".
	 *			  Jika HEAD baru menjadi MaxEl + 1, maka HEAD diset = 1;
	 *			  Jika Queue menjadi kosong, HEAD = TAIL = Nil.
	 */
	infotype Del ();
	
	/// Operasi Delete untuk Jockeying
	/**	<br>Proses 	: Menghapus elemen tail pada variabel berclass Queue karena efek jockeying 
	 *	<br>I.S.	: Variabel berclass Queue tidak kosong
	 *	<br>F.S.	: X = nilai elemen TAIL pada <br><br>I.S., Jika Queue masih berisi : TAIL "mundur".
	 *			  Jika TAIL baru menjadi 0, maka TAIL diset = N;
	 *			  Jika Queue menjadi kosong, HEAD = TAIL = Nil.
	 */
	infotype DelJockey();

	/// Operator Tulis
	/** Operator untuk menuliskan variabel Q berclass Queue ke layar 
	 *	<br>I.S.	: Q terdefinisi
	 *	<br>F.S.	: Nilai Q ditulis ke layar dengan format {..,..,..,..}
	 *	<br>Proses	: Menulis semua elemen dari variabel Q ke layar 
	 */
	friend ostream& operator<<(ostream &output, const Queue& Q) {
		if (Q.HEAD != 0) {
			output << "{";
			output << Q.Q[Q.HEAD];
			if (Q.HEAD != Q.TAIL) {
				int i = Q.HEAD+1;
				do {
					output << "," << Q.Q[i];
					i++;
					if (i == Q.N+1) {
						i = 1;
					}
				} while (i != Q.TAIL+1);
			}
			output << "}" << endl;
		} else {
			output << "{}" << endl;
		}
		return output;
	}

private:
	static const int Nil = 0;
	infotype *Q; /* tabel penyimpanan elemen */
	address HEAD; /* alamat penghapusan */
	address TAIL; /* alamat penambahan */
	int N; /* maksimum banyaknya elemen queue */
};

#endif