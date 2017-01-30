#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> name(N);
	unordered_set<int> S;
	for(int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		name[i] = temp;
		S.insert(temp);
	}
	int currName = 1;
	for(int i = K; i < N; i++) {
		while(S.count(currName)) currName++;
		name[i] = currName++;
	}
	
	if(K == N) {
		cout << -1 << endl;
		return 0;
	}		

	vector<pii> edges;
	for(int i = 0; i < N; i++) {
		if(i != K) edges.emplace_back(i, K);
	}

	for(int i = K + 1; i < N; i++) {
		for(int j = 0; j < K; j++) {
			edges.emplace_back(j, i);
		}	
	}
	for(int i = K + 1; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			edges.emplace_back(i, j);	
		}
	}	
		
	if(K >= 2) {
		int X = (K - 2) / 2 + 2;
		for(int i = 2; i < X; i++)
			edges.emplace_back(0, i);
		for(int i = X; i < K; i++)
			edges.emplace_back(1, i);
		for(int i = 2; i < K; i++) {
			for(int j = i + 1; j < K; j++) {
				edges.emplace_back(i, j);
			}
		}
	}
		
	if(edges.size() < M) {
		cout << -1 << endl;
		return 0;
	}

	int count = 0;
	for(pii X : edges) {
		cout << name[X.first] << " " << name[X.second] << endl;
		count++;
		if(count == M) break;
	}
}
