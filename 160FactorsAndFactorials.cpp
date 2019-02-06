
// Vasudev Vijayaraman
// UVA 160 - Factors and Factorials
// UVA username - vasapp
// Data Structure Used - Arrays
	
#include <iostream>
using namespace std;

int main()
{
	long input, i, flag, count, j, save;
	long primes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 }; 
	// All the primes less than 100 in an array
	// If input is a huge number, then use of Sieve of Erathosenes to generate prime number upto that limit 

	while (cin >> input) // reading in data
	{

		if (input == 0) // Terminates on a 0
			return 0;

		save = input;
		cout << input;

		long a[25] = { 0 }; // Creating array and setting it to 0 because there are 25 prime numbers below 100

		while (input != 1) // 1 is not a prime number 
		{
			i = input; // set input to i to compare
			j = 0;

			while (i > 1) // all primes greater than 1
			{
				count = 0; // set count to 0
				while (i % primes[j] == 0) // if remainder is 0
				{
					i /= primes[j];
					count++; // increment counter
				}
				a[j] += count;
				j++;
			}

			input--;
		}

		// output 

		for (i = 24; i >= 0; i--) // print array from backwards
		{
			if (a[i] != 0)
				break;
		}
		j = i;

		printf("%3ld! =", save); // width of 3
		if (j >= 15) // 15 digits in a row 
			flag = 0;
		else
			flag = 15; // set flag to 15 to go to the next line
		for (i = 0; i <= j; i++)
		{
			printf("%3ld", a[i]); // prints the answers 
			flag++;
			if (flag == 15)
				printf("\n%6c", ' '); // once hit 15 digits, new line
		}
		cout << '\n'; // New Line char
	}
	return 0;
}