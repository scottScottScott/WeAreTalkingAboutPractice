#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
const int max_length = 1e6;
ll memo[max_length][4][4];
const int MOD = 1e9 + 7;

void update(vector<int> &result, int val) {
	if(val == 4) {
		for(int i = 0; i < val; i++)
			result.push_back(i);
	}
	else
		result.push_back(val);
} 
int main() {
	string s;	
	getline(cin, s);
	int n = s.size();
	map<char, int> M{ {'0', 0}, {'1', 1}, {'2', 2}, {'*', 3}, {'?', 4} };
	for(int i = 1; i < n; i++) {
		int fst, snd;
		fst = M[s[i - 1]];
		snd = M[s[i]];
		if(i == 1) {
			vector<int> first, second;
			update(first, fst);
			update(second, snd);
			for(int x : first) {
				for(int y : second) {
					if(x == 0 and (y == 0 or y == 1))
						memo[1][x][y] = 1;
					if(x == 3 and (y == 1 or y == 2 or y == 3))
						memo[1][x][y] = 1;
					if(x == 1 and y == 3)
						memo[1][x][y] = 1;
				}
			}
			continue;
		}
		if(fst == 4 or fst == 0) {
			if(snd == 4 or snd == 0) { 
				memo[i][0][0] += memo[i - 1][0][0];
				memo[i][0][0] += memo[i - 1][1][0];
			}
			if(snd == 4 or snd == 1) {
				memo[i][0][1] += memo[i - 1][0][0];
				memo[i][0][1] += memo[i - 1][1][0];
			}
		}
		if(fst == 4 or fst == 1) {
			if(snd == 4 or snd == 0) {
				memo[i][1][0] += memo[i - 1][3][1];
			}
			if(snd == 4 or snd == 1) {
				memo[i][1][1] += memo[i - 1][3][1];
			}
			if(snd == 4 or snd == 3) {
				memo[i][1][3] += memo[i - 1][0][1];	
				memo[i][1][3] += memo[i - 1][1][1];
			}
		}
		if(fst == 4 or fst == 2) {
			if(snd == 4 or snd == 3)
				memo[i][2][3] += memo[i - 1][3][2];
		}	
		if(fst == 4 or fst == 3) {
			if(snd == 4 or snd == 1) {
				memo[i][3][1] += memo[i - 1][3][3];	
				memo[i][3][1] += memo[i - 1][2][3];	
				memo[i][3][1] += memo[i - 1][1][3];	
			}
			if(snd == 4 or snd == 2) {
				memo[i][3][2] += memo[i - 1][3][3];	
				memo[i][3][2] += memo[i - 1][2][3];	
				memo[i][3][2] += memo[i - 1][1][3];	
			}
			if(snd == 4 or snd == 3) {
				memo[i][3][3] += memo[i - 1][3][3];	
				memo[i][3][3] += memo[i - 1][2][3];	
				memo[i][3][3] += memo[i - 1][1][3];	
			}
		}

		for(int a = 0; a < 4; a++) {
			for(int b = 0; b < 4; b++)
				memo[i][a][b] %= MOD;
		}
	}
	if(n == 1) {
		if(s[0] == '0' or s[0] == '*') cout << 1 << endl;
		else if(s[0] == '?') cout << 2 << endl;
		else cout << 0 << endl;
		return 0;
	}

	ll result = 0;
	int last = n - 1;
	result += memo[last][0][0];
	result += memo[last][1][0];
	result += memo[last][1][3];
	result += memo[last][2][3];
	result += memo[last][3][1];
	result += memo[last][3][3];
	cout << result % MOD << endl;
}
