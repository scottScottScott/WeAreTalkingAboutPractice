#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

typedef pair<int, int> pii;

bool cmp(pii U, pii V) {
	int U_dist = abs(U.first) + abs(U.second);
	int V_dist = abs(V.first) + abs(V.second);
	return U_dist < V_dist;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int numMoves = 2 * N;
	vector<pii> bombs;
	for(int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		bombs.emplace_back(Y, X);
		if(X == 0 or Y == 0) numMoves += 2;
		else numMoves += 4;
	}
	cout << numMoves << "\n";
	sort(bombs.begin(), bombs.end(), cmp);
	for(pii curr : bombs) {
		stringstream first, second;
		if(curr.first > 0) {
			first  << "1 " << curr.first << " U\n"; 
			second << "1 " << curr.first << " D\n";
		}
		else if(curr.first < 0) {
			first  << "1 " << -curr.first << " D\n";	
			second << "1 " << -curr.first << " U\n";
		}

		if(curr.second > 0) {
			first  << "1 " << curr.second << " R\n"; 
			second << "1 " << curr.second << " L\n";
		}
		else if(curr.second < 0) {
			first  << "1 " << -curr.second << " L\n";	
			second << "1 " << -curr.second << " R\n";
		}

		cout << first.str();
		cout << "2\n";
		cout << second.str();
		cout << "3\n";	
	}	
}
