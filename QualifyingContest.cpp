#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, string> pis;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<pis>> storage(M + 1);
	for(int n = 0; n < N; n++) {
		string name;	
		int region, points;
		cin >> name >> region >> points;
		storage[region].emplace_back(points, name);
	}
	for(int i = 1; i <= M; i++) {
		sort(storage[i].rbegin(), storage[i].rend());
		if(storage[i].size() > 2 and storage[i][1].first == storage[i][2].first)
			cout << "?" << endl;
		else 	
			cout << storage[i][0].second << " " << storage[i][1].second << endl;
	}
}
