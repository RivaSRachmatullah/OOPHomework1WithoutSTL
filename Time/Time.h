/**\class Time
 *
 * \brief Class Time
 *
 * Class ini merepresentasikan waktu pada dunia nyata.
 * Berisi atribut jam, menit, dan detik yang bertipe integer dan juga 
 * method berupa prosedur dan fungsi untuk mengelola jam.
 *
 * \note Class ini hanya mengelola waktu dalam bentuk HH:MM:SS
 * tanpa tanggal
 *
 * $Author: Riva Syafri Rachmatullah (.h) <br>Indam Muhammad dan Riva Syafri Rachmatullah (.cpp) $
 *
 * \version 1.0 $Revision: 1.1 $
 *
 * $Date: 2014/03/19 16:53:23 $
 *
 * Contact		:	<br>13512036@std.stei.itb.ac.id
 *					<br>13512026@std.stei.itb.ac.id
 *
 * Created on	: 7 Maret 2014 17:00:00
 *
 */


#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
public:
	/// Constructor (CTOR)
	Time();

	/// Copy Constructor (CCTOR)
	Time(const Time& T);

	/// Destructor
	~Time();

	/// Operator Tulis
	/** Operator untuk menuliskan variabel T berclass Time ke layar 
	 *	<br>I.S.	: T terdefinisi
	 *	<br>F.S.	: Nilai T ditulis ke layar dengan format H:M:S
	 *	<br>Proses	: Menulis nilai setiap komponen dari variabel T ke layar 
	 */
	friend ostream& operator<<(ostream &output, const Time& T) {
		output << T.H << ":" << T.M << ":" << T.S;
		return output;
	}
	
	/// Operator Baca
	/** Operator untuk membaca input user yang lalu dimasukkan ke dalam suatu
	 * variabel berclass Time
	 *	<br>I.S.	: Objek T ada.
	 *	<br>F.S.	: T berisi TIME yang valid
	 *	<br>Proses	: Mengulangi membaca komponen H, M, S sehingga membentuk Time T yang valid.
	 *			Tidak mungkin menghasilkan Time T yang tidak valid. 
	 */
	friend istream& operator>>(istream &input, Time& T) {
		int hour, minute, second;
		char c;
		input >> hour >> c >> minute >> c >> second;
		while (!(IsTimeValid(hour, minute, second))) {
			cout << "input jam salah" << endl;
			input >> hour >> c >> minute >> c >> second;
		}
		T.H = hour;
		T.M = minute;
		T.S = second;
		return input;
	}

	/// Pemeriksa komponen pembuat waktu
	/** Operasi yang memeriksa apakah 3 komponen yang ada pada parameter 
	 * dapat membentuk jam pada dunia nyata secara valid atau benar */
	static bool IsTimeValid (int H, int M, int S);
	
	/// Getter Jam
	int GetHour();
	
	/// Getter Menit
	int GetMinute();
	
	/// Getter Detik
	int GetSecond();

	/// Setter Jam
	/** Operasi untuk mengubah atribut jam dalam class Time 
	 * <br>I.S. = H terdefinisi
	 * <br>Proses = H yang ada di class diubah isinya menjadi H yang ada di parameter
	 * <br>F.S. = H yang ada di class adalah H yang ada di parameter
	 */
	void SetHour(int H);
	
	/// Setter Menit
	/** Operasi untuk mengubah atribut menit dalam class Time 
	 * <br>I.S. = M terdefinisi
	 * <br>Proses = M yang ada di class diubah isinya menjadi M yang ada di parameter
	 * <br>F.S. = M yang ada di class adalah M yang ada di parameter
	 */
	void SetMinute(int M);
	
	/// Setter Second
	/** Operasi untuk mengubah atribut detik dalam class Time 
	 * <br>I.S. = S terdefinisi
	 * <br>Proses = S yang ada di class diubah isinya menjadi S yang ada di parameter
	 * <br>F.S. = S yang ada di class adalah S yang ada di parameter
	 */
	void SetSecond(int S);

	/// Operator ==
	/** Memeriksa apakah suatu variabel berclass Time sama dengan T.
	 * Fungsi ini akan mengembalikan true jika sama atau mengembalikan false jika tidak. */
	bool operator==(const Time &T);
	
	/// Operator !=
	/** Memeriksa apakah suatu variabel berclass Time tidak sama dengan T.
	 * Fungsi ini akan mengembalikan true jika tidak sama atau mengembalikan false jika sama. */
	bool operator!= (const Time &T); 
	
	/// Operator <
	/** Fungsi ini akan mengembalikan true apabila suatu variabel berclass Time adalah waktu yang lebih awal daripada T.
	 * dan false apabila sebaliknya atau sama dengan T. */
	bool operator< (const Time &T);

	/// Operator >
	/** Fungsi ini akan mengembalikan true apabila suatu variabel berclass Time adalah waktu sesudah T.
	 * dan false apabila sebaliknya atau sama dengan T. */
	bool operator> (const Time &T);
	
private:
	int H;
	int M;
	int S;
};

#endif