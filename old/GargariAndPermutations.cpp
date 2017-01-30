#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> info(n, vector<int> (k + 1));	

	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			info[--temp][i + 1] = j;
		}
	}
	for(int i = 0; i < n; i++) {
		info[i][0] = INT_MAX;
		for(int j = 1; j <= k; j++)
			info[i][0] = min(info[i][0], info[i][j]);
	}
	sort(info.begin(), info.end());
	vector<int> count(n);
	int result = 1;
	for(int i = 0; i < n; i++) {
		int temp = 0;
		for(int j = 0; j < i; j++) {
			bool valid = true;
			for(int l = 1; l <= k; l++) {
				if(info[i][l] < info[j][l])
					valid = false;
			}
			if(valid) temp = max(temp, count[j]);
		}
		count[i] = temp + 1;
		result = max(result, count[i]);
	}	
	cout << result << endl;
}
