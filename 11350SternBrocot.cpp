// Vasudev Vijayaraman
// UVA Username - vasapp
// UVA 11350 - Stern Brocot Tree
// Data Structure Used - None
// Trick - Set the mid numerator and mid denonimator value to left and right in the beginning

#include <iostream>
#include <string>

using namespace std;

void SternBrocotTree(string direction) {
	// tree values left dnumberator, denominator, mid numerator etc
	long long left_num = 0;
	long long left_den = 1;
	long long right_num = 1;
	long long right_den = 0;
	long long mid_num = 1;
	long long mid_den = 1;

	for (int i = 0; i < direction.length(); i++)
	{
		if (direction[i] == 'R') { // set values if right
			left_num = mid_num;
			left_den = mid_den;
			mid_num = left_num + right_num;
			mid_den = left_den + right_den;
		}
		else if (direction[i] == 'L') { // set values if left
			right_num = mid_num;
			right_den = mid_den;
			mid_num = left_num + right_num;
			mid_den = left_den + right_den;
		}
	}
	cout << mid_num << "/" << mid_den << endl;

}



int main()
{
	string direction; // has the direction of the tree left or right
	int TestCases; // Number of Test Cases
	cin >> TestCases;
	while (TestCases--) {
		cin >> direction; // reading in data 
		SternBrocotTree(direction); // calling the function
		
	}

    return 0;
}

