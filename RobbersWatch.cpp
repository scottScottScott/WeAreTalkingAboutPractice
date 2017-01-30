#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

void r_generate(int numDigits, string &curr, vector<bool> &used, vector<string> &storage) {
	if(curr.size() == numDigits) {
		storage.push_back(curr);
		return;
	}

	for(int i = 0; i <= 6; i++) {
		if(used[i] == 1) continue;
		used[i] = 1;
		curr += (i + '0');
		r_generate(numDigits, curr, used, storage);
		used[i] = 0;
		curr.pop_back();
	}
}

bool valid(string S, int val) {
	int currPow = 1;	
	int result = 0;
	for(int i = 0; i < S.size(); i++) {
		result += currPow * (S[i] - '0');
		currPow *= 7;
	}
	return (result <= val);
}

int getNumDigits(int N) {
	int result = 1;
	ll curr = 7;
	while(N >= curr) {
		result++;
		curr *= 7;
	}
	return result;
}

int main() {
	int N, M;
	cin >> N >> M;
	N--; M--;
	
	int dN = getNumDigits(N);
	int dM = getNumDigits(M);

	if(dN + dM > 7) {
		cout << 0 << endl;
		return 0;
	}

	string curr;
	vector<bool> used(7);
	vector<string> first, second;
	r_generate(dN, curr, used, first);
	r_generate(dM, curr, used, second);
	
	int result = 0;
	for(string &s : first) {
		if(!valid(s, N)) continue;
		for(string &t : second) {
			if(!valid(t, M)) continue;
			vector<bool> used(7);
			bool isGood = true;
			for(int i = 0; i < s.size(); i++) 
				used[s[i] - '0'] = 1;
			for(int i = 0; i < t.size(); i++) {
				if(used[t[i] - '0'] == 1) {
					isGood = false;
					break;
				}
			}
			if(isGood == false) continue;
			result++;
		}
	}

	cout << result << endl;
}
