#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#include <deque>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

class Fenwick {
	public:
		Fenwick(int n) {
			this->n = n;
			storage.resize(n + 1);
		}
		void update(int i, int val) {
			for( ; i <= n; i += -i & i)
				storage[i] += val;
		}
		int sum(int i) {
			int result = 0;
			for( ; i > 0; i -= -i & i)
				result += storage[i];	
			return result;
		}
	private:
		vector<int> storage;
		int n;
};

int main() {
	deque<vector<int>> col, row;
	int n; 
	cin >> n;
	for(int i = 0; i < n; i++) {
		pii a, b;
		scanf("%d %d %d %d", &a.first, &a.second, &b.first, &b.second);
		if(a.first == b.first) {
			vector<int> temp{a.first, min(a.second, b.second), max(a.second, b.second)};
			col.push_back(temp);
		}
		else {
			vector<int> temp{a.second, min(a.first, b.first), max(a.first, b.first)};
			row.push_back(temp);
		}
	}
	sort(col.begin(), col.end());
	sort(row.begin(), row.end());
	vector<int> prev;
	vector<pii> memo;
	ll area = 0;
	int next = 0;
	map<int, int> M, R;
	while(!col.empty()) {
		vector<int> curr = col.front();	
		col.pop_front();
		if(prev.empty() or curr[0] > prev[0] or curr[1] > prev[2]) {
			if(!prev.empty()) {
				if(!M.count(prev[0])) {
					R[next] = prev[0];
					M[prev[0]] = next;
					next++;
				}
				memo.emplace_back(prev[1], prev[0]);
				memo.emplace_back(prev[2] + 1, prev[0]);
				area += prev[2] - prev[1] + 1;
			}
			prev = curr;
		}
		else
			prev[2] = max(curr[2], prev[2]);

		if(col.empty()) {
			if(!M.count(prev[0])) {
				R[next] = prev[0];
				M[prev[0]] = next;
				next++;
			}
			memo.emplace_back(prev[1], prev[0]);
			memo.emplace_back(prev[2] + 1, prev[0]);
			area += prev[2] - prev[1] + 1;
		}
	}

	n = row.size();	
	prev.clear();
	for(int i = 0; i < n; i++) {
		vector<int> curr = row.front();	
		row.pop_front();
		if(prev.empty() or curr[0] > prev[0] or curr[1] > prev[2]) {
			if(!prev.empty()) row.emplace_back(prev);
			prev = curr;
		}
		else
			prev[2] = max(curr[2], prev[2]);

		if(i == n - 1)
			row.emplace_back(prev);
	}

	Fenwick F(next);
	vector<bool> light(next);
	vector<int> val(next);
	for(int i = 0; i < next; i++)
		val[i] = R[i];
	sort(memo.begin(), memo.end());
	deque<pii> Q(memo.begin(), memo.end());
	while(!row.empty()) {
		vector<int> curr = row.front();
		row.pop_front();
		while(!Q.empty() and Q.front().first <= curr[0]) {
			int x = M[Q.front().second];
			Q.pop_front();
			F.update(x + 1, light[x] ? -1 : 1);
			light[x] = !light[x];
		}
		int right = upper_bound(val.begin(), val.end(), curr[2]) - val.begin();
		int left = lower_bound(val.begin(), val.end(), curr[1]) - val.begin();
		int block = F.sum(right) - F.sum(left);
		area += (curr[2] - curr[1] + 1) - block;
	}
	cout << area << endl;
}
