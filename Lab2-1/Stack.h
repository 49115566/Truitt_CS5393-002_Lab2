#ifndef _STACK_H_
#define _STACK_H_

struct Node {
	Node* next;      // Pointer to the next node in the list
	Node* prev;      // Pointer to the previous node in the list
	char bracket;    // Character to store the bracket
};

class Stack {
private:
	Node* head;      // Pointer to the head of the stack (top)
	Node* tail;      // Pointer to the tail of the stack (bottom)

	int len;         // Integer to track the length of the stack
public:
	Stack();         // Constructor to initialize the stack
	~Stack();        // Destructor to clean up the stack

	void push(char b);   // Method to add a character to the top of the stack
	char pop();          // Method to remove and return the top character from the stack
	char peep();         // Method to view the top character without removing it

	int getLen();        // Method to return the current length of the stack
};


#endif