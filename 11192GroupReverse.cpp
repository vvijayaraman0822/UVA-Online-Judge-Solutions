
// Vasudev Vijayaraman
// Digits Reverse - 11192
// UVA login name - vasapp
// Data Structure used - Arrays
// Tricks - Number of letters to be reversed done by dividing total number of digits by user entered number of groups. 
//           Creating a temp to hold temporary value

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int DigReverse; // integer to hold number of groups
	string letters; // hold the letters as a string
	cin >> DigReverse; // read user input of number of groups

	while(DigReverse) { // while there are number of groups to read in, keep looping
	
		cin >> letters; // reading in all the letters entered by the user
		int size = letters.size(); // returns the size of the string 
		int group = size / DigReverse; // number of letters to be reversed 
		for (int i = 0; i < size; i += group) 
		{
			for (int a = i, b = i + group-1; a<b; ++a, --b) // printing reverse from the loop
			{
				char temp(letters[a]); // temporary array of characters
				letters[a] = letters[b]; // content of one array is copied into another
				letters[b] = temp; // once copied, the array is set to temp to go to the next line

			}

		}

		cout << letters << '\n';// print statement

		cin >> DigReverse; // read the next line 
	}
    return 0;
}

