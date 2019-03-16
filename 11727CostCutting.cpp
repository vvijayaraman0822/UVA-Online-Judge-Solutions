// Vasudev Vijayaraman
// Cost Cutting - 11727
// UVA login name - vasapp
// Data Structure used - none
// Tricks - For loop to read all data in and math equation to avoid using any data structures. For example - if y < x and y > z, then
// y is the middle value


#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int x, y, z, n;
	cin >> n;
	for (int i=0; i < n; i++ ){
		cin >> x >> y >> z;
		if (y > x && y < z || y < x && y > z ) {
			cout << "Case "<< i+1 <<": "<< y;
		}
		else if (x > y && x < z || x < y && x > z) {
			cout << "Case " << i + 1 << ": " << x;
		}
		else {
			cout << "Case " << i + 1 << ": " << z;
		}
		cout << endl;

	}

    return 0;
}
 
