/**
 * \class Queue
 * 
 * @brief Queue Class
 * @details Represent a Queue
 * 
 * @author Riva Syafri Rachmatullah (13512036) for .h file
 * @author Riva Syafri Rachmatullah (13512036) for .cpp file
 *
 * @version v1.3
 * 
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue
{
public:
	/**
	 * @brief Initializes a new instance of the Queue class with 26 block of memory.
	 */
	Queue();
	
	/**
	 * @brief Initializes a new instance of the Queue class with MaximumElementofQueue + 1 block of memory.
	 * 
	 * @param[in] MaximumCapacityofQueue Maximum number of element stored on Queue.
	 */
	Queue(int MaximumCapacityofQueue);
	
	/**
	 * @brief Initializes a new instance of the Queue class with all the content of specified Queue.
	 * 
	 * @param[in] Q The object Queue that will be copied.
	 */
	Queue(const Queue& Q);
	
	/**
	 * @brief Copy all content of specified Queue to current Queue.
	 * 
	 * @param[in] Q The object Queue that will be copied.
	 */
	Queue& operator=(const Queue& Q);
	
	/**
	 * @brief Clear an instance of Queue from memory.
	 */
	~Queue();
	
	/**
	 * @brief Writes the specified Queue followed by the current line terminator to the standard output stream.
	 * @details Queue will be printed {x1,x2,x3,...,xn}
	 * 
	 * @param[out] output An instance of class ostream.
	 * @param[in] Q An instance of class Queue.
	 */
	friend ostream& operator<<(ostream &output, const Queue& Q)
	{
		if (Q.Head != 0)
		{
			output << "{";
			output << Q.Q[Q.Head];
			int TemporaryInt = Q.Tail + 1;
			if (TemporaryInt == Q.CapacityofQueue + 1)
				TemporaryInt = 1;
			if (Q.Head != Q.Tail) {
				int i = Q.Head + 1;
				if (i == Q.CapacityofQueue + 1)
					i = 1;
				while (i != TemporaryInt)
				{
					output << "," << Q.Q[i];
					i++;
					if (i == Q.CapacityofQueue + 1)
						i = 1;
				}
			}
			output << "}" << endl;
		}
		else
			output << "{}" << endl;
		return output;
	}

	/**
	 * @brief Gets the Head address of queue.
	 * @return The Head address of queue.
	 */
	int AddressofHead();
	
	/**
	 * @brief Gets the Tail address of queue.
	 * @return The Tail address of queue.
	 */
	int AddressofTail();
	
	/**
	 * @brief Gets the content on Queue's Head address.
	 * @exception InvalidOperationException Queue is empty.
	 * @return The value of Queue's Head address.
	 */
	int ContentofHead();
	
	/**
	 * @brief Gets the content on Queue's Tail address.
	 * @exception InvalidOperationException Queue is empty.
	 * @return The value of Queue's Tail address.
	 */
	int ContentofTail();
	
	/**
	 * @brief Gets the maximum capacity that can be stored on Queue.
	 * @return The maximum capacity of Queue.
	 */
	int Size();
	
	/**
	 * @brief Determines whether Queue is empty or not.
	 * @details Queue is empty if Head and Tail are 0.
	 * @return true if Queue is empty; otherwise false.
	 */
	bool IsQueueEmpty();
	
	/**
	 * @brief Determines whether Queue is full or not.
	 * @details Queue is full if Count() equals to the MaximumCapacityofQueue.
	 * @return true if Queue is full; otherwise false.
	 */
	bool IsQueueFull();
	
	/**
	 * @brief Gets the number of elements stored on Queue.
	 * @return The number of elements stored.
	 */
	int Effective();
	
	/**
	 * @brief Add element to Queue's Tail.
	 * @param[in] Element Element to input.
	 */
	void Enqueue(int Element);
	
	/**
	 * @brief Delete element on Queue's Head.
	 * @return 0 if Queue is empty; otherwise element on Queue's Head.
	 */
	int Dequeue();
	
	/**
	 * @brief Delete element on Queue's Tail.
	 * @exception InvalidOperationException Queue is empty.
	 * @return Element on Queue's Tail.
	 */
	int DeleteforJockeying();

private:
	int *Q, Head, Tail, CapacityofQueue;
};

#endif