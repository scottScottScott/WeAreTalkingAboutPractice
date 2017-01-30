#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M;	
	cin >> N >> M;
	vector<pii> edges;
	map<int, vector<int>> H;
	for(int i = 0; i < M; i++) {
		int A, B, W;
		scanf("%d %d %d", &A, &B, &W);
		A--;
		B--;
		edges.emplace_back(A, B);
		H[W].push_back(i);
	}

	vector<int> dist(N, 0);
	for(auto &X : H) {
		vector<int> &curr_vec = X.second;
		vector<pii> update;
		for(int i : curr_vec) {	
			pii currEdge = edges[i];
			int A = currEdge.first;
			int B = currEdge.second;

			if(dist[A] + 1 > dist[B]) 
				update.emplace_back(B, dist[A] + 1);
		}
		
		for(pii Y : update)
			dist[Y.first] = max(dist[Y.first], Y.second);
	}
	
	cout << *max_element(dist.begin(), dist.end()) << endl;
}
