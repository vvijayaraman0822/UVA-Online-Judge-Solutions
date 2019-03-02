// Vasudev Vijayaraman
// Squarelotron - 10016
// UVA login name - vasapp
// Data Structure used - vectors
// Tricks - Flips using cases

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{

	int DifferentCases; // store first line of input
	cin >> DifferentCases; // read first line of input for number of cases

	while (DifferentCases--) // keep reading in data until all the cases exist
	 {
		int opCt;
		cin >> opCt;
		vector< vector<int> > sq(opCt, vector<int>(opCt)); // 2d vectors of int 

		for (int i = 0; i < opCt; ++i) // rows
		{
			for (int j = 0; j < opCt; ++j) // columns
				cin >> sq[i][j]; // reading in the rows and columns
		}

		int rings = (opCt >> 1) + (opCt & 1);
		for (int i = 0; i < rings; ++i)
		{
			int op;
			cin >> op; // reading in the op
			for (int j = 0; j < op; ++j) // looping through the op
			{
				int op;
				cin >> op;
				int limit = opCt - i - 1;
				switch (op)
				{
					// Upside-Down Flip
				case 1: // up down swap code using (UL,UL) and (LR,LR) as your corners
					for (int k = i; k <= limit; ++k)
						swap(sq[i][k], sq[limit][k]);

					for (int k = i + 1; (k << 1) < opCt - 1; ++k)
					{
						int l = opCt - k - 1;
						swap(sq[k][i], sq[l][i]);
						swap(sq[k][limit], sq[l][limit]);
					}
					break;
					// Left-Right Flip
				case 2:
					for (int k = i; k <= limit; ++k)
						swap(sq[k][i], sq[k][limit]);

					for (int k = i + 1; (k << 1) < opCt - 1; ++k)
					{
						int l = opCt - k - 1;
						swap(sq[i][k], sq[i][l]);
						swap(sq[limit][k], sq[limit][l]);
					}
					break;
					// Flip through the Main Diagonal
				case 3:
					for (int k = i + 1; k <= limit; ++k) // swaps left col and bottom row of selected rin
					{
						swap(sq[i][k], sq[k][i]);
						swap(sq[limit][k], sq[k][limit]); // //swaps bottom row and right col of select ring
					}
					break;
					// Flip through the Main Inverse Diagonal
				case 4:
					for (int k = limit - 1, l = i + 1; k >= i; --k, ++l)
					{
						swap(sq[i][k], sq[l][limit]);
						swap(sq[l][i], sq[limit][k]);
					}
					break;
				}
			}
		}

		for (int i = 0; i < opCt; ++i)
		{
			for (int j = 0; j < opCt; ++j)
				cout << sq[i][j] << (j + 1 < opCt ? " " : "\n"); // print the opCt
		}
	}
	system("pause");

	return 0;
}