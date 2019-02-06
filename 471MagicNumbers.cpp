// Vasudev Vijayaraman
// 471 - Magic Numbers
// UVA login name - vasapp
// Data Structure required - Vector
// Tricks - Using the isUnique function to extract one digit at a time

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isUnique(long long input) {

	int setNumber[10] = { 0 };

	while (input) {
		setNumber[input % 10]++; // extracting one digit at a time
		if (setNumber[input % 10] > 1) { // if the remainder is more than 1
			return false;
		}
		input /= 10; // extracting digits
	}

	return true;
}


int main() {

	int testCases; // read in testcases
	long long Largest = 9876543210LL;
	long long input = 9876543210LL; // input is long long since it is a big number

	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		cin >> input; // input reading in
	
		//cout << input;

		long long first_num = input;
		long long second_num = 1;

		while (true) {
			if (isUnique(first_num) && isUnique(second_num)) 
				cout << first_num << " / " << second_num << " = " << input << endl;
			first_num = first_num + input;
			second_num++;

				if (first_num > Largest){
					break;
			}
		}

		if (testCases) {
			cout << endl;
		}
	}
return 0;

}


	
