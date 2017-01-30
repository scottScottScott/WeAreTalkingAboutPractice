#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int adj[26 * 2][26 * 2];

int toI(char c) {
	if(c >= 'a')
		return c - 'a';
	else 
		return c - 'A' + 26;
}

int main() {
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	//parse input
	int P;
	fin >> P;
	for(int i = 0; i < P; i++) {
		char c1, c2;	
		int dist;
		fin >> c1 >> c2 >> dist;
		int index1 = toI(c1);
		int index2 = toI(c2);	
		if(adj[index1][index2] == 0 || adj[index1][index2] > dist) {
			adj[index1][index2] = dist;
			adj[index2][index1] = dist;
		}
	}	

	//run Dijkstra
	vector<int> d(26 * 2);
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push(make_pair(0, toI('Z')));
	while(!q.empty()) {
		ii curr = q.top();	
		q.pop();
		int dist = curr.first;	
		int index = curr.second;
		if(dist <= d[index]) {
			if(index >= 26 && index != toI('Z')) {
				char outC = (index - 26) + 'A';
				fout << outC << " " << dist << endl;
				return 0;
			}
			for(int i = 0; i < 26 * 2; i++) {
				if(adj[index][i] > 0) {
					if(dist + adj[index][i] <= d[i] || d[i] == 0) {
						d[i] = dist + adj[index][i];
						q.push(make_pair(d[i], i));
					}
				}
			}	
		}	
	}

	return 0;
}
