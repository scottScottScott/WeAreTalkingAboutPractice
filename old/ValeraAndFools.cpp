#include <iostream>
#include <utility>
#include <algorithm>
#include <deque>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n, k;
	cin >> n >> k;
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> P(n);
	vector<int> sumP(n);	
	for(int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		switch(temp) {
			case 0:
				P[i] = 1;
				break;
			case 100:
				P[i] = 2;
				break;
			default:
				P[i] = 4;
		}
		
	}
	for(int i = n - 1; i >= 0; i--)
		sumP[i] = (i + 1 == n ? 0 : sumP[i + 1]) | P[i];	
	vector<vector<bool>> seen(n, vector<bool>(n));
	vector<bool> V(n + 1);
	int result = 0;
	pii temp{0, 1};
	deque<pii> Q{temp};
	seen[temp.first][temp.second] = 1;;
	for(int shots = 0; shots < k; shots++) {
		int Q_size = Q.size();
		while(Q_size--) {
			pii curr = Q.front();
			int A = curr.first; 
			int B = curr.second;
			Q.pop_front();
			vector<pii> next;
			result++;

			if(P[A] & 5 and sumP[B] & 6) {
				if(B + 1 == n) 
					V[B] = 1;
				else
					next.emplace_back(B, B + 1);
			}
			if(P[A] & 6 and !(sumP[B] & 2)) {
				if(B + 1 == n)
					V[A] = 1;
				else
					next.emplace_back(A, B + 1);
			}
			if(P[A] & 6 and sumP[B] & 6) {
				if(B + 1 == n - 1)
					V[B + 1] = 1;
				else if(B + 1 == n)
					V[n] = 1;
				else
					next.emplace_back(B + 1, B + 2);
			}
			for(pii x : next) {
				if(!seen[x.first][x.second]) {
					seen[x.first][x.second] = 1;
					Q.push_back(x);
				}
			}
		}
	}
	result += Q.size();
	result += accumulate(V.begin(), V.end(), (int) 0);
	cout << result << endl;
}
