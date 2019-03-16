// Vasudev Vijayaraman
// UVA 10209 - Is this Integration?
// UVA username - vasapp
// Data Structure Used - none 
	

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

#define PI acos(-1)

using namespace std;


int main()
{
	double side;
	
	while (cin >> side) {

		double striped = side*side*(1 - sqrt(3) + PI / 3); // Area of middle 
		double dotted = side*side*(2 * sqrt(3) - 4 + PI / 3); // Area of the outer arc
		double grid = side*side*(4 - 2 * PI / 3 - sqrt(3)); // Area of the outermost arcs
		
		cout << fixed << setprecision(3) << striped << " " << // Set decimal places to 3 and print
			dotted << " " <<
			grid << endl;
	}


	
    return 0;
}

