#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

list<int> adj[501];
vector<int> path;

void eulerianPath(int node) {
	//cout << node << endl;
	while(adj[node].size()) {
		list<int>::iterator itr = min_element(adj[node].begin(), adj[node].end());
		int nxtNode = *itr;
		adj[node].erase(itr);
		for(list<int>::iterator itr = adj[nxtNode].begin(); itr != adj[nxtNode].end(); itr++) {
			if(*itr == node) {
				adj[nxtNode].erase(itr);
				break;
			}
		}
		eulerianPath(nxtNode);
	}
	path.push_back(node);	
}

int main() {
	ifstream fin("fence.in");
	ofstream fout("fence.out");

	int F;
	fin >> F;
	for(int i = 0; i < F; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int start = -1;	
	for(int i = 1; i <= 500; i++) {
		//cout << i << " " << adj[i].size() << endl;
		if(adj[i].size() > 0) {
			if(adj[i].size() % 2 == 0 && start == -1)
				start = i;
			else if(adj[i].size() % 2 == 1 && (start == -1 || adj[start].size() % 2 == 0))	
				start = i;
		}
	}

	//cout << start << endl;

	eulerianPath(start); 
	for(int i = path.size() - 1; i >= 0; i--) 	
		fout << path[i] << endl;		
	
	return 0;
}
