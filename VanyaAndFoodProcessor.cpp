#include <iostream>

using namespace std;

int main() {
	int N, H, K;
	cin >> N >> H >> K;

	long long result = 0;
	int curr_size = 0;
	for(int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if(curr_size + temp <= H)
			curr_size += temp;
		else {
			int max_size = H - temp;
			int extra = curr_size - max_size; 
			int time = extra / K;
			if(extra % K != 0) 
				time++;
			curr_size -= time * K;
			curr_size = max(curr_size, 0);
			curr_size += temp;
			result += time;
		}
	}
	result += curr_size / K;
	if(curr_size % K != 0) result++;

	cout << result << endl;
}
