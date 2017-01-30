#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

class AstronomicalRecords {
public:
	int minimalPlanets(vector <int>, vector <int>);
};

long GCD(long A, long B) {
	if(B == 0) return A;
	return GCD(B, A % B);
}

long LCM(long A, long B) {
	return A * B / GCD(A, B);
}

int AstronomicalRecords::minimalPlanets(vector<int> A, vector<int> B) {
	int result = A.size() + B.size();
	for(int i = 0; i <= A.size(); i++) {
		for(int j = 0; j <= B.size(); j++) {
			if(i == A.size() and j != B.size()) continue;
			if(i != A.size() and j == B.size()) continue;

			vector<long> temp_A(A.begin(), A.end());
			vector<long> temp_B (B.begin(), B.end());
			if(i != A.size() and j != B.size()) {
				long lcm = LCM(A[i], B[j]);
				long comp_A = lcm / A[i];
				long comp_B = lcm / B[j];
				for(long &X : temp_A)
					X *= comp_A;
				for(long &X : temp_B) 
					X *= comp_B;	
			}
						
			vector<int> memo(B.size());
			for(int k = 0; k < A.size(); k++) {
				int maxMatch = 0;
				for(int z = 0; z < B.size(); z++) {
					int temp = memo[z];
					if(temp_A[k] == temp_B[z])
						memo[z] = max(memo[z], maxMatch + 1);	
					maxMatch = max(maxMatch, temp);
				}
			}
			result = min(result, (int) A.size() + (int) B.size() - *max_element(memo.begin(), memo.end()));
		}
	}	
	return result;
}
