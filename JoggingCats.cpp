#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adjList(N);
	for(int i = 0; i < M; i++) {
		int X, Y;
		scanf("%d %d", &X, &Y);
		X--;
		Y--;
		adjList[X].push_back(Y);
		adjList[Y].push_back(X);
	}
	
	long count = 0;
	vector<pii> info;
	for(int i = 0; i < N; i++)
		info.emplace_back(adjList[i].size(), i);
	sort(info.rbegin(), info.rend());
	vector<int> used(N);
	for(pii curr : info) {
		int currNode = curr.second;
		used[currNode] = true;
		unordered_map<int, int> Map;
		for(int X : adjList[currNode]) {
			if(!used[X]) {
				for(int Y : adjList[X]) {
					if(!used[Y]) 
						Map[Y]++;
				}
			}
		}
		for(pii X : Map)
			count += X.second * (X.second - 1) / 2;	
	}
	
	cout << count << endl;
}
