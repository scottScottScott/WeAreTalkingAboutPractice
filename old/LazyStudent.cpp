#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tpl;

int main() {
	int N, M;
	cin >> N >> M;
	vector<pii> MST;
	vector<pii> other;
	for(int i = 0; i < M; i++) {
		int W;
		bool inTree;
		cin >> W >> inTree;
		if(inTree)
			MST.emplace_back(W, i);
		else
			other.emplace_back(W, i);
	}

	vector<tpl> result;
	vector<tpl> I;

	sort(MST.begin(), MST.end());
	for(int i = 0; i < MST.size(); i++)
		result.emplace_back(MST[i].second, i, N - 1);

	int curr_edge = 0;
	for(int i = 1; i < MST.size(); i++) {
		for(int j = 0; j < i; j++) {
			I.emplace_back(MST[i].first, i, j);
			curr_edge++;
		}
		if(curr_edge >= M) break;
	}

	sort(other.begin(), other.end());
	sort(I.begin(), I.end());
	for(int i = 0; i < other.size(); i++) {
		if(other[i].first < get<0>(I[i])) {
			cout << -1 << endl;
			return 0;
		}
		result.emplace_back(other[i].second, get<1>(I[i]), get<2>(I[i]));
	}

	sort(result.begin(), result.end());
	for(tpl curr : result)
		cout << get<1>(curr) + 1 << " " << get<2>(curr) + 1 << endl;
}
