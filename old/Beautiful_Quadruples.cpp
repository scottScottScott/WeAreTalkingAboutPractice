#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> bounds(4);	
	for(int i = 0; i < 4; i++)
		cin >> bounds[i];
	sort(bounds.begin(), bounds.end());

	vector<long> temp(bounds[3] + 1);
	for(int i = 1; i <= bounds[0]; i++)
		temp[i] = 1;
	for(int i = 1; i < 4; i++) {
		for(int j = 2; j <= bounds[i - 1]; j++)
			temp[j] += temp[j - 1];
		for(int j = bounds[i - 1] + 1; j <= bounds[i]; j++) 
			temp[j] = temp[bounds[i - 1]];
	}
    long zero = 0;
	long total = accumulate(temp.begin(), temp.end(), zero);
    
	vector<vector<long>> memo(bounds[2] + 1, vector<long>(4096 + 1));
	for(int c = 1; c <= bounds[2]; c++) {
		for(int d = c; d <= bounds[3]; d++) {
			int temp = c ^ d;
			memo[c][temp]++;
		}
	}

	for(int c = bounds[2] - 1; c >= 1; c--) {
		for(int val = bounds[3]; val >= 0; val--) {
			memo[c][val] += memo[c + 1][val];
		} 
	}

	long subtract_val = 0;
	for(int a = 1; a <= bounds[0]; a++) {
		for(int b = a; b <= bounds[1]; b++) {
			int temp = a ^ b;
			int temp_2 = memo[b][temp];
			subtract_val += temp_2;
		}
	}
	
	cout << total - subtract_val << endl;
}
