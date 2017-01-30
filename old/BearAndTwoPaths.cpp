#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &V, int i, int j) {
	int temp = V[i];
	V[i] = V[j];
	V[j] = temp;
}

int main() {
	int N, K;
	cin >> N >> K;
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	vector<int> first;
	vector<int> second;
	if(N > 4 and K >= N + 1) {
		first.push_back(A);
		first.push_back(C);
		for(int n = 1; n <= N; n++) {
			if(n != A and n != B and n != C and n != D)
				first.push_back(n);
		}
		first.push_back(D);
		first.push_back(B);

		second = first;
		swap(second, 0, 1);
		swap(second, N - 1, N - 2);
	}
	else {
		cout << -1 << endl;
		return 0;
	}

	for(int i = 0; i < first.size(); i++) {
		printf("%d", first[i]);
		printf(i == first.size() - 1 ? "\n" : " ");
	}
	for(int i = 0; i < first.size(); i++) {
		printf("%d", second[i]);
		printf(i == first.size() - 1 ? "\n" : " ");
	}
}
