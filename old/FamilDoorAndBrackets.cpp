#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

long long getVal(int left, int right, vector<vector<long long>> &memo) {
	if(right < 0 or left < 0) return 0;

	long long &curr = memo[left][right];
	if(curr != -1) return curr;

	if(right > left) curr = 0;
	else curr = getVal(left, right - 1, memo) + getVal(left - 1, right, memo);
	curr %= MOD;
	return curr;
}

int main() {
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;

	long long result = 0;
	const int MOD = 1e9 + 7;

	int left, right;
	left = right = 0;
	int diff = 0;
	for(char X : S) {
		if(X == '(') left++;
		else right++;

		if(right > left)
			diff = max(diff, right - left);
	}

	int P_left_min = diff;	
	int Q_right_min = left - (right - diff);
	int needed_length = N - M;

	vector<vector<long long>> memo(2001, vector<long long> (2001, -1));	
	memo[0][0] = 1;
	memo[1][0] = 1;

	for(int P = P_left_min; P <= needed_length - Q_right_min; P++) {
		int P_extra = P - P_left_min;	

		for(int P_left = 0; P_left <= P_extra; P_left++) {
			int Q_extra = needed_length - P - Q_right_min;
			int P_right = P_extra - P_left;
			if(P_right > P_left) continue;
			int left_carry = P_left - P_right;
						
			int Q_right = left_carry;
			Q_extra -= left_carry;
			if(Q_extra < 0 or Q_extra % 2 == 1) continue;
			int Q_left = Q_extra / 2;
			Q_right += Q_extra / 2;

			result = ( result + getVal(P_left + P_left_min, P_right, memo) * getVal(Q_right + Q_right_min, Q_left, memo) ) % MOD;
		}
	}

	cout << result << endl;
}
