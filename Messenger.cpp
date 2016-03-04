#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<char, long long> pcl;

int main() {
	vector<int> input_size = {0, 0};
	cin >> input_size[0] >> input_size[1];
	
	int N;
	vector<vector<pcl>> S{{}, {}}; 
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < input_size[i]; j++) {
			int L;
			char C;
			cin >> L >> C >> C;
			if( (N = S[i].size()) == 0 or S[i][N - 1].first != C)
				S[i].emplace_back(C, L);
			else
				S[i][N - 1].second += L;	
		}
	}

	long long occur = 0;	
	vector<pcl> &str = S[1];

	if(str.size() == 1) {
		for(int i = 0; i < S[0].size(); i++) {
			if(S[0][i].first == str[0].first and S[0][i].second >= str[0].second)
				occur += S[0][i].second - str[0].second + 1;
		}
	}
	else {
		pcl front = str[0];
		pcl back = str.back();
		str.erase(str.begin());
		str.pop_back();
		int M = str.size();
		str.emplace_back('$', 1);
		str.insert(str.end(), S[0].begin(), S[0].end());

		N = str.size();
		vector<int> Z(N);
		Z[0] = N;

		int l, r;
		r = l = 0;
		for(int i = 1; i < N; i++) {
			if(i > r) {
				r = l = i;
				int start = 0;
				while(str[start] == str[r]) {
					start++;
					r++;
				}
				Z[i] = start;
			}
			else {
				if(Z[i - l] < r - i) {
					Z[i] = Z[i - l];
				}	
				else {
					l = i;
					while(str[r] == str[r - l])
						r++;
					Z[i] = r - l;
				}
			}
		}

		for(int i = 1; i + M < N; i++) {
			if(Z[i] == M) {
				if(str[i - 1].first == front.first and str[i - 1].second >= front.second) {
					if(str[i + M].first == back.first and str[i + M].second >= back.second) {
						occur++;
					}
				}
			}
		}	
	}

	cout << occur << endl;
}
