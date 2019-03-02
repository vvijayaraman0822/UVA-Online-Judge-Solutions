// Vasudev Vijayaraman
// WertyU - 10082
// UVA login name - vasapp
// Data Structure used - Array
// Tricks - Assigning values to a constant array and looking for the position after its misplacement. 
//			If i is greater or equal to the length or array, then s[i] = 0


#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; // assigning value to a constant array
	int i, l;
	while ((l = getchar()) != EOF) // reading in characters until the end of file 
	{
		for (i = 1; key[i] && key[i] != l; i++); // If i is greater or equal to the length or array, then s[i] = 0
			if (key[i])
				putchar(key[i - 1]); // outputs the character to the left of the keyboard
			else
				putchar(l); 

	}
	return 0;
}

