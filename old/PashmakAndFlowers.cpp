#include <iostream>
#include <climits>

using namespace std;

int main() {
	int N;
	cin >> N;
	int lo = INT_MAX;
	int lo_cnt = 0;
	int hi = INT_MIN;
	int hi_cnt = 0;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
			
		if(temp < lo) {
			lo = temp;
			lo_cnt = 1;	
		}
		else if(temp == lo)
			lo_cnt++;

		if(temp > hi) {
			hi = temp;
			hi_cnt = 1;
		}
		else if(temp == hi)
			hi_cnt++;
	}

	long long solution = 0;
	if(lo == hi)
		solution = (long long) lo_cnt * (lo_cnt - 1) / 2;
	else
		solution = (long long) lo_cnt * hi_cnt;
	
	cout << hi - lo << " " << solution << endl;
}
