#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include "../DateTime/DateTime.h"
#include "../Teller/Teller.h"

using namespace std;

class Event{
public:
	Event();
	Event(int N);
	~Event();
	
	// INPUT
	friend istream& operator>>(istream &input, Event &E) {
		DateTime DT;
		input >> DT >> E.code;
		while (E.code == ' ' || E.code == '\n')
			input >> E.code;
		if (DT < E.Deadline || DT == E.Deadline) {
			if (E.code == 'A' || E.code =='D') {
				if (E.code == 'A') {
					id++;
					E.T->SearchThenAdd(id);
					E.DT = DT;
				} else if (E.code == 'D') {
					int ID;
					input >> ID;
					int X = E.T->SearchThenDel(ID);
				}
			}
		}
		E.DT = DT;
		E.T->Print();
		return input;
	}

	// GETTER
	DateTime getTime();
	DateTime getDeadline();

	// SETTER
	void setDeadline(DateTime Deadline);

	// ENDING
	void Close();
	
private:
	static int id;
	DateTime DT, Deadline;
	char code;
	Teller *T;
};

#endif