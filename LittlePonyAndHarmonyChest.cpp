#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 140000;
int memo[101][MAX];
int cost[101][MAX];
vector<int> factors(60);

void set_factors() {
	int index = 0;
	unordered_map<int, int> M;
	for(int i = 2; i < 60; i++) {
		int result = 0;
		int temp = i;
		for(int j = 2; j <= temp; j++) {
			if(temp % j == 0) {
				while(temp % j == 0)	
					temp /= j;
				if(!M.count(j)) M[j] = index++;
				result |= 1 << M[j];	
			}
		}
		factors[i] = result;
	}
}

int main() {
	set_factors();
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++)
		cin >> A[i];
	memset(cost, -1, sizeof(cost));
	cost[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int k = 0; k < MAX; k++) {
			if(cost[i][k] == -1) continue;
			for(int j = 1; j < 60; j++) {
				if( !(k & factors[j]) ) {
					pii next{k | factors[j], cost[i][k] + abs(A[i] - j)};	
					int &curr = cost[i + 1][next.first];
					if(curr == -1 or next.second < curr) {
						curr = next.second;
						memo[i][next.first] = j;
					}
				}
			}
		}
	}
	int result = 0;
	for(int k = 0; k < MAX; k++) {
		if(cost[n][k] != -1 and cost[n][k] < cost[n][result])
			result = k;	
	}
	vector<int> V;
	for(int i = n - 1; i >= 0; i--) {
		int used = memo[i][result];		
		V.push_back(used);
		result ^= factors[used];
	}
	reverse(V.begin(), V.end());
	for(int i = 0; i < n; i++)
		cout << V[i] << (i + 1 == n ? "\n" : " ");
}
