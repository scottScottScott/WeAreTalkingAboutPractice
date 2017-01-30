#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

using namespace std;

int main() {
	int K;
	cin >> K;
	int N, M;
	vector<pii> edges;

	if(K % 2 == 1){
		N = 4 * K - 2;
		M = (N * K) / 2;			

		for(int i = 2; i <= K; i++)
			edges.emplace_back(1, i);
		for(int i = 2; i <= K; i++) {
			for(int j = K + 1; j <= 2 * K - 1; j++)
				edges.emplace_back(i, j);
		}
		for(int i = K + 1; i <= 2 * K - 1; i += 2)
			edges.emplace_back(i, i + 1);
	
		int add = 2 * K - 1;
		int temp = edges.size();
		for(int i = 0; i < temp; i++) {
			edges.emplace_back(edges[i].first + add, edges[i].second + add);
		}
		edges.emplace_back(1, 1 + add);
	}
	else {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	cout << N << " " << M << endl;
	for(pii curr : edges)
		printf("%d %d\n", curr.first, curr.second);
}
