// Vasudev Vijayaraman
// UVA 587 - There's Treasure Everywhere
// UVA username - vasapp
// Data Structure used - map
// Tricks - Reading in data using sstream 

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;
const double diagDist = sqrt(2.0) / 2; // Setting diagonal 
const pair<double, double> origin(0.0, 0.0);

int main() {
	map<string, pair<double, double>> compass; // map containing string(directions) and pair(coordinates)
	int distance;
	int ct = 1;
	string line = ""; // Empty string
	string direction = "";

	// Initial value setting for the map
	compass["N"] = make_pair(0, 1);
	compass["S"] = make_pair(0, -1);
	compass["E"] = make_pair(1, 0);
	compass["W"] = make_pair(-1, 0);
	compass["NW"] = make_pair(-diagDist, diagDist);
	compass["NE"] = make_pair(diagDist, diagDist);
	compass["SW"] = make_pair(-diagDist, -diagDist);
	compass["SE"] = make_pair(diagDist, -diagDist);

	cout << fixed << setprecision(3); // upto 3 decimal places
	getline(cin, line); // Read in line by line

	while (line != "END") { // read until end of line
		pair <double, double> myLocation = origin;
		line = line.erase(line.size() - 1);
		replace(line.begin(), line.end(), ',', ' ');
		istringstream ss(line);
		while (ss >> distance >> direction) {
			myLocation.first = myLocation.first + distance * compass[direction].first;
			myLocation.second = myLocation.second + distance * compass[direction].second;
		}

		double simpleDistance = sqrt((myLocation.first*myLocation.first) + (myLocation.second*myLocation.second));

		cout << "Map #" << ct << "\nThe treasure is located at (" << myLocation.first << "," << myLocation.second
			<< ").\nThe distance to the treasure is " << simpleDistance << ".\n\n";

		++ct; //increment count
		getline(cin, line);
	}
	return 0;
}


	
