/**\class DateTime
 *
 * \brief Class DateTime
 *
 * Class ini digunakan untuk merepresentasikan bentuk tanggal dan waktu yang ada 
 * pada dunia nyata. Berisi atribut D yang berclass Date dan T yang berclass TIme
 * dan juga method berupa prosedur dan fungsi untuk membaca dan menuliskan D dan T itu
 *
 * \note Class ini mengelola tanggal dan waktu dalam bentuk HH-MM-YYYY;DD:mm:SS
 *
 * $Author: Riva Syafri Rachmatullah (.h) <br>Indam Muhammad dan Riva Syafri Rachmatullah (.cpp) $
 *
 * \version 1.0 $Revision: 1.2 $
 *
 * $Date: 2014/03/21 00:23:40 $
 *
 * Contact		:	<br>13512026@std.stei.itb.ac.id
 *					<br>13512036@std.stei.itb.ac.id
 *
 * Created on	: 7 Maret 2014 17:30:00
 *
 */

#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include "../Date/Date.h"
#include "../Time/Time.h"
#include <string>
using namespace std;

class DateTime{
public:
	/// Constructor (CTOR)
	/** Berisi inisialisasi awal suatu objek berclass DateTime
	 * dengan memanggil constructor default kelas Date dan Time */
	DateTime();
	
	/// Copy Constructor (CCTOR)
	/** Berisi inisialisasi awal suatu objek berclass DateTime
	 * dengan mengisi D dan T dengan isi D dan T yang ada di DT */
	DateTime(const DateTime& DT);
	
	/// Destructor
	/** Menghapus suatu objek berclass DateTime dari memori */
	~DateTime();
	
	/// Getter Tanggal
	/** Operasi untuk mendapatkan atribut tanggal (D) dalam class DateTime */
	Date Tanggal();
	
	/// Getter Waktu
	/** Operasi untuk mendapatkan atribut waktu (T) dalam class DateTime */
	Time Waktu ();
	
	/// Setter Tanggal
	/** Operasi untuk mengubah atribut hari dalam class DateTime
	 * <br>I.S. = D terdefinisi
	 * <br>Proses = D yang ada di class diubah isinya menjadi D yang ada di parameter
	 * <br>F.S. = D yang ada di class adalah D yang ada di parameter
	 */
	void SetTanggal (Date D);

	/// Setter Waktu
	/** Operasi untuk mengubah atribut hari dalam class DateTime
	 * <br>I.S. = T terdefinisi
	 * <br>Proses = T yang ada di class diubah isinya menjadi T yang ada di parameter
	 * <br>F.S. = T yang ada di class adalah T yang ada di parameter
	 */
	void SetWaktu (Time T);

	/// Pemeriksaan komponen pembuat tanggal dan waktu
	/** Operasi yang memeriksa apakah 2 komponen yang ada pada parameter 
	 * dapat membentuk tanggal dan waktu pada dunia nyata secara valid atau benar */
	static bool IsDTValid (Date D, Time T);
	
	/// Operator ==
	/** Memeriksa apakah suatu variabel berclass DateTime sama dengan DT.
	 * Fungsi ini akan mengembalikan true jika sama atau mengembalikan false jika tidak. */
	bool operator== (DateTime DT);
	
	/// Operator !=
	/** Memeriksa apakah suatu variabel berclass DateTime tidak sama dengan DT.
	 * Fungsi ini akan mengembalikan true jika tidak sama atau mengembalikan false jika sama. */
	bool operator!= (DateTime DT);
	
	/// Operator <
	/** Fungsi ini akan mengembalikan true apabila suatu variabel berclass DateTime 
	 * adalah tanggal dan waktu yang lebih awal daripada DT dan false apabila sebaliknya atau sama dengan DT. */
	bool operator< (DateTime DT);
	
	/// Operator >
	/** Fungsi ini akan mengembalikan true apabila suatu variabel berclass DateTime
	 * adalah tanggal sesudah DT dan false apabila sebaliknya atau sama dengan DT. */
	bool operator> (DateTime DT);

	/// Operator Baca
	/** Operator untuk membaca input user yang lalu dimasukkan ke dalam suatu
	 * variabel berclass DateTime
	 *	<br>I.S.	: Objek DT ada.
	 *	<br>F.S.	: DT berisi DateTime yang valid
	 *	<br>Proses	: Mengulangi membaca komponen D dan T sehingga membentuk DateTime DT
	 *			  yang valid. Tidak mungkin menghasilkan DateTime DT yang tidak valid.
	 */
	friend istream& operator>>(istream &input, DateTime &DT) {
		int H,m,S,D,M,Y;
		char c;
		do {
			input >> D >> c >> M >> c >> Y >> c >> H >> c >> m >> c >> S;
			if (!Date::IsDateValid(D,M,Y) || !Time::IsTimeValid(H,m,S))
				cout << "Input salah" << endl;
		} while (!Date::IsDateValid(D,M,Y) || !Time::IsTimeValid(H,m,S));
		DT.D.SetDay(D);
		DT.D.SetMonth(M);
		DT.D.SetYear(Y);
		DT.T.SetHour(H);
		DT.T.SetMinute(m);
		DT.T.SetSecond(S);
		return input;
	}

	/// Operator Tulis
	/** Operator untuk menuliskan variabel DT berclass DateTime ke layar 
	 *	<br>I.S.	: DT terdefinisi
	 *	<br>F.S.	: Nilai DT ditulis ke layar dengan format DD-MM-YYYY;HH:mm:SS
	 *	<br>Proses	: Menulis nilai setiap komponen dari variabel DT ke layar 
	 */
	friend ostream& operator<<(ostream &output, const DateTime &DT) {
		output << DT.D << ";" << DT.T;
		return output;
	}
	
private:
	Date D;
	Time T;
};

#endif // DATE_H