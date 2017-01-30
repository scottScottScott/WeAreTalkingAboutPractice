#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N, B, T;
	long long A;
	cin >> N >> A >> B >> T;
	string S;
	cin >> S;

	int time_1 = 1 + (S[0] == 'w' ? B : 0);	
	T -= time_1;
	if(T < 0) {
		cout << 0 << endl;
		return 0;
	}
	int max_photos = 1;
	
	int index = 1;
	int cost = 0;;
	for( ; index < N; index++) {
		int newCost = 1 + (S[index] == 'w' ? B : 0);
		if(T < cost + newCost +  index * A) break;
		else cost += newCost;
	}
	max_photos = max(max_photos, index);
	if(max_photos == N) {
		cout << N << endl;
		return 0;
	}

	index--;
	int second_index = N - 1;
	while(index >= 0) {
		int newCost = 1 + (S[second_index] == 'w' ? B : 0);
		while( T >= cost + newCost + A * (index + N - second_index) + A * min(index, N - second_index) ) {
			cost += newCost;
			second_index--;
			newCost = 1 + (S[second_index] == 'w' ? B : 0);
		}
		int curr_photos = index + (N - second_index);
		max_photos = max(max_photos, curr_photos);

		cost -= 1 + (S[index] == 'w' ? B : 0);
		index--;
	}

	cout << max_photos << endl;
}
