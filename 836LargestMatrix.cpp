// Vasudev Vijayaraman
// UVA 836 - Largest Matrix
// UVA username - vasapp
// Data Structure used - Array 
// Tricks - Use 2D range sum. First select vertical side length and second selects position

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string Matrix[1000]; // Array of Matric upto 1000 values

bool isTrue(int begin, int end, int j)
{
	for (begin; begin <= end ; ++begin)
		if (Matrix[begin][j] != '1') // Test case 1
			return false;
	return true;
}

int main()
{

	int TestCases;
	cin >> TestCases;
	while (TestCases--) // number of test cases
	{
		cin >> Matrix[0]; // 
		int N = Matrix[0].size(); // Size of matrix

		for (int i = 1; i < N; ++i)
			cin >> Matrix[i]; // inserting values into the matrix

		int SubMatrix = 0; 
		int Max = 0; // Set max to 0
		for (int Len = 1; Len <= N; ++Len) {
			for (int i = 0; i + Len - 1 < N; ++i) {
				SubMatrix = 0;
				for (int j = 0; j < N; ++j) {
					if (isTrue(i, i + Len - 1, j))
						SubMatrix += Len;
					else
						SubMatrix = 0;

					if (SubMatrix > Max) Max = SubMatrix; // set max to submatrix if it is higher
				}
			}
		}
		cout << Max << endl;
		if (TestCases) // print until testcases
			cout << endl;
	}
}
