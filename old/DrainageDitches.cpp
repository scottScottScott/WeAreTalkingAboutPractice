#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

int adj[201][201];
int prevNode[201];
int N, M;

bool findPath() {
	int s = 1;
	int t = M;
	memset(prevNode, 0, sizeof(prevNode));
	deque<int> visited;
	visited.push_back(s); prevNode[s] = s;
	while(!visited.empty())	{
		int currNode = visited.front();
		visited.pop_front();
		for(int i = 1; i <= M; i++) {
			if(adj[currNode][i] > 0 and prevNode[i] == 0) {
				prevNode[i] = currNode;
				visited.push_back(i);
				if(i == t)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ifstream fin("ditch.in");
	ofstream fout("ditch.out");

	fin >> N >> M;

	for(int i = 0; i < N; i++) {
		int a, b, cap;
		fin >> a >> b >> cap;
		adj[a][b] += cap;
	}

	int flow = 0;
	while(findPath()) {
		int currNode = M;
		int pathVal = adj[prevNode[M]][M];
		while(currNode != 1) {
			int previous = prevNode[currNode];	
			pathVal = min(pathVal, adj[previous][currNode]);
			currNode = previous;
		}
		flow += pathVal;

		currNode = M;
		//cout << M << endl;
		while(currNode != 1) {
			int previous = prevNode[currNode];	
			adj[previous][currNode] -= pathVal;
			adj[currNode][previous] += pathVal;
			currNode = previous;
			//cout << currNode << endl;
		}
		//cout << "PATH VAL: " << pathVal << endl << endl;
	}

	/*
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 4; j++) {
			cout << i << " " << j << ": " << adj[i][j] << endl;
		}
	}
	*/
	fout << flow << endl;
}
