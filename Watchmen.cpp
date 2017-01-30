#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

long long countPair(vector<int> &A) {
	long long count = 0;
	int N = A.size();
	sort(A.begin(), A.end());
	int val = -1;
	long long rep = -1;
	for(int i = 0; i <= N; i++) {
		if(i == 0 or i == N or A[i] != val) {
			if(i != 0) {
				count += rep * (rep - 1) / 2;
			}
			if(i != N) {
				val = A[i];	
				rep = 1;
			}
		}
		else rep++;
	}
	return count;
}

int main() {
	int N;
	cin >> N;
		
	vector<pii> watch;
	vector<int> x_watch(N);
	vector<int> y_watch(N);
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		watch.emplace_back(x, y);
		x_watch[i] = x;
		y_watch[i] = y;
	}

	long long count = 0;
	count += countPair(x_watch);
	count += countPair(y_watch);

	sort(watch.begin(), watch.end());
	pii val {-1, -1};
	long long rep = -1;
	for(int i = 0; i <= N; i++) {
		if(i == 0 or i == N or watch[i] != val) {
			if(i != 0) {
				count -= rep * (rep - 1) / 2;
			}
			if(i != N) {
				val = watch[i];	
				rep = 1;
			}
		}
		else rep++;
	}

	cout << count << endl;
}
