#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	int N;
	cin >> N;
	while(N != 0) {
		vector<int> x(N);	
		vector<int> y(N);
		double adj[N][N];
		memset(adj, 0, sizeof(adj));

		double minY = 0;
		int minNode = -1;
		for(int i = 0; i < N; i++) {
			cin >> x[i] >> y[i];
			if(y[i] < minY || minNode == -1) {
				minNode = i;
				minY = y[i];
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(i != j && y[i] <= y[j]) {
					double dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2); 
					dist = sqrt(dist);
					adj[i][j] = dist;		
					//cout << "I: " << i << " J: " << j << " DIST: " << dist << endl;
				}
			}
		}

		double minCable = 0;
		vector<int> visited(N, 0);
		vector<double> dist(N, 0);
		visited[minNode] = 1;
		int nodesAdded = 1;	
		int currNode = minNode;
		int nxtNode = 0;
		//cout << "NXTNODE: " << currNode << endl;
		while(nodesAdded != N) {
			int minYNode = -1;
			double minDist;
			for(int i = 0; i < N; i++) {
				if(visited[i] != 1) {
					//cout << "I: " << currNode << " J: " << i << " MIN DIST: " << dist[i] << " ADJ DIST: " << adj[currNode][i] << endl;
					//cout << "OPTIONS";
					if(adj[currNode][i] != 0 && (dist[i] == 0 || adj[currNode][i] < dist[i])) {
						dist[i] = adj[currNode][i];
						//cout << " " << i << " ";
					}
					//cout << endl;
					if(dist[i] != 0 and (minYNode == -1 or (y[i] < y[minYNode]) or (y[i] == y[minYNode] && dist[i] < dist[minYNode]) ) ) {
						//cout << "!!!!!" << nxtNode << " " << i << " " << dist[i] << endl;
						minDist = dist[i];
						minYNode = i;
					}
				}
			}	
			//cout << "NXTNODE: " << nxtNode << endl;
			nxtNode = minYNode;
			visited[nxtNode] = 1;
			minCable += dist[nxtNode];
			nodesAdded++;
			currNode = nxtNode;
		}
		printf("%.2lf\n", minCable);
		cin >> N;
	}
	return 0;	
}
