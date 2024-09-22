#include <iostream>
#include "Queue.h"
using namespace std;

// Constructor to initialize an empty queue
Q::Q() {
	head = nullptr;  // Front of the queue (dequeue here)
	tail = nullptr;  // Back of the queue (enqueue here)
	len = 0;         // Initial length is zero
}

// Destructor to clean up dynamically allocated memory
Q::~Q() {
	while (head) {
		tail = head->next; // Move tail to the next node
		delete head;       // Delete the current head node
		head = tail;       // Move head forward
	}
}

// Enqueue a new value at the back (tail) of the queue
void Q::enqueue(int v) {
	Node* newNode = new Node;   // Create a new node
	newNode->val = v;           // Set the value of the new node
	newNode->next = nullptr;    // It will be the last node, so next is nullptr
	newNode->prev = tail;       // The previous node is the current tail
	if (tail) tail->next = newNode; // If there's a tail, update its next to the new node
	else head = newNode;            // If queue is empty, new node becomes head

	tail = newNode;  // The new node becomes the tail (back of the queue)
	len++;           // Increase the length
}

// Dequeue a value from the front (head) of the queue
int Q::dequeue() {
	if (!head) {  // If the queue is empty
		throw runtime_error("Queue is empty, cannot dequeue.");
	}

	Node* temp = head;       // Store the current head node in a temporary pointer
	int v = head->val;       // Get the value of the head node
	head = head->next;       // Move the head to the next node

	if (head) head->prev = nullptr; // If the queue is not empty, update the new head's prev to nullptr
	else tail = nullptr;            // If the queue is now empty, set tail to nullptr

	delete temp;  // Free the memory of the dequeued node
	len--;        // Decrease the length
	return v;     // Return the dequeued value
}

// Return the value at the front (head) of the queue without dequeuing it
int Q::front() {
	if (!head) {  // If the queue is empty
		throw runtime_error("Queue is empty, no front element.");
	}

	return head->val;  // Return the value at the head
}

// Check if the queue is empty
bool Q::isEmpty() {
	return len == 0;  // Return true if length is 0
}

// Return the current size of the queue
int Q::size() {
	return len;  // Return the length of the queue
}
