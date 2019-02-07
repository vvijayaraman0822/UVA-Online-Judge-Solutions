// Vasudev Vijayaraman
// UVA 673 - Paranthesis Balance
// UVA username - vasapp
// Data Structure used - Stack
// Tricks - Pushing and popping into stacks appropriately 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string expr; // string to read in all the characters as a string
	stack<char> myStack; // stack containing characters 
	int count; // contains the number of lines 
	cin >> count; // reading in the number of lines
	while (count--) { // execute until the counter is 0
		getline(cin, expr); // reading in the character line by line 
		for (int i = 0; i < expr.length(); i++)
		{
			if (!myStack.empty() && expr[i] == '(' && myStack.top() == ')') // pop if it is a balanced paranthesis 
			{
				myStack.pop();
			}
			else if (!myStack.empty() && expr[i] == '[' && myStack.top() == ']') // pop if it is a balanced square paranthesis 
			{
				myStack.pop();
			}
			else // else push back into the stack 
			{
				myStack.push(expr[i]);
			}
		}

		if (myStack.empty()) // checking to see of the stack is empty 
		{
			cout << "Yes" << endl; // Yes if the stack is empty 
		}

		else
		{
			cout << "No" << endl;
		}


	}
	return 0;

}