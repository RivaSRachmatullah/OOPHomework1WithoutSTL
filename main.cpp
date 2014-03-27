#include <iostream>
#include "Event/Event.h"

using namespace std;

int main() {
	DateTime Deadline,DT;
	int N;
	cin >> Deadline >> N;
	Event *E = new Event(N);
	E->setDeadline(Deadline);
	bool stop = false;
	do {
		cin >> *E;
		if (E->getDeadline() < E->getTime() || E->getDeadline() == E->getTime())
			stop = true;
	} while (!stop);
	E->Close();
	system("pause");
	return 0;
}