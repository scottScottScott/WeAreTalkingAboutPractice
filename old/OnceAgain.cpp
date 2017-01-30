#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_A = 300;

int main() {
	int N, T;
	cin >> N >> T;
	vector<int> A(N);
	map<int, int> M;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		M[A[i]]++;
	}
	int repeat;
	if(T <= 200) repeat = T;
	else repeat = 200;
	T -= repeat;

	for(int t = 2; t <= repeat; t++) {
		for(int i = 0; i < N; i++)
			A.push_back(A[i]);
	}

	vector<int> increase(A.size());
	vector<int> best(MAX_A + 1);
	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j <= A[i]; j++)
			increase[i] = max(increase[i], 1 + best[j]);
		best[A[i]] = increase[i]; 
	}
	vector<int> decrease(A.size());
	best.clear();
	best.resize(MAX_A + 1);
	for(int i = A.size() - 1; i >= 0; i--) {
		for(int j = A[i]; j <= MAX_A; j++)
			decrease[i] = max(decrease[i], 1 + best[j]);
		best[A[i]] = decrease[i];
	}

	int result = 0;
	for(int i = 0; i < A.size(); i++) {
		int temp = increase[i] + M[A[i]] * T  + decrease[i] - 1;
		result = max(result, temp);
	}
	cout << result << endl;
}
