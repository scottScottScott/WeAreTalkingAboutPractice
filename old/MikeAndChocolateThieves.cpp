#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll M;
	cin >> M;
	
	ll result = -1;
	ll lo = 8;
	ll hi = M * 8;	
	while(lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		
		ll count = 0;
		ll K = 2; 	
		while(count <= M) {
			ll temp = K * K * K; 	
			if(mid < temp) break;
			ll temp_count = mid / temp;
			count += temp_count;
			K++;
		}

		if(count == M) {
			if(result == -1 or mid < result) result = mid;
			hi = mid - 1;
		}
		else if(count < M)
			lo = mid + 1;
		else if(count > M)
			hi = mid - 1;
	}
	cout << result << endl;
}
