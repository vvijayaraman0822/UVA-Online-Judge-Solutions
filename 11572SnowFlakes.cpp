// Vasudev Vijayaraman
// UVA login name - vasapp
// UVA 11572 - Snow Flakes
// Data Structure used - Maps
// Tricks - reading input and inserting into the map correctly


#include "stdafx.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

int pairs; 
int TestCases; // holds the number of testcase
int NumberSnow; // holds the number of snowflakes
int dat; // storing the data
int counters; // keeps count
int answer;
using namespace std;
map <int, int> snowflakes; // map holding two integer type

int main(){
	cin >> TestCases; // reading in testcases
	while (TestCases--) { // until testcase becomes 0
		cin >> NumberSnow;
		snowflakes.clear();
		answer = 0; counters = 0; pairs = 0;
		for (int i = 0; i < NumberSnow; i++) {
			cin >> dat; // reading in data
			int x = snowflakes[dat]; 
			if (x != 0) { // loop until it is not 0
				pairs = max(pairs, x); // maximum value
					counters = i - pairs - 1; // counter

}
				counters++; // incrementing the counter
				snowflakes[dat] = i;
				answer = max(answer, counters); // max value
		}
		cout << answer << endl;
	}

}