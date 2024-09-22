#include <iostream>           // Include input/output library for console operations
#include "Stack.h"            // Include the Stack class header file
using namespace std;          // Use the standard namespace to avoid prefixing std::

int main() {                  // Main function
	Stack s;                  // Create a Stack object to store the brackets
	char* exp = new char(50);  // Allocate memory for a character array (expression input)
	cout << "Enter the mathematical expression:\n";  // Prompt the user for input
	cin.getline(exp, 50);      // Read the input expression from the user
	for (int i = 0; exp[i]; i++) {  // Loop through each character in the expression
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')  // Check if the character is an opening bracket
			s.push(exp[i]);     // Push the opening bracket onto the stack
		else if (exp[i] == ')') {  // Check if the character is a closing parenthesis
			if (s.pop() != '(') {  // Pop from stack and check if it matches the opening parenthesis
				cout << "ERROR: the " << i + 1 << "th character of the expression, ), does not have a matching parenthesis.\n";
				// Output error if no matching opening parenthesis is found
				return 0;        // Exit the program on error
			}
		}
		else if (exp[i] == ']') {  // Check if the character is a closing bracket
			if (s.pop() != '[') {  // Pop from stack and check if it matches the opening bracket
				cout << "ERROR: the " << i + 1 << "th character of the expression, ], does not have a matching bracket.\n";
				// Output error if no matching opening bracket is found
				return 0;        // Exit the program on error
			}
		}
		else if (exp[i] == '}') {  // Check if the character is a closing brace
			if (s.pop() != '{') {  // Pop from stack and check if it matches the opening brace
				cout << "ERROR: the " << i + 1 << "th character of the expression, }, does not have a matching bracket.\n";
				// Output error if no matching opening brace is found
				return 0;        // Exit the program on error
			}
		}
	}
	if (s.getLen() != 0)  // Check if the stack is not empty (unmatched opening brackets)
		cout << "ERROR: not all parenthetical expressions are closed.\n";  // Output error if there are unmatched brackets
	else
		cout << "All parenthesis are used properly.\n";  // Output success if all brackets are matched correctly
	return 0;              // Return 0 to indicate successful execution
}
