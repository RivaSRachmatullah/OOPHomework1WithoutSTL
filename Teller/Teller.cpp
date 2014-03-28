#include <cmath>
#include "Teller.h"

using namespace std;

Teller::Teller()
{
	NumberofTeller = 5;
	T = new Queue[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int i = 0; i < NumberofTeller; i++)
		TellerServingStatus[i] = false;
}

Teller::Teller(int NumberofTeller)
{
	this->NumberofTeller = NumberofTeller;
	T = new Queue[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int i = 0; i < NumberofTeller; i++)
		TellerServingStatus[i] = false;
}

Teller::Teller(const Teller &T)
{
	NumberofTeller = T.NumberofTeller;
	this->T = new Queue[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int i = 0; i < NumberofTeller; i++)
	{
		this->T[i] = T.T[i];
		TellerServingStatus[i] = T.TellerServingStatus[i];
	}
}

Teller& Teller::operator=(const Teller &T)
{
	NumberofTeller = T.NumberofTeller;
	if (this->T != NULL)
	{
		delete this->T;
		delete TellerServingStatus;
	}
	this->T = new Queue[NumberofTeller];
	TellerServingStatus = new bool[NumberofTeller];
	for (int i = 0; i < NumberofTeller; i++)
	{
		this->T[i] = T.T[i];
		TellerServingStatus[i] = T.TellerServingStatus[i];
	}
	return *this;
}

Teller::~Teller()
{
	delete T;
	delete TellerServingStatus;
}

int Teller::DepartureofAnElement(int ID)
{
	bool stop = false;
	int i = 0;
	while (i < NumberofTeller && !stop)
	{
		if (T[i].ContentofHead() == ID)
			stop = true;
		else
			i++;
	}
	if (!stop)
	{
		cout << "Not Found" << endl;
		return 0;
	}
	else
	{
		int TellerNumber = Jockeying(i);
		if (TellerNumber != -1)
			T[TellerNumber].Enqueue(T[i].DeleteforJockeying());
		int IDRemoved = T[i].Dequeue();
		if (T[i].IsQueueEmpty())
			TellerServingStatus[i] = false;
		return IDRemoved;
	}
}

void Teller::ArriveofAnElement(int ID)
{
	int Minimum = 0;
	for (int i = 1; i < NumberofTeller; i++)
	{
		if (T[Minimum].Effective() > T[i].Effective())
			Minimum = i;
	}
	if (!T[Minimum].IsQueueFull())
	{
		if (T[Minimum].IsQueueEmpty())
			TellerServingStatus[Minimum] = true;
		T[Minimum].Enqueue(ID);
	}
}

void Teller::DepartureAll()
{
	int NumberofEmptyTeller = 0;
	for (int j = 0; j < NumberofTeller; j++)
	{
		if (!TellerServingStatus[j])
			NumberofEmptyTeller++;
	}
	int TellerNumber = 0;
	while (NumberofEmptyTeller != NumberofTeller)
	{
		if (TellerServingStatus[TellerNumber])
		{
			int IDRemoved = T[TellerNumber].Dequeue();
			if (T[TellerNumber].IsQueueEmpty())
			{
				TellerServingStatus[TellerNumber] = false;
				NumberofEmptyTeller++;
			}
			if (IDRemoved != 0)
				cout << "Departure " << IDRemoved << endl;
		}
		if (TellerNumber == NumberofTeller - 1)
			TellerNumber = 0;
		else
			TellerNumber++;
	}
}

void Teller::Print()
{
	for (int i = 0; i < NumberofTeller; i++)
	{
		if (TellerServingStatus[i])
			cout << "Teller[" << i << "] = " << T[i];
	}
}

int Teller::Jockeying(int iOrigin)
{
	int Minimum = 0;
	for (int i = 1; i < NumberofTeller; i++)
	{
		if (T[Minimum].Effective() > T[i].Effective())
			Minimum = i;
		else if (T[Minimum].Effective() == T[i].Effective() &&
				abs(Minimum-iOrigin) > abs(i-iOrigin))
			Minimum = i;
	}
	if (T[iOrigin].Effective() > T[Minimum].Effective() + 2)
		return Minimum;
	else
		return -1;
}
