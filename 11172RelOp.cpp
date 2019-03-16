// Vasudev Vijayaraman
// Relational Operators - 11172
// UVA login name - vasapp
// Data Structure used - none
// Tricks - Simple while loop to read in data, if statement for basic relational operators

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a;
	while (a--) {
		cin >> b >> c;
		if (b < c) {
			cout << "<";
		}
		else if (b > c) {
			cout << ">";
		}
		else {
			cout << "=";
		}
		cout << endl;

	}

    return 0;
}

