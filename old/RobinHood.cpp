#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;
	deque<int> wealth(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &wealth[i]);
	sort(wealth.begin(), wealth.end());

	if(N == 1) {
		cout << 0 << endl;
		return 0;
	}
	if(K == 0) {
		cout << wealth[N - 1] - wealth[0] << endl;
		return 0;
	}

	long long K_copy = K;

	long long curr_val = -1;
	long long curr_count = 0;
	long long curr_extra = 0;
	while(K > 0 and !wealth.empty()) {
		long long temp = wealth.back();	
		if(curr_val == -1) {
			curr_val = temp;
			curr_count = 1;
			curr_extra = 0;
			wealth.pop_back();
		}
		else if(curr_val == temp) {
			curr_count++;
			wealth.pop_back();
		}
		else if(curr_val > temp) {
			long long needed = (curr_val - temp) * curr_count;
			if(needed <= K) {
				K -= needed;
				curr_val = temp;
				curr_count++;
				wealth.pop_back();
			}
			else {
				curr_val -= K / curr_count;
				curr_extra = K % curr_count;
				if(curr_extra > 0) {
					curr_val--;
					curr_extra = curr_count - curr_extra;
				}
				K = 0;
			}
		}
	}
	
	if(K != 0) {
		curr_val -= K / curr_count;
		curr_extra = K % curr_count;
		if(curr_extra > 0) {
			curr_val--;
			curr_extra = curr_count - curr_extra;
		}
		K = 0;
	}

	K = K_copy;
	long long b_val = -1;
	long long b_count = 0;
	long long b_extra = 0;
	while(K > 0 and !wealth.empty()) {
		long long temp = wealth.front();
		if(b_val == -1) {
			b_val = temp;
			b_count = 1;	
			b_extra = 0;
			wealth.pop_front();
		}
		else if(b_val == temp) {
			b_count++;
			wealth.pop_front();
		}
		else if(b_val < temp) {
			long long needed = (temp - b_val) * b_count;
			if(needed <= K) {
				K -= needed;
				b_val = temp;
				b_count++;
				wealth.pop_front();
			}
			else {
				b_val += K / b_count;
				b_extra = K % b_count;
				K = 0;
			}
		}
	}

	if(b_val == -1) {
		cout << ( (curr_extra + K) % N != 0) << endl;
		return 0;
	}

	if(K != 0 and wealth.empty()) {
		long long needed = (curr_val - b_val) * curr_count;
		if(needed <= K + b_extra) {
			curr_extra += K - needed - b_extra;
			curr_extra %= N;
			b_val = curr_val;
		}
		else
			b_val += (K + b_extra) / b_count;
	}

	cout << curr_val - b_val + (curr_extra != 0) << endl;	
}
