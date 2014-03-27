/**\class Teller
 *
 * \brief Class Teller
 *
 * Class ini digunakan untuk merepresentasikan bentuk antrian sejumlah N-antrian
 * dengan N yang akan ditentukan kemudian.
 * Berisi tentang prosedur dan fungsi yang diakses untuk mengelola antrian.
 *
 * \note Class belum Generic
 *
 * $Author: Riva Syafri Rachmatullah (.h and .cpp) <br>Indam Muhammad (generic type) $
 *
 * \version 1.0 $Revision: 1.0 $
 *
 * $Date: 2014/03/21 00:55:55 $
 *
 * Contact		:	<br>13512026@std.stei.itb.ac.id
 *					<br>13512036@std.stei.itb.ac.id
 *
 * Created on	: 15 Maret 2014 19:00:00
 *
 */

#include <iostream>
using namespace std;

#ifndef TELLER_H
#define TELLER_H

#include "../Queue/Queue.h"
#include <iostream>

using namespace std;

class Teller{
public:
	/// Constructor (CTOR)
	/**	<br>I.S.	: Bebas
	 *	<br>F.S. 	: Sebuah variabel dengan tabel memori queue berjumlah 5
	 *	<br>Proses 	: Membuat sebuah variabel berclass Teller dengan alokasi memori sebanyak 5 Queue
	 *			 dengan pemanggilan Queue menggunakan Constructor default.
	 */
	Teller();

	/// Constructor Parameter (CTORPARAM)
	/**	<br>I.S.	: N terdefinisi
	 *	<br>F.S. 	: Sebuah variabel dengan tabel memori queue berjumlah N
	 *	<br>Proses 	: Membuat sebuah variabel berclass Teller dengan alokasi memori sebanyak N Queue
	 *			 dengan pemanggilan Queue menggunakan Constructor default.
	 */
	Teller(int N);

	/// Copy Constructor (CCTOR)
	/**	<br>I.S.	: T terdefinisi
	 *	<br>F.S. 	: Sebuah variabel dengan tabel memori queue berjumlah T.N dan memiliki isi yang
	 *			 sama dengan T.
	 *	<br>Proses 	: Membuat sebuah variabel berclass Teller dengan alokasi memori sebanyak T.N
	 *			 dengan pemanggilan Queue menggunakan Constructor default yang lalu isi dari T disalin
	 *			 isinya ke variabel itu.
	 */
	Teller(const Teller &T);

	/// Destructor (DTOR)
	/**	<br>Proses 	: Mengembalikan memori T
	 *	<br>I.S.	: Objek berclass Teller ada
	 *	<br>F.S.	: Objek dihapus dari memori dengan tabel penyimpanan didealokasi
	 */
	~Teller();

	/// Operator Overloading '='
	/**	<br>I.S.	: T terdefinisi
	 *	<br>F.S. 	: Sebuah variabel dengan tabel memori queue berjumlah T.N dan memiliki isi yang
	 *			 sama dengan T.
	 *	<br>Proses 	: Membuat sebuah variabel berclass Teller dengan alokasi memori sebanyak T.N
	 *			 dengan pemanggilan Queue menggunakan Constructor default yang lalu isi dari T disalin
	 *			 isinya ke variabel itu.
	 */
	Teller& operator=(const Teller &T);
	
	/// Operasi Pencarian dan Penghapusan Elemen
	/**	Fungsi yang melakukan penghapusan elemen pada queue tertentu sesuai dengan input id
	 * yang diberikan.
	 *	<br>Proses 	: Mencari Queue yang memiliki elemen yaitu id di HEAD yang lalu memanggil fungsi Del pada Queue itu.
	 *	<br>I.S.	: Variabel berclass Queue yang memiliki id di HEAD tidak mungkin kosong
	 *	<br>F.S.	: elemen id pada Queue yang memilikinya akan menjadi "return value"
	 */
	infotype SearchThenDel(int id);
	
	/// Operasi Pencarian dan Penambahan Elemen
	/**	Prosedur yang melakukan penambahan elemen pada queue tertentu
	 *	<br>Proses 	: Mencari Queue terpendek yang lalu memanggil prosedur Add pada Queue itu.
	 *	<br>I.S.	: Variabel berclass Teller mungkin memiliki semua Queue kosong dan tabel penampung elemen untuk semua Queue TIDAK penuh 
	 *	<br>F.S.	: Queue terpendek akan bertambah elemennya dengan id berada di paling belakang barisan 
	 */
	void SearchThenAdd(int id);
	
	/// Operasi Penghapusan Semua Elemen
	/**	Prosedur yang melakukan penghapusan elemen pada queue sesuai urutan yang lalu menuliskan ke layar
	 *	elemen-elemen yang dihapus.
	 *	<br>Proses 	: Memanggil fungsi Del pada setiap Queue hingga seluruh Queue kosong
	 *	<br>I.S.	: Teller memiliki Queue yang boleh kosong untuk semua Queue
	 *	<br>F.S.	: Seluruh Queue kosong
	 */
	void EndDel();

	/// Prosedur Tulis
	/** Prosedur untuk menuliskan variabel T berclass Teller ke layar 
	 *	<br>I.S.	: T terdefinisi
	 *	<br>F.S.	: Nilai T ditulis ke layar dengan format 
	 *	<br>       Q[1] = {..,..,..,..}
	 *	<br>	   Q[2] = {..,..,..,..} dst
	 *	<br>Proses	: Menulis semua elemen dari Queue yang ada di T ke layar
	 */
	void Print();


	/// Fungsi Jockey
	/** Fungsi Jockeying menghasilkan j yaitu nomor Queue tujuan (jika terjadi jockeying)
	 *	atau -1 (jika tidak terjadi jockeying)
	 *	Syarat terjadinya jockeying adalah ada queue lain yang lebih pendek dengan 
	 *	selisih lebih dari 2 elemen dengan mensimulasikan pelanggan yang berpindah dari 
	 *	Q[iOrigin] ke Q[j] (jika ada) dengan j != iOrigin dan NbElmt(j) paling minimum.
	 *	Jika terdapat lebih dari satu Q[j] dengan NbElmt(j) minimum, pilih j 
	 *	yang paling dekat dengan iOrigin dan j yang memiliki indeks lebih kecil.
	 */
	int Jockeying (int iOrigin);
		

private:
	int N;
	Queue *Q;
	bool *QEmpty;
};

#endif

