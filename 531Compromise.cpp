// Vasudev Vijayaraman
// UVA 531 - Compromise
// UVA username - vasapp
// Data Structure used - Vectors
// Tricks - Record the direction where it came from and reverse 

#include "stdafx.h"
#include  <iostream>
#include  <string>
#include  <vector>

using  namespace  std;

string A[110], B[110];
int LCS[110][110] = { 0 };
int pre[110][110];

int main()
{
	while(1) {

		int N = 1,
		int M = 1;

		while(cin >> A[N] && A[N] != " # ") 
			++N;
		while(cin >> B[M] && B[M] != " # ") 
			++M;

		if(N == 1) 
			return  0;

		for(int i = 1; i < N; ++i) {
			for(int j = 1; j < M; ++j) {
				if(A[i] == B[j]) {
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
					pre[i][j] = 0;   // 0 is ↖
				}
				else{
					if(LCS[i - 1][j] > LCS[i][j - 1]) {
					LCS[i][j] = LCS[i - 1][j];
					pre[i][j] = 1; // 1 is
				}
				else{
					LCS[i][j] = LCS[i][j - 1];
				pre[i][j] = 2; // 2 is 
				   }
				}
			}
		}
		vector<string *> Ans; // Vector of strings (pointer)
		int i = N - 1, j = M - 1;
		while(i && j) {
			if(pre[i][j] == 0) {
				Ans.push_back(&A[i]); // push the element (refernce)
				--i, --j;
			}
			else  if (pre[i][j] == 1)
				--i;
			else
				--j;
		}
		if(!Ans.empty()) { //if vector not empty
			cout << **Ans.rbegin();
			for(auto iter = Ans.rbegin() + 1; iter != Ans.rend(); ++iter) // iterator 
				cout << '  ' << **iter; // iterate and print answer
		}
		cout << endl;
	}
	return 0;
}