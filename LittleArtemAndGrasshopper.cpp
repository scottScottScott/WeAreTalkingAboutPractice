#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	string direction;	
	cin >> direction;
	vector<int> dist(N);
	for(int i = 0; i < N; i++)
		cin >> dist[i];
	vector<bool> visited(N);

	int curr = 0;
	while(true) {
		visited[curr] = 1;
		if(direction[curr] == '>') curr += dist[curr];
		else curr -= dist[curr];

		if(curr < 0 or curr >= N) {
			cout << "FINITE" << endl;
			return 0;
		}
		if(visited[curr]) {
			cout << "INFINITE" << endl;
			return 0;
		}
	}
}
