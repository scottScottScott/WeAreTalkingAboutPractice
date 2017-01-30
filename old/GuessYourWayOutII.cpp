#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

void merge(vector<pll> &v) {
	sort(v.begin(), v.end());
	int n = v.size();
	vector<pll> result;
	int curr = 0;
	while(curr < n) {
		int next = curr + 1;
		while(next < n and v[next].first <= v[curr].second + 1) {
			v[curr].second = max(v[next].second, v[curr].second);	
			next++;
		}
		result.push_back(v[curr]);
		curr = next;
	}
	v = move(result);
}

void intersect(vector<pll> &v) {
	sort(v.begin(), v.end());
	int n = v.size();
	vector<pll> result;
	int curr = 0;
	while(curr < n) {
		int next = curr + 1;
		pll a = v[curr];
		while(next < n and v[next].first <= v[curr].second) {
			a.first = v[next].first;
			a.second = min(v[next].second, a.second);	
			next++;
		}
		result.push_back(a);
		curr = next;
	}
	v = move(result);
}

void update(pll &curr) {
	curr.first = curr.first * 2;
	curr.second = curr.second * 2 + 1;
}

ll diff(pll &curr) {
	ll result = curr.second - curr.first + 1;	
	return result;
}

int main() {
	string cheat = "Game cheated!";
	string mystery = "Data not sufficient!";
	int h, q;	
	cin >> h >> q;
	vector<vector<pll>> valid(h + 1);
	vector<vector<pll>> invalid(h + 1);
	for(int i = 0; i < q; i++) {
		int level;
		pll temp;
		bool T;
		cin >> level >> temp.first >> temp.second >> T;
		if(T) valid[level].push_back(temp);
		else invalid[level].push_back(temp);
	}
	pll good {-1, -1};
	vector<pll> bad;
	pll range;
	for(int i = 1; i <= h; i++) {
		if(i == 1) range.first = range.second = 1;
		else update(range);
		if(good.first != -1)
			update(good);
		for(pll &curr : bad)
			update(curr);
		for(pll &curr : invalid[i])
			bad.push_back(curr);
		if(good.first != -1)
			valid[i].push_back(good);
		if(valid[i].empty()) continue;
		intersect(valid[i]);
		if(valid[i].size() != 1) {
			cout << cheat << endl;
			return 0;
		}
		good = valid[i].front();
	}

	merge(bad);
	if(good.first == -1) {
		if(bad.size() == 1 and bad.front() == range)
			cout << cheat << endl;
		else if(bad.size() == 1 and diff(bad.front()) == diff(range) - 1) {
			if(bad.front().first > range.first)
				cout << range.first << endl;
			else
				cout << range.second << endl;
		}
		else if(bad.size() == 2 and diff(bad.front()) + diff(bad.back()) == diff(range) - 1)
			cout << bad.front().second + 1 << endl;
		else if(bad.size() == 0 and diff(range) == 1) 
			cout << 1 << endl;
		else
			cout << mystery << endl;
	}	
	else {
		for(pll curr : bad) {
			if(curr.first <= good.first and curr.second >= good.first) {
				good.first = curr.second + 1;
				if(good.first > good.second) break;
			}
			else if(curr.first > good.first and curr.first <= good.second) {
				if(curr.second < good.second) {
					cout << mystery << endl;
					return 0;
				}
				good.second = curr.first - 1;
			}
		}
		if(good.first == good.second)
			cout << good.first << endl;
		else if(good.first < good.second)
			cout << mystery << endl;
		else
			cout << cheat << endl;
	}
}
