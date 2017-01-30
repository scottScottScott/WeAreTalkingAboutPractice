#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

int N, M;
int adj[402][402];
int visited[402];

bool hasFlow() {
	int s = 0;
	int t = 401;

	memset(visited, -1, sizeof(visited));
	visited[s] = s;

	deque<int> toVisit;	
	toVisit.push_back(s);

	while(!toVisit.empty()) {
		int curr = toVisit.front();
		toVisit.pop_front();
		for(int i = 0; i <= 401; i++) {
			if(visited[i] == -1 && adj[curr][i] > 0) {
				visited[i] = curr;
				toVisit.push_back(i);
				if(i == t)
					return true;
			}
		}	
	}

	return false;
}

int main() {
	ifstream fin("stall4.in");
	ofstream fout("stall4.out");

	fin >> N >> M;
	for(int a = 1; a <= N; a++) {
		int S;
		fin >> S;
		adj[0][a] = 1;
		for(int i = 0; i < S; i++) {
			int b;	
			fin >> b;
			b += 200;
			adj[a][b] = 1;
		}
	}
	for(int i = 201; i <= 200 + M; i++) {
		adj[i][401] = 1;
	}

	int flow = 0;
	while(hasFlow()) {
		int curr = 401;	
		int flowPath = adj[visited[curr]][curr];
		while(curr != 0) {
			int prev = visited[curr];
			flowPath = min(flowPath, adj[prev][curr]);
			curr = prev;
		}
		flow += flowPath;
		
		curr = 401;
		while(curr != 0) {
			int prev = visited[curr];
			adj[prev][curr] -= flowPath;
			adj[curr][prev] += flowPath;
			curr = prev;
		}
	}
	fout << flow << endl;
}
