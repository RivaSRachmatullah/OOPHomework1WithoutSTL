/**
 * @file
 * @brief Implementation Queue Class
 * 
 */
#include "Queue.h"
#include <cstdlib>

Queue::Queue()
{
	CapacityofQueue = 25;
	Q = new int[CapacityofQueue + 1];
	Head = 0;
	Tail = 0;
}

Queue::Queue(int MaximumCapacityofQueue)
{
	if (MaximumCapacityofQueue > 0)
	{
		CapacityofQueue = MaximumCapacityofQueue;
	}
	else
	{
		CapacityofQueue = 25;
	}
	Q = new int[CapacityofQueue + 1];
	Head = 0;
	Tail = 0;
}

Queue::Queue(const Queue& Q)
{
	CapacityofQueue = Q.CapacityofQueue;
	this->Q = new int[CapacityofQueue + 1];
	Head = Q.Head;
	Tail = Q.Tail;
	int i = Head;
	while (i != Tail)
	{
		this->Q[i] = Q.Q[i];
		i++;
		if (i == CapacityofQueue + 1)
		{
			i = 1;
		}
	}
}

Queue& Queue::operator=(const Queue& Q)
{
	if (this->Q != NULL)
	{
		delete this->Q;
	}
	CapacityofQueue = Q.CapacityofQueue;
	this->Q = new int[CapacityofQueue+1];
	Head = Q.Head;
	Tail = Q.Tail;
	int i = Head;
	while (i != Tail)
	{
		this->Q[i] = Q.Q[i];
		i++;
		if (i == CapacityofQueue+1)
		{
			i = 1;
		}
	}
	return *this;
}

Queue::~Queue()
{
	delete Q;
}

int Queue::AddressofHead()
{
	return Head;
}

int Queue::AddressofTail()
{
	return Tail;
}

int Queue::ContentofHead()
{
	return Q[Head];
}

int Queue::ContentofTail() {
	return Q[Tail];
}

int Queue::Size() {
	return CapacityofQueue;
}

bool Queue::IsQueueEmpty()
{
	return (Head == 0 && Tail == 0);
}

bool Queue::IsQueueFull ()
{
	return Effective() == CapacityofQueue;
}

int Queue::Effective()
{
	if (IsQueueEmpty())
		return 0;
	else if (Tail > Head)
		return Tail - Head + 1;
	else if (Tail < Head)
		return (CapacityofQueue + Tail) - Head + 1;
	else
		return 1;
}

void Queue::Enqueue(int Element)
{
	if (!IsQueueFull())
	{
		if (IsQueueEmpty())
		{
			Head = 1;
			Tail = 1;
			Q[Tail] = Element;
		}
		else
		{ 
			Tail++;
			if (Tail > CapacityofQueue)
			{
				Tail = 1;
				Q[Tail] = Element;
			}
			else
				Q[Tail] = Element;
		}	
	}
}

int Queue::Dequeue()
{
	if (!IsQueueEmpty())
	{
		int Element = Q[Head];
		if (Effective() == 1)
		{
			Head = 0;
			Tail = 0;
		}
		else
		{
			Head++;
			if (Head > CapacityofQueue)
				Head = 1;
		}
		return Element;
	}
	else
		return 0;
}

int Queue::DeleteforJockeying()
{
	if (!IsQueueEmpty())
	{
		int X = Q[Tail];
		if (Effective() == 1)
		{
			Head = 0;
			Tail = 0;
		}
		else
		{
			Tail--;
			if (Tail == 0)
				Tail = CapacityofQueue;
		}
		return X;
	}
	else
		return 0;
}