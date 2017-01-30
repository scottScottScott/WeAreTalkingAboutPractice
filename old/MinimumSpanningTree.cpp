#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

vector<int> Parent;
vector<int> Rank;

int Find(int X) {
	if(X != Parent[X])
		Parent[X] = Find(Parent[X]);
	return Parent[X];
}

bool Link(int X, int Y) {
	if(X == Y) return false;
	
	if(Rank[X] > Rank[Y]) {
		Parent[Y] = X;
	}
	else {
		Parent[X] = Y;
		if(Rank[Y] == Rank[X])
			Rank[Y]++;
	}
	return true;
}

bool Union(int X, int Y) {
	return Link(Find(X), Find(Y));
}

int main() {
	int N, M;
	cin >> N >> M;
	while(N || M) {
		vector<pii> edges;
		vector<pii> weights;
		for(int i = 0; i < M; i++) {
			int U, V, W;
			cin >> U >> V >> W;
			edges.emplace_back(min(U, V), max(U, V));
			weights.emplace_back(W, i);	
		}
		vector<pii> edgesUsed;
		long totalWeight = 0;
		Parent.resize(N);
		for(int i = 0; i < N; i++) {
			Parent[i] = i;
		}
		Rank.clear();
		Rank.resize(N);
		sort(weights.begin(), weights.end());
		for(pii X : weights) {
			int i = X.second;
			if(Union(edges[i].first, edges[i].second)) {
				totalWeight += X.first;
				edgesUsed.push_back(edges[i]);
			}	
		}	
		sort(edgesUsed.begin(), edgesUsed.end());
		if(edgesUsed.size() < N - 1) {
			cout << "Impossible" << endl;
		}
		else {	
			cout << totalWeight << endl;	
			for(pii X : edgesUsed) 
				cout << X.first << " " << X.second << endl;
		}
		cin >> N >> M;
	}
}
