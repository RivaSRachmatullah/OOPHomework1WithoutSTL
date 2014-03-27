#include "Event.h"

int Event::id = 0;

Event::Event() {
	T = new Teller();
}

Event::Event(int N) {
	T = new Teller(N);
}

Event::~Event() {
	delete T;
}

DateTime Event::getTime() {
	return DT;
}

DateTime Event::getDeadline() {
	return Deadline;
}

void Event::setDeadline(DateTime Deadline) {
	this->Deadline = Deadline;
}

void Event::Close() {
	cout << "Loop terminate" << endl;
	T->EndDel();
}

