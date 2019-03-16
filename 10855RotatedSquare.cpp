// Vasudev Vijayaraman
// 10855 - Rotated Square
// UVA login name - vasapp
// Data Structure required - 2D vectors
// Tricks - Indexing, traversing and rotating 2D vectors using nested
//			for loops

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

void Rotate(vector<vector<char>> &B, int n);
int getCount(vector<vector<char>> &A, vector<vector<char>> &B, int N, int n);

int main()
{
	int N, n;
	cin >> N >> n; // N is big square and n is small square

	while (!(N == 0 && n == 0)) // while loop to keep reading until either one is 0
	{
		vector<vector<char>> A(N, vector<char>(N)); // fill large matrix
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				cin >> A[r][c];
			}
		}

		vector<vector<char>> B(n, vector<char>(n)); // fill small matrix
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				cin >> B[r][c];
			}

		}
		int i = 0;
		while (i < 4)
		{
			cout << getCount(A, B, N, n); // count how many times small matrix appears in large matrix
			if (i != 3)
			{
				cout << " ";
			}
			Rotate(B, n);
			i++;
		}

		cin >> N >> n;
		cout << endl;
	}

	return 0;
}

void Rotate(vector<vector<char>> &B, int n)

{
	// c, N-r-1

	vector<vector<char>> C(n, vector<char>(n));
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{

			C[c][n - r - 1] = B[r][c];
		}
	}
	B = C;
}
	
int getCount(vector<vector<char>> &A, vector<vector<char>> &B, int N, int n)
{
	// traverse large matrix until the first element in the
   //  small matrix is found

	int count = 0;
	for (int r = 0; r < N - n + 1; r++)
	{
		for (int c = 0; c < N - n + 1; c++)
		{
			// first element is hit
			if (A[r][c] == B[0][0]) {

				// compare submatrix with small matrix
				int check = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (A[r + i][c + j] == B[i][j])
						{
							check++;
						}

					}
				}
				// if submatrix contains all elements in the small'
				// matrix in the correct order, then a match is found

				if (check == n*n)
				{
					count++;
				}
			}
		}
	}
	return count;
}