#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M, H, T;
	cin >> N >> M >> H >> T;
	
	vector<pii> edges;
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if(H <= T)
			edges.emplace_back(min(a, b), max(a, b));
		else
			edges.emplace_back(max(a, b), min(a, b));
	}

	vector<vector<int>> adjList(N + 1);
	for(pii curr : edges) {
		adjList[curr.first].push_back(curr.second);
		adjList[curr.second].push_back(curr.first);
	}

	for(pii edge : edges) {
		if(H > adjList[edge.first].size() - 1 or T > adjList[edge.second].size() - 1) continue;

		vector<bool> temp(N + 1);
		vector<bool> intersect(N + 1);
		int extra = 0;	
		for(int X : adjList[edge.first]) {
			if(X != edge.second) {
				temp[X] = 1;	
			}
		}
		for(int X : adjList[edge.second]) {
			if(X != edge.first) {
				if(temp[X] == 1) {
					intersect[X] = 1;
					extra++;
				}
			}
		}
		
		int S_1 = adjList[edge.first].size() - 1 - extra;
		int S_2 = adjList[edge.second].size() - 1 - extra;

		if(H <= S_1 + extra) {
			if(S_1 < H)	
				extra -= H - S_1;
			if( T <= S_2 + extra) {
				cout << "YES" << endl;
				cout << edge.first << " " << edge.second << endl;

				vector<pii> two_nodes{ {edge.first, H}, {edge.second, T} };
				int inter_index = 0;
				for(pii X : two_nodes) {
					int j = 0;
					for(int i = 0; i < X.second; i++) {
						int temp;
						while(j < adjList[X.first].size() and 
							( (temp = adjList[X.first][j]) == two_nodes[0].first or temp == two_nodes[1].first or intersect[temp]) ) j++;
					
						if(j < adjList[X.first].size())
							cout << adjList[X.first][j++];
						else {
							while(intersect[inter_index] == 0) inter_index++;
							cout << inter_index++;
						}
						if(i != H - 1) cout << " ";
						else cout << endl;
					}	
				}
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}
