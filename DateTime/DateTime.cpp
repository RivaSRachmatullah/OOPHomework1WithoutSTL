#include "DateTime.h"

using namespace std;

// 4 SEKAWAN
DateTime::DateTime() {}
DateTime::DateTime(const DateTime& DT) {
	D = DT.D;
	T = DT.T;
}
DateTime::~DateTime() {}
	
/* GETTER */
Date DateTime::Tanggal() {
	return D;
}
Time DateTime::Waktu () {
	return T;
}
	
/* SETTER */
void DateTime::SetTanggal (Date D) {
	this->D = D;
}
/* Mengubah nilai komponen D dengan D di parameter */
void DateTime::SetWaktu (Time T) {
	this->T = T;
}
/* Mengubah nilai komponen T dengan T di parameter */

/* PREDIKAT */
bool DateTime::IsDTValid (Date D, Time T) {
	return Date::IsDateValid(D.GetDay(),D.GetMonth(),D.GetYear()) && Time::IsTimeValid(T.GetHour(),T.GetMinute(),T.GetSecond());
}
/*	Mengirim true jika D dan T dapat membentuk DateTime yang valid dipakai untuk mengetes SEBELUM membentuk sebuah DateTime */
bool DateTime::operator== (DateTime DT) {
	return DT.D == D && DT.T == T;
}
/* Menghasilkan true jika variabel berclass DateTime sama dengan D */
bool DateTime::operator!= (DateTime DT) {
	return DT.D != D || DT.T != T;
}
/* Menghasilkan true jika variabel berclass DateTime sama dengan D */
bool DateTime::operator< (DateTime DT) {
	if (D == DT.D)
		return T < DT.T;
	else 
		return D < DT.D;
}
/* Menghasilkan true jika variabel berclass DateTime kurang dari D */
bool DateTime::operator> (DateTime DT) {
	if (D == DT.D)
		return T > DT.T;
	else 
		return D > DT.D;
}
/* Menghasilkan true jika variabel berclass DateTime lebih dari D */