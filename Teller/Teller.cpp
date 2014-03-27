#include "Teller.h"

using namespace std;

Teller::Teller() {
	this->N = 5;
	this->Q = new Queue[N];
	this->QEmpty = new bool[N];
	for (int i = 0; i < N; i++) {
		QEmpty[i] = true;
	}
}

Teller::Teller(int N) {
	this->N = N;
	this->Q = new Queue[N];
	this->QEmpty = new bool[N];
	for (int i = 0; i < N; i++) {
		QEmpty[i] = true;
	}
}

Teller::Teller(const Teller &T) {
	this->N = T.N;
	this->Q = new Queue[N];
	for (int i = 0; i < N; i++) {
		this->Q[i] = T.Q[i];
	}
	this->QEmpty = new bool[N];
	for (int i = 0; i < N; i++) {
		this->QEmpty[i] = T.QEmpty[i];
	}
}

Teller& Teller::operator=(const Teller &T) {
	this->N = T.N;
	if (this->Q != NULL)
		delete this->Q;
	this->Q = new Queue[N];
	for (int i = 0; i < N; i++) {
		this->Q[i] = T.Q[i];
	}
	if (this->QEmpty != NULL)
		delete QEmpty;
	this->QEmpty = new bool[N];
	for (int i = 0; i < N; i++) {
		this->QEmpty[i] = T.QEmpty[i];
	}
	return *this;
}

Teller::~Teller() {
	delete Q;
	delete QEmpty;
}

	// Prosedur Add dan Del
infotype Teller::SearchThenDel(infotype id) {
	int i = 0;
	bool stop = false;
	while (i < N && !stop) {
		if (Q[i].InfoHead() == id)
			stop = true;
		else
			i++;
	}
	if (!stop) {
		cout << "Not Found" << endl;
		return 0;
	} else {
		int j = Jockeying(i);
		if (j != -1)
			Q[j].Add(Q[i].DelJockey());
		int X = Q[i].Del();
		if (Q[i].IsEmpty()) {
			QEmpty[i] = true;
		}
		return X;
	}
}

void Teller::SearchThenAdd(int id) {
	int min = 0;
	for (int i = 1; i < N; i++) {
		if (Q[min].Count() > Q[i].Count()) {
			min = i;
		}
	}
	if (!Q[min].IsFull()) {
		if (Q[min].IsEmpty())
			QEmpty[min] = false;
		Q[min].Add(id);
	}
}

void Teller::EndDel() {
	int cek = 0;
	for (int j = 0; j < N; j++) {
		if (QEmpty[j])
			cek++;
	}
	int i = 0;
	while (cek != N) {
		if (!QEmpty[i]) {
			int X = Q[i].Del();
			if (Q[i].IsEmpty()) {
				QEmpty[i] = true;
				cek++;
			}
			if (X != 0)
				cout << "Departure " << X << endl;
		}
		if (i == N-1)
			i = 0;
		else
			i++;
	}
}

int Teller::Jockeying (int iOrigin) {
	int min = 0;
	for (int i = 1; i < N; i++) {
		if (Q[min].Count() > Q[i].Count())
			min = i;
		else if (Q[min].Count() == Q[i].Count() && abs(min-iOrigin) > abs(i-iOrigin))
			min = i;
	}
	if (Q[iOrigin].Count() > Q[min].Count() + 2)
		return min;
	else
		return -1;
}

void Teller::Print() {
	for (int i = 0; i < N; i++) {
		if (!QEmpty[i]) {
			cout << "Q[" << i+1 << "] = " << Q[i];
		}
	}
}