#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	// Declare an array of 5 queues, each queue for a different priority level
	Q priorityQ[5];

	int priority;  // Variable to store the priority of the input value
	int val;       // Variable to store the input integer value

	// Loop to input 10 values and their respective priorities
	for (int i = 0; i < 10; i++) {
		priority = -1;  // Initialize priority with an invalid value
		cout << "Enter an integer value: ";  // Prompt user for an integer
		cin >> val;  // Read the integer value from the user

		// Loop until a valid priority (0 to 4) is entered
		while (priority < 0 || priority > 4) {
			cout << "Enter the priority of this integer in the queue: ";  // Prompt for priority
			cin >> priority;  // Read the priority value
		}
		// Enqueue the value into the queue corresponding to the entered priority
		priorityQ[priority].enqueue(val);
	}

	try {
		// Attempt to dequeue an item from the highest priority non-empty queue
		cout << "Dequeueing 1 item: ";
		int i;  // Variable to track the queue index

		// Find the first non-empty queue starting from the highest priority (0)
		for (i = 0; i < 5 && priorityQ[i].isEmpty(); i++);
		// Dequeue and print the front item from the highest non-empty queue
		cout << priorityQ[i].dequeue() << endl;

		// Attempt to dequeue another item in the same way
		cout << "Dequeueing 1 item: ";
		for (i = 0; i < 5 && priorityQ[i].isEmpty(); i++);
		cout << priorityQ[i].dequeue() << endl;
	}
	// Catch any runtime error, particularly for dequeueing from an empty queue
	catch (const runtime_error& e) {
		cout << "Error: " << e.what() << endl;  // Output the error message
	}

	int size = 0;	//Store queue size
	for (int i = 0; i < 5; i++) size += priorityQ[i].size();	//Sum sizes of various queues
	cout << "Total size: " << size << endl;	//Output the total size

	return 0;  // End of the program
}
