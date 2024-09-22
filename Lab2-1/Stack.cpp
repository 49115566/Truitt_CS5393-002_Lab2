#include "Stack.h"  // Include the Stack class definition

Stack::Stack() {    // Constructor for the Stack class
	head = nullptr;  // Initialize head to null (empty stack)
	tail = nullptr;  // Initialize tail to null (empty stack)
	len = 0;         // Initialize stack length to 0
}

Stack::~Stack() {   // Destructor for the Stack class
	while (head) {   // Loop to delete all nodes in the stack
		tail = head->next;  // Move the tail to the next node
		delete head;        // Delete the current head node
		head = tail;        // Move head to the next node
	}
	tail = nullptr;   // Ensure tail is set to null after deletion
}

void Stack::push(char b) {  // Method to push a character onto the stack
	Node* newNode = new Node;  // Create a new node
	len++;                     // Increase stack length
	newNode->bracket = b;      // Set the character in the new node
	newNode->prev = tail;      // Set the previous pointer to the current tail
	newNode->next = nullptr;   // Set the next pointer to null
	if (head) tail->next = newNode;  // If stack is not empty, link new node to current tail
	else head = newNode;             // If stack is empty, set head to the new node
	tail = newNode;                  // Update the tail to the new node
}

char Stack::pop() {    // Method to pop a character from the stack
	if (!tail) return 0;  // Return 0 if the stack is empty
	char b = tail->bracket;  // Get the character from the tail node
	Node* temp = tail->prev; // Temporarily store the previous node
	delete tail;             // Delete the tail node
	len--;                   // Decrease stack length
	tail = temp;             // Set the tail to the previous node
	if (tail) tail->next = nullptr;  // If tail exists, set its next pointer to null
	else head = nullptr;             // If no nodes left, set head to null
	return b;                // Return the popped character
}

char Stack::peep() {   // Method to view the top character without popping
	if (!tail) return 0;  // Return 0 if the stack is empty
	return tail->bracket; // Return the top character from the tail node
}

int Stack::getLen() {   // Method to get the current stack length
	return len;          // Return the stack length
}
