#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> start {2, 1};
	
	while(Q--) {
		int type;
		scanf("%d", &type);

		if(type == 1) {
			int amount;
			scanf("%d", &amount);
			for(int &X : start) {
				X += amount;
				X += N;
				X %= N;
			}
		}
		else {
			for(int &X : start) {
				if(X % 2 == 1) X++;
				else X--;
				
				X += N;
				X %= N;
			}
		}
	}

	start[0] -= 2;
	start[1] -= 1;
	for(int &X : start) {
		X += N;
		X %= N;
	}

	vector<int> memo(N + 1);
	for(int i = 1; i <= N; i++) {
		long long temp = i;
		temp += start[i % 2];	
		temp += N;
		temp %= N;
		if(temp == 0) temp = N;
		memo[temp] = i;
	}

	for(int i = 1; i <= N; i++) {
		printf("%d", memo[i]);
		if(i != N) printf(" ");
	}
	printf("\n");
}
