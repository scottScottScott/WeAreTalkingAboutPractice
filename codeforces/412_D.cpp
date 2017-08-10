#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(2);

int getMax(int good, int all) {
	int denom = 32;
	int points = 3000;
	while(denom >= 2) {
		if(denom * good <= all)
			return points;
		points -= 500;
		denom /= 2;
	}
	return points;
}

bool getScores(int total, vector<int> scores) {
	vector<int> result(2);
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			if(memo[i][j] == -1) continue;
			int maxP = getMax(scores[j], total);
			result[i] += maxP - maxP / 250 * memo[i][j];
		}	
	}
	return result[0] > result[1];
}

int main() {
	int N;
	cin >> N;
	vector<int> solved(5);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 5; j++) {
			int temp;
			cin >> temp;
			if(i < 2) {
				memo[i].push_back(temp);
			}
			if(temp != -1)
				solved[j]++;
		}
	}
	int result = -1;
	for(int i = 0; i <= 120 * 32; i++) {
		vector<int> temp = solved;
		for(int j = 0; j < 5; j++) {
			if(memo[0][j] != -1 and memo[1][j] != -1) {
				if(memo[0][j] > memo[1][j])
					temp[j] += i;
			}
		}
		bool valid = getScores(i + N, temp);
		if(valid) {
			result = i;
			cout << result << endl;
			return 0;
		}
	}
	cout << result << endl;
}
