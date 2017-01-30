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

class PrimeSoccer {
public:
	double getProbability(int, int);
};

bool isPrime(int x) {
	if(x == 0 or x == 1) return false;
	for(int i = 2; i < x; i++)
		if(x % i == 0) return false;
	return true;
}

double choose(int x, int y) {
	long result = 1;
	for(int i = x; i > x - y; i--) 
		result *= i;
	for(int i = y; i > 0; i--)
		result /= i;
	return result;
}

double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB) {
	double A = skillOfTeamA / 100.0;
	double B = skillOfTeamB / 100.0;

	double result = 0;
	for(int a = 0; a <= 18; a++) {
		for(int b = 0; b <= 18; b++) {
			if(!isPrime(a) and !isPrime(b)) continue;
			double temp = 1;
			for(int i = 1; i <= a; i++)
				temp *= A;
			for(int i = a + 1; i <= 18; i++)
				temp *= (1 - A);
			for(int i = 1; i <= b; i++)
				temp *= B;
			for(int i = b + 1; i <= 18; i++)
				temp *= (1 - B);
			temp *= choose(18, a) * choose(18, b);
			result += temp;
		}
	}	
	return result;
}



