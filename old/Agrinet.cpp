#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() { 
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");

	//parse input
	int N;	
	fin >> N;
	int adj[N][N];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			fin >> adj[i][j];
		}
	}

	//Prim's Algorithm in O(N * N) time
	int totalCost = 0;
	vector<bool> visited(N, false);
	vector<int> cost(N, 100001);
	cost[0] = 0;
	int numVisited = 0;
	while(numVisited != N) {
		numVisited++;
		int minNode;
		int minCost = -1;
		for(int i = 0; i < N; i++) {
			if(!visited[i] && (minCost == -1 || cost[i] < minCost)) { 
				minCost = cost[i];
				minNode = i;
			}
		}

		totalCost += minCost;	
		visited[minNode] = true;
		for(int i = 0; i < N; i++) {
			if(adj[minNode][i] < cost[i])
				cost[i] = adj[minNode][i];
		}
	}

	fout << totalCost << endl;
	return 0;
}
