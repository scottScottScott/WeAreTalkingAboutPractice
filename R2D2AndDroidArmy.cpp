#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int calculate(vector<deque<int>> &V) {
	int result = 0;
	for(int i = 0; i < V.size(); i++)
		result += (V[i].empty() ? 0 : V[i].front());
	return result;
}

int main() {
	int n, m, k;	
	cin >> n >> m >> k;
	int info[n][m];		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> info[i][j];
	}
	
	vector<deque<int>> memo(m);
	int first = 0;
	int result = 0;
	vector<int> temp(m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			while(!memo[j].empty() and info[i][j] > memo[j].back())
				memo[j].pop_back();
			memo[j].push_back(info[i][j]);
		}
		while(calculate(memo) > k) {
			for(int j = 0; j < m; j++) {
				if(info[first][j] == memo[j].front())
					memo[j].pop_front();
			}
			first++;
		}
		if(i - first + 1 > result) {
			result = i - first + 1;
			for(int j = 0; j < m; j++)
				temp[j] = memo[j].front();
		}
	}
	for(int i = 0; i < m; i++)
		cout << temp[i] << " ";	
	cout << endl;
}
