#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, A, B;
vector<bool> visited, result;
vector<int> info;

void move(int &curr, int &next, vector<vector<int>> &adjList) {
	int temp = next;
	if(adjList[next][0] != curr) {
		next = adjList[next][0];
		curr = temp;
	}
	else {
		next = adjList[next][1];
		curr = temp;
	}
}

void bodyCode(int curr, vector<vector<int>> &adjList, bool &valid) {  
	int next = adjList[curr][0];
	while(true) {
		visited[curr] = 1;
		visited[next] = 1;
		int first = info[curr];
		int second = info[next];

		if(A - first == second) result[curr] = result[next] = 0;
		else result[curr] = result[next] = 1;

		if(adjList[next].size() == 1) break;

		move(curr, next, adjList);
		if(adjList[next].size() == 1) {
			valid = false;
			break;
		}
		move(curr, next, adjList);
		if(visited[curr]) break;
	}
}


int main() {
	cin >> N >> A >> B;
	info.resize(N);
	map<int, int> toIndex;
	for(int i = 0; i < N; i++) {
		cin >> info[i];
		toIndex[info[i]] = i;
	}

	bool valid = true;
	vector<vector<int>> adjList(N);
	for(int i = 0; i < N; i++) {
		int next_A = A - info[i];
		if(toIndex.count(next_A))
			adjList[i].push_back(toIndex[next_A]);

		int next_B = B - info[i];
		if(next_B != next_A and toIndex.count(next_B))
			adjList[i].push_back(toIndex[next_B]);

		if(adjList[i].size() == 0) valid = false;
	}

	visited.resize(N);
	result.resize(N);

	for(int i = 0; i < N; i++) {
		if(visited[i] == 0 and adjList[i].size() == 1)
			bodyCode(i, adjList, valid);
	}

	if(!valid) {
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < N; i++) {
		if(visited[i] == 0)
			bodyCode(i, adjList, valid);
	}

	cout << "YES" << endl;
	for(int i = 0; i < N; i++) {
		printf(result[i] ? "1" : "0");
		printf(i != N - 1 ? " " : "\n");
	}
}
