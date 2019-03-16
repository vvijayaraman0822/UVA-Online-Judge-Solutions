// Vasudev Vijayaraman
// 10305 - Ordering Tasks
// UVA login name - vasapp
// Data Structure required - Vector 
// Tricks - Pushing into the vector correctly and traversing through it

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix; // 2d vectors of int to push the data in 
vector<bool> fountOut; // keep track if discovered or not
vector<int> answer; // sorting the top

void depthFirstAlgorithm(int first)
{
	fountOut[first] = true;  // set bool to true
	int second;
	for (int i = 0; i < matrix[first].size(); ++i) { // traverse through the 
		second = matrix[first][i];
		if (fountOut[second] == false)  // if has not found out
			depthFirstAlgorithm(second); // keep traversing & recurrence
	}
	answer.push_back(first); // pushing back into the top
}


int main()
{
	int numberofTask;
	int relations;
	int first;
	int second;

	while (cin >> numberofTask >> relations) { // reading in data
		if (numberofTask == 0 || relations == 0)
			break;

		else {
			
			fountOut.assign(numberofTask + 1, false); // assign a vector of size number of tasks and set all to false
			matrix.resize(numberofTask + 1); // set the vector size to the number of Task


			while (relations--) {
				cin >> first >> second; // reading in the m and n
				matrix[first].push_back(second); // pushing into  a 2d vector

			}

			for (int i = 1; i <= numberofTask; i++) {
				if (fountOut[i] == false) //
					depthFirstAlgorithm(i);
			}
			for (int i = numberofTask - 1; i >= 0; --i) { // printing from backwards
				cout << answer[i] << " ";
	
			}
			cout << endl;
		}
	}
	return 0;
}

