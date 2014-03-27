/**\class Date
 *
 * \brief Class Date
 *
 * Class ini digunakan untuk merepresentasikan bentuk tanggal pada dunia nyata.
 * Berisi atribut hari, bulan, dan tahun yang bertipe integer dan juga 
 * method berupa prosedur dan fungsi untuk mengelola tanggal
 *
 * \note Class ini hanya mengelola tanggal dalam bentuk DD-MM-YYYY
 * tanpa waktu
 *
 * $Author: Riva Syafri Rachmatullah (.h) <br>Indam Muhammad dan Riva Syafri Rachmatullah (.cpp) $
 *
 * \version 1.0 $Revision: 1.2 $
 *
 * $Date: 2014/03/20 21:12:25 $
 *
 * Contact		:	<br>13512026@std.stei.itb.ac.id
 *					<br>13512036@std.stei.itb.ac.id
 *
 * Created on	: 7 Maret 2014 17:15:00
 *
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
public:
	/// Constructor (CTOR)
	Date();
	
	/// Copy Constructor (CCTOR)
	Date(const Date& D);
	
	/// Destructor
	~Date();
	
	/// Getter Hari
	int GetDay();
	
	/// Getter Bulan
	int GetMonth();
	
	/// Getter Tahun
	int GetYear();
	
	/// Setter Hari
	/** Operasi untuk mengubah atribut hari dalam class Date
	 * <br>I.S. = D terdefinisi
	 * <br>Proses = D yang ada di class diubah isinya menjadi D yang ada di parameter
	 * <br>F.S. = D yang ada di class adalah D yang ada di parameter
	 */
	void SetDay (int D);
	
	/// Setter Bulan
	/** Operasi untuk mengubah atribut bulan dalam class Date
	 * <br>I.S. = M terdefinisi
	 * <br>Proses = M yang ada di class diubah isinya menjadi M yang ada di parameter
	 * <br>F.S. = M yang ada di class adalah M yang ada di parameter
	 */
	void SetMonth (int M);
	
	/// Setter Tahun
	/** Operasi untuk mengubah atribut Tahun dalam class Date
	 * <br>I.S. = Y terdefinisi
	 * <br>Proses = Y yang ada di class diubah isinya menjadi Y yang ada di parameter
	 * <br>F.S. = Y yang ada di class adalah Y yang ada di parameter
	 */
	void SetYear (int Y);
	
	/// Pemeriksaan komponen pembuat tanggal
	/** Operasi yang memeriksa apakah 3 komponen yang ada pada parameter 
	 * dapat membentuk tanggal pada dunia nyata secara valid atau benar */
	static bool IsDateValid (int D, int M, int Y);
	
	/// Operator ==
	/** Memeriksa apakah suatu variabel berclass Date sama dengan D.
	 * Fungsi ini akan mengembalikan true jika sama atau mengembalikan false jika tidak. */
	bool operator== (const Date &D);
	
	/// Operator !=
	/** Memeriksa apakah suatu variabel berclass Date tidak sama dengan D.
	 * Fungsi ini akan mengembalikan true jika tidak sama atau mengembalikan false jika sama. */
	bool operator!= (const Date &D);
	
	/// Operator <
	/** Fungsi ini akan mengembalikan true apabila suatu variabel berclass Date adalah tanggal yang lebih awal daripada D.
	 * dan false apabila sebaliknya atau sama dengan D. */
	bool operator< (const Date &D);
	
	/// Operator >
	/** Fungsi ini akan mengembalikan true apabila suatu variabel berclass Date adalah tanggal sesudah D.
	 * dan false apabila sebaliknya atau sama dengan D. */
	bool operator> (const Date &D);
	
	/// Pemeriksaan Tahun Kabisat
	/** Fungsi ini akan mengembalikan true apabila tahun Y adalah tahun kabisat 
	 * yaitu habis dibagi 4 tetapi tidak habis dibagi 100, atau habis dibagi 400. */
	static bool IsKabisat (const int &Y);

	/// Operator Baca
	/** Operator untuk membaca input user yang lalu dimasukkan ke dalam suatu
	 * variabel berclass Date
	 *	<br>I.S.	: Objek D ada.
	 *	<br>F.S.	: D berisi DATE yang valid
	 *	<br>Proses	: Mengulangi membaca komponen D, M, Y sehingga membentuk Date D yang valid.
	 *			Tidak mungkin menghasilkan Date D yang tidak valid. 
	 */
	friend istream& operator>>(istream &input, Date &D) {
		int day,month,year;
		char c;
		input >> day >> c >> month >> c >> year;
		while (!(IsDateValid(day, month, year))) {
			cout << "Input tanggal salah, coba input lagi" << endl;
			input >> day >> c >> month >> c >> year;
		}
		D.D = day;
		D.M = month;
		D.Y = year;
		return input;
	}
	
	/// Operator Tulis
	/** Operator untuk menuliskan variabel D berclass Date ke layar 
	 *	<br>I.S.	: D terdefinisi
	 *	<br>F.S.	: Nilai D ditulis ke layar dengan format D-M-Y
	 *	<br>Proses	: Menulis nilai setiap komponen dari variabel D ke layar 
	 */
	friend ostream& operator<<(ostream &output, const Date &D) {
		output << D.D << "-" << D.M << "-" << D.Y;
		return output;
	}
	
private:
	int D;
	int M;
	int Y;
};

#endif // DATE_H