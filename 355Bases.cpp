// Vasudev Vijayaraman
// UVA 355 - The Bases are loaded
// UVA login name - vasapp
// Data Structure used - none 
// Tricks - set flag, keep count and use long long if number gets big


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int from, to;
	string number;
	while (cin >> from >> to >> number) // redaing in dadta
	{

		if (number[0] == '0')
		{
			cout << number << " base " << from << " = 0 base " << to << endl; // if number is 0, print statement 
		
		}

		else
		{
			int flag; 
			int m = 0;
			int counter = 0; // to keep count
			long long sum = 0;
			for (int i = number.length() - 1; i >= 0; i--) // traverse the array from right to left 
			{ 

				/* The logic below is to switch Hexadecimal to decimal*/
			  
				flag = 0;
				if (number[i] == 'A') 
					m = 10;
				else if (number[i] == 'B') 
					m = 11;
				else if (number[i] == 'C') 
					m = 12;
				else if (number[i] == 'D')
					m = 13;
				else if (number[i] == 'E')
					m = 14;
				else if (number[i] == 'F') 
					m = 15;
				else
				{
					m = number[i] - '0';
				}

				if (m >= from) // if greater than the number we are trying to convert from
				{
					flag = 1;
					break;
				}
				sum += m*pow(from, counter++); // power function and increment counter
			}
			if (flag) // if true
			{
				cout << number << " is an illegal base " << from << " number" << endl; // illegal base
			}
			else
			{
				long long keep;
				 keep = sum;
				char temp[100]; // to keep temporar variable
				int p;

				int t = 0; // counter the temporary variable 
				while (keep)
				{
					p = keep % to;
					if (p == 10) 
						temp[t++] = 'A';
					else if (p == 11) 
						temp[t++] = 'B';
					else if (p == 12) 
						temp[t++] = 'C';
					else if (p == 13) 
						temp[t++] = 'D';
					else if (p == 14) 
						temp[t++] = 'E';
					else if (p == 15) 
						temp[t++] = 'F';
					else
					{
						temp[t++] = p + '0';
					}
					keep = keep / to;
				}
				string result = "";
				for (int j = t - 1; j >= 0; j--) // traverse array from backwards 
				{
					
					result += temp[j]; // store result 

				}
				cout << number << " base " << from << " = " << result << " base " << to << endl;
				
			}
		}
	}
}
