#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;
	vector<pii> P;
	for(int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		P.emplace_back(X, Y);
	}

	bool result = false;
	int i;
	for(i = 0; i + 1 < N; i++)
		if(P[i].first != P[i + 1].first) break;
	if(i + 1 == N) result = true;

	for(i = 0; i + 1 < N; i++)
		if(P[i].second != P[i + 1].second) break;
	if(i + 1 == N) result = true;

	cout << (result ? "YES" : "NO") << endl;	
}
