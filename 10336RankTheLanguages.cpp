// Vasudev Vijayaraman
// UVA 10336 - Rank the Languages
// UVA username - vasapp
// Data Structure - 2D Vectors
// Tricks - Comparing upper, lower, left and right. Flood Fill method

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> graph(height + 2, vector<char>(width + 2));
void FloodFill(int, int, vector<vector<char>> &, char store);
char computeAnswer(int, int, vector<vector<char>> &);
int height;
int width;

int main() {
	int testCases;
	cin >> testCases;
	string input;

	while (testCases--)
	{
		cin >> height;
		cin >> width;

		for (int rows = 0; rows < height + 2; rows++) // create a border so it does not go outside the range
		{
			for (int columns = 0; columns < width + 2; columns++) // height and width are 2 more because of the border around it
			{
				graph[rows][columns] = '#';
			}
		}
		for (int temp = 0; temp < height; temp++)
		{
			cin >> input;
			for (int rows = temp + 1; rows < height + 2; rows++)
				for (int columns = 1; columns < width + 2; columns++)
				{
					if (rows != height + 1 && columns != width + 1)
					{
						graph[rows][columns] = input[columns - 1];
					}
				}
		}

		cout << "World #" << testCases + 1 << "\n";
		vector<int> counting(26);

		for (int r = 1; r < height; r++)
			for (int c = 1; c < width; c++)
				if (graph[r][c] != '#')
				{
					counting[graph[r][c] - 97]++;
					FloodFill(r + 1, c, graph);
				}
		Output();
	}
}


bool comp(const pair<char, int> a, const pair<char, int> b) // pair and compare
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

void Output(int rows, int columns) {
	int max = -1;
	int alpha;
	while (max != 0) {
		max = 0;
		for (int i = 0; i < 26; ++i)
			if (graph[rows][columns] > max) {
				max = graph[rows][columns];
				alpha = i + 'a';
			}
		if (max > 0) {
			graph[max - 'a'] = 0;
			cout << max;
		}
	}
}



void FloodFill(int rows, int columns, vector<vector<char>>&graph, char store)
{
	if (graph[rows][columns] != '#')
	{
		graph[rows][columns] = '#';
		if (graph[rows + 1][columns] == store) // check bottom row
			FloodFill(rows + 1, columns, graph, store); 
		else if (graph[rows - 1][columns] == store) // check top row
			FloodFill(rows - 1, columns, graph, store);
		else if (graph[rows][columns + 1] == store) // check to the right
			FloodFill(rows, columns + 1, graph, store);
		else if (graph[rows][columns - 1] == store) // check to the left
			FloodFill(rows, columns - 1, graph, store); 
	}
}

char computeAnswer(int rows, int columns, vector<vector<char>>&graph)
{
	if (graph[rows][columns] != '#')
		FloodFill(rows, columns, graph, store);
		return graph[rows][columns];
	else
		return '#';
}

