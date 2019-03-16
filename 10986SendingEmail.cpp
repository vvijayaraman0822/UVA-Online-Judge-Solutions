// Vasudev Vijayaraman
// 10986 - Sending Email
// UVA login name - vasapp
// Data Structure required - Vector, Priority_Queue
// Tricks - Pushing into the vector and using priority queue


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;


// vi dist(V, INF); 

//memset(d, INF, sizeof d); // catching the overflown

const int INF = 0x3f3f3f3f;

/*This function was taken from the Halim book Page nmber 148 as per the requirements 
since priority queue was a must for this program */

void dijakrstraAlgorithm(int s, vi &dist, vector<vii> & AdjList ) {

	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); 
		pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) 
			continue;
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

int i;
int t;
dist[s] = 0;

void readinData() {
	int server1;
	int server2;
	int cableLength;
	int TestCases;
	int m, n; s;
	cin >> TestCases;

	for (i = 0; i <= TestCases; i++) {
		cin >> n >> m >> s >> t;
		cin >> server1 >> server2 >> cableLength;
		//cout << n << m << s << t << endl;
		vector<vii> AdjList(n, vii());

		for (int j = 0; j < m; ++j) {
			cin >> server1 >> server2 >> cableLength;
			AdjList[server1].push_back(ii(server2, cableLength));
			AdjList[server2].push_back(ii(server1, cableLength));

			vi dist(1000000);
			dijakrstraAlgorithm(s, dist, AdjList);

		}
	}
}




int main()
{
	readinData();
	cout << "Case #" << i + 1 << ": ";
	if (dist[t] == INF)
		cout << dist[t] << endl;
	else
		cout << "unreachable" << endl;


return 0;
}


