#include "Date.h"

Date::Date() {
	this->D = 1;
	this->M = 1;
	this->Y = 1;
}
	
Date::Date(const Date& D) {
	this->D = D.D;
	this->M = D.M;
	this->Y = D.Y;
}
	
Date::~Date() {}

int Date::GetDay () {
	return D;
}
	
int Date::GetMonth () {
	return M;
}

int Date::GetYear () {
	return Y;
}

void Date::SetDay (int D) {
	this->D = D;
}

void Date::SetMonth (int M) {
	this->M = M;
}

void Date::SetYear (int Y) {
	this->Y = Y;
}

bool Date::IsDateValid (int D, int M, int Y) {
	if (IsKabisat(Y) && Y > 0) {
		if (M == 2)
			return D >= 1 && D <= 29;
		else if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
			return D >= 1 && D <= 31;
		else if (M == 4 || M == 6 || M == 9 || M == 11)
			return D >= 1 && D <= 30;
		else
			return false;
	} else if (!IsKabisat(Y) && Y > 0) {
		if (M == 2)
			return D >= 1 && D <= 28;
		else if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
			return D >= 1 && D <= 31;
		else if (M == 4 || M == 6 || M == 9 || M == 11)
			return D >= 1 && D <= 30;
		else
			return false;
	} else {
		return false;
	}
}

bool Date::operator== (const Date &D) {
	return this->D == D.D && this->M == M && this->Y == Y;
}

bool Date::operator!= (const Date &D) {
	return this->D != D.D || this->M != M || this->Y != Y;
}

bool Date::operator< (const Date &D) {
	if (this->Y == D.Y) {
		if (this->M == D.M)
			return this->D < D.D;
		else
			return this->M < D.M;
	} else
		return this->Y < D.Y;
}

bool Date::operator> (const Date &D) {
	if (this->Y == D.Y) {
		if (this->M == D.M)
			return this->D > D.D;
		else
			return this->M > D.M;
	} else
		return this->Y > D.Y;
}

bool Date::IsKabisat (const int &Y) {
	if (Y > 0)
		return ((Y%4 == 0) && (Y%100 != 0)) || (Y%400 == 0);
	else
		return false;
}
