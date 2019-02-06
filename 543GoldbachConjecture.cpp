// Vasudev Vijayaraman
// UVA 543 - Goldbach Conjecture
// UVA username - vasapp
// Data Structure used - Bitset, map and Vectors

#include <bitset>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bitset<10000010> sets;
vector<int> primes;
map<int, bool> answer;

void Generate_Prime(long long largest_num) {
	sets.set(); // sets all the bits to 1
	sets[0] = 0; // Sets 0 because it is not prime
	sets[1] = 0; // Sets 1 because it is not prime
	for (long long i = 2; i <= largest_num + 1; i++) {
		if (sets[i]) {
			for (long long j = i * i; j <= largest_num + 1; j += i) // Finding its own multiple and factors
				sets[j] = 0;
			primes.push_back((int)i); // Pushing into the vector as integer by casting 
			answer[i] = true; // if prime, then true for key value pairs(maps)
		}
	}
}

int input;

int main() {
	Generate_Prime(1000000); // Calling the function
	for(;;) { // infinite loop
		cin >> input;
		if (input == 0)  // break when input is 0
			break;
		int i;
		for (i = 0; i < primes.size(); i++) { // Vector size
			if (answer[input - primes[i]]) // Input - the prime number
				break;
		}
		cout << input << " = " << primes[i] << " + " << input - primes[i] << endl; // print answer

	}
}


