#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> balls(N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &balls[i]);
		balls[i]--;	
	}

	vector<int> count(N);
	for(int i = 0; i < N; i++) {
		vector<int> M(N);
		int best_color;
		int max_count = 0;
	
		for(int j = i; j < N; j++) {
			M[balls[j]]++;
			if(M[balls[j]] > max_count or (M[balls[j]] == max_count and balls[j] < best_color) ) {
				max_count = M[balls[j]];
				best_color = balls[j];
			}
			count[best_color]++;
		}		
	}

	for(int i = 0; i < N; i++) {
		printf("%d", count[i]);
		printf(i == N - 1 ? "\n" : " ");
	}
}
