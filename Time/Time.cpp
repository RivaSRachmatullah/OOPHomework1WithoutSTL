#include "Time.h"

Time::Time() {
	H = 0;
	M = 0;
	S = 0;
}
	
Time::Time(const Time& T) {
	H = T.H;
	M = T.M;
	S = T.S;
}

Time::~Time() {
}

bool Time::IsTimeValid (int H, int M, int S) {
	return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59) && (S >= 0) && (S <= 59));
}
	
int Time::GetHour() {
	return H;
}

int Time::GetMinute() {
	return M;
}

int Time::GetSecond() {
	return S;
}

void Time::SetHour(int H) {
	this->H = H;
}

void Time::SetMinute(int M) {
	this->M = M;
}

void Time::SetSecond(int S) {
	this->S = S;
}

bool Time::operator==(const Time &T) {
	return H == T.H && M == T.M && S == T.S;
}

bool Time::operator!= (const Time &T) {
	return H != T.H || M != T.M || S != T.S;
}

bool Time::operator< (const Time &T) {
	if (H == T.H) {
		if (M == T.M)
			return S < T.S;
		else
			return M < T.M;
	} else
		return H < T.H;
}

bool Time::operator> (const Time &T) {
	if (H == T.H) {
		if (M == T.M)
			return S > T.S;
		else
			return M > T.M;
	} else
		return H > T.H;
}