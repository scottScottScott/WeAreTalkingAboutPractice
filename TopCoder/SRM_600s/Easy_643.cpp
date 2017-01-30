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

void getPrimes(long long N, vector<long long> &result, int size) {
	for(long long i = 2; i * i <= N; i++) {
		if(N % i != 0) continue;
		while(N % i == 0) {
			N /= i;
			result.push_back(i);	
		}
		if(result.size() == size - 1 and N != 1) {
			result.push_back(N);
			return;
		}
	}
	if(N != 1)
		result.push_back(N);
}

class TheKingsFactorization {
public:
	 vector<long long> getVector(long long, vector<long long>);
};

vector<long long> TheKingsFactorization::getVector(long long N, vector<long long> primes) {
	vector<long long> result;
	for(int i = 0; i < primes.size(); i++) 
		N /= primes[i];
	vector<long long> temp;
	if(primes.size() == 1 and N != 1)
		temp.push_back(N);
	else
		getPrimes(N, temp, primes.size());
	for(int i = 0; i < primes.size(); i++) {
		result.push_back(primes[i]);
		if(i < temp.size())
			result.push_back(temp[i]);
	}
	return result;
}
