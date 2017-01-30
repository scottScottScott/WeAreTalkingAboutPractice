#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

class Fenwick {
	public:

	Fenwick(int N) {
		this->N = N;
		storage.resize(N + 1);
	}

	void update(int A) {
		for(int i = A; i <= N; i += i & -i)
			storage[i] += 1;
	}

	int sum(int A) {
		int result = 0;
		for(int i = A; i > 0; i -= i & -i)	
			result += storage[i];
		return result;
	}

	private:
		int N;
		vector<int> storage;
};

int main() {
	int N;
	cin >> N;
	
	vector<pii> segments;
	vector<int> right;
	map<int, int> M;
	map<int, int> M_2;
	for(int i = 0; i < N; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		segments.emplace_back(A, B);
		right.push_back(B);
		M_2[B] = i;
	}
	sort(right.begin(), right.end());
	for(int i = 0; i < right.size(); i++) {
		M[right[i]] = i + 1;
	}

	sort(segments.rbegin(), segments.rend());

	Fenwick F(N);
	vector<int> result(N);
	for(pii curr : segments) {
		int R = M[curr.second];
		int temp = F.sum(R);
		F.update(R);
		result[M_2[curr.second]] = temp;
	}
	
	for(int X : result)
		printf("%d\n", X);
}
