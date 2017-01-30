#include <iostream>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	int n;
	cin >> n;
	unordered_map<ll, ll> M;
	pll curr;
	cin >> curr.first >> curr.second;
	priority_queue<pll, vector<pll>, greater<pll>> hiQ;
	priority_queue<pll, vector<pll>, less<pll>> loQ;
	for(int i = 1; i < n; i++) {
		ll t, w;	
		scanf("%lld %lld", &t, &w);
		M[t] += w - t + 1;
		if(t > curr.first) hiQ.emplace(w - t + 1, t);
		else loQ.emplace(t, w - t + 1);
	}
	int result = hiQ.size() + 1;
	while(!hiQ.empty()) {
		pll next = hiQ.top();
		hiQ.pop();
		if(next.first <= curr.first)
			curr.first -= next.first;	
		else 
			break;
		while(!loQ.empty() and loQ.top().first > curr.first) {
			pll next = loQ.top();
			loQ.pop();
			hiQ.emplace(next.second, next.first);
		}
		int place = hiQ.size() + 1;
		result = min(result, place);
	}	
	cout << result << endl;
}
