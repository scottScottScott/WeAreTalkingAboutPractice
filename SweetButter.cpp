#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	ifstream fin("butter.in");
	ofstream fout("butter.out");

	int N, P, C;
	fin >> N >> P >> C;

	vector<int> numCows(P + 1, 0);	
	for(int i = 0; i < N; i++) {
		int cowLoc;
		fin >> cowLoc;
		numCows[cowLoc]++;
	}

	vector<int> adjList[P + 1];	
	vector<int> distList[P + 1];	
	for(int i = 0; i < C; i++) {
		int a, b, dist;
		fin >> a >> b >> dist;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
		distList[a].push_back(dist);
		distList[b].push_back(dist);
	}

	int minDist = -1;
	for(int i = 1; i <= P; i++) {
		//cout << "P: " << i << endl;
		vector<int> visited(P + 1, 0);
		vector<int> dist(P + 1, 0);
		priority_queue<ii, vii, greater<ii> > Q;
		Q.push(make_pair(0, i));	
		while(!Q.empty()) {
			ii currPair = Q.top();
			int curr = currPair.second;
			Q.pop();
			if(visited[curr] != 1) {
				visited[curr] = 1;
				for(int j = 0; j < adjList[curr].size(); j++) {
					int nxt = adjList[curr][j];
					if(visited[nxt] == 0) {
						if(dist[nxt] == 0 or dist[curr] + distList[curr][j] < dist[nxt]) {
							dist[nxt] = dist[curr] + distList[curr][j];
							//cout << "NEXT: " << nxt << " DIST: " << dist[nxt] << endl;
							Q.push(make_pair(dist[nxt], nxt));
						}
					}
				}
			}
		}
		int currCowDist = 0;
		for(int j = 1; j <= P; j++) {
			//cout << "J: " << j << " DIST: " << dist[j] << endl;
			currCowDist += dist[j] * numCows[j];
		}
		if(minDist == -1 || currCowDist < minDist)
			minDist = currCowDist;
	}

	fout << minDist << endl;
	return 0;
}
