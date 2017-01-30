#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, temp;
	cin >> N;
	map<int, int> M;
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);	
		M[temp]++;
	}

	cin >> N;
	vector<pii> movies(N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		movies[i].first = temp;
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		movies[i].second = temp;
	}

	int best_index = -1;
	pii best;
	for(int i = 0; i < N; i++) {
		int X = M[movies[i].first];
		int Y = M[movies[i].second];
		if(best_index == -1 or X > best.first or (X == best.first and Y > best.second)) {
			best_index = i;
			best.first = X;
			best.second = Y;
		}
	}
	cout << best_index + 1 << endl;
}
