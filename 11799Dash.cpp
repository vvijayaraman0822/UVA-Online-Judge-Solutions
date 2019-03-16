// Vasudev Vijayaraman
// Horror Dash - 11799
// UVA login name - vasapp
// Data Structure used - Vectors
// Tricks - Use the sorting algorithm in the STL to sort from minimum to maximum and choose the last value which is the maximum. Put all the values
//			in the vector, sort and choose the maximum value. 

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, n, c, counter;
	counter = 1; // setting the counter to 1
	cin >> a; // reading in the first line of input
	while (a--) { 
		vector <int> v; // declaring a vector of type int
		cin >> n;
		for (int i = 0; i < n; i++) { // reading in the values given in each line 
			cin >> c;
			v.push_back(c); // pushing it onto the vectors
		}
		sort(v.begin(), v.end()); //sorting the algorithm from beginnning to ending
		cout << "Case " << counter++ << ": " << v[n - 1] << endl; // prints the maximum value in each line
		}
	
    return 0;
}


