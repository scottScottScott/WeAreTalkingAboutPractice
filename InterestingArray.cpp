#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Fenwick {
	public:
		Fenwick(int size) {
			storage.resize(size + 1);
			n = size;
		}
		void update(int i, int val) {
			for( ; i <= n; i += i & -i)
				storage[i] += val;
		}
		int sum(int i) {
			int result = 0;
			for( ; i > 0; i -= i & -i)
				result += storage[i];
			return result;
		}
	private:
		vector<int> storage;
		int n;
};

void update(vector<int> &count, int val, int type, int &curr) {
	for(int i = 0; i < 30; i++) {
		bool bit = (val >> i) & 1;
		if(bit == 0) continue;
		if(type == 0) {
			if(count[i] == 0)
				curr |= 1 << i;
			count[i]++;
		}
		else {
			if(count[i] == 1)
				curr ^= 1 << i;
			count[i]--;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;	
	vector<vector<int>> segments;
	vector<vector<int>> info;
	vector<int> count(30);
	vector<int> a(n + 1);
	for(int i = 0; i < m; i++) {
		int l, r, val;
		scanf("%d %d %d", &l, &r, &val);
		segments.push_back(vector<int> {l, val, 0});
		segments.push_back(vector<int> {r + 1, val, 1});
		info.push_back(vector<int> {l, r, val});
	}	
	sort(segments.begin(), segments.end());
	deque<vector<int>> Q(segments.begin(), segments.end());
	sort(info.begin(), info.end());
	int curr = 0;
	for(int i = 1; i <= n; i++) {
		while(!Q.empty() and (Q.front())[0] == i) {
			vector<int> temp = Q.front();
			Q.pop_front();
			update(count, temp[1], temp[2], curr);
		}
		a[i] = curr;
	}
	vector<Fenwick> F(30, Fenwick(n));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 30; j++)
			F[j].update(i, (a[i] >> j) & 1);
	}
	Q.clear();
	Q.assign(info.begin(), info.end());
	for(int i = 1; i <= n; i++) {
		while(!Q.empty() and (Q.front())[0] == i) {
			int val = 0;
			vector<int> temp = Q.front();
			Q.pop_front();
			for(int j = 0; j < 30; j++) {
				int valid = F[j].sum(temp[1]);
				if(valid == temp[1] - temp[0] + 1) 
					val |= 1 << j;
			}
			if(val != temp[2]) {
				cout << "NO" << endl;
				return 0;
			}
		}
		for(int j = 0; j < 30; j++)
			F[j].update(i, ((a[i] >> j) & 1) == 1 ? -1 : 0);
	}
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) {
		printf("%d", a[i]);
		printf(i != n ? " " : "\n");
	}
	return 0;
}
