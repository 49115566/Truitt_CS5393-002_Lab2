#ifndef _QUEUE_H_
#define _QUEUE_H_

// Definition of the Node structure
struct Node {
	// Pointer to the previous node in the list
	Node* prev;
	// Pointer to the next node in the list
	Node* next;
	// Value stored in this node
	int val;
};

// Definition of the class Q (queue)
class Q {
private:
	// Pointer to the head (front) of the queue
	Node* head;
	// Pointer to the tail (end) of the queue
	Node* tail;
	// Length of the queue (number of elements)
	int len;

public:
	// Constructor for initializing an empty queue
	Q();
	// Destructor to free allocated memory
	~Q();

	// Method to add an element to the end of the queue
	void enqueue(int v);
	// Method to remove and return the front element from the queue
	int dequeue();
	// Method to return the front element without removing it
	int front();

	// Method to check if the queue is empty
	bool isEmpty();
	// Method to get the number of elements in the queue
	int size();
};


#endif