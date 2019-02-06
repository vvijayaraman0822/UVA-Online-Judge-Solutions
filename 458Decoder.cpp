// Vasudev Vijayaraman
// Decoder - 458
// UVA login name - vasapp
// Data Structure used - Array
// Tricks - Figured that Ascii code values preceedes by 7 so print every (character - 7) until it is a null character


#include <iostream>
using namespace std;


int main()
{
	char letter[255]; // put 256 values of ASCII into an array
	char d;

	while (cin >> letter) { //  while loop to read in all the letters
		for (int i = 0; letter[i] != '\0'; i++) {  // puts data into the array until a null character represented by \0
			d = letter[i] - 7; // print values ASCII - 7
			cout << d;
		}
		cout << endl;  // next line 
	}
	
    return 0;
}

