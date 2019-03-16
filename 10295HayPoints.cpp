// Vasudev Vijayaraman
// 10295 - Hay Points
// UVA login name - vasapp
// Data Structure required - maps
// Tricks - while loops and reading in data correctly

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int TestCases; // contains number of lines to read
	int NumberofJobs; // contains number of jobs 
	int Payment; // contains how much the payment is
	long long total = 0; // holds the total pay
	string words; //contains job key words associated with payment
	string job; // contains the job description
	cin >> TestCases; // // reading in Test cases
	cin >> NumberofJobs; // read in number of jobs 
	map<string, int> mps; // map to hold the job key words and payment
	
	while (TestCases--) { // while loop until test cases
		cin >> words; // reading in data
		cin >> Payment;
		mps[words] = Payment; // associating set
	}

	while (NumberofJobs--) { // while loop number of jobs
		total = 0;
		while (1) { // infinite loop until break statement 
			cin >> job; // reading in job description
			if (job == ".") // break when you hit a fullstop
				break; 
			else
				total += mps[job]; // adding the sum and storing in total

		}

		cout << total << endl; // print the total 

	}
			return 0;
		}
