#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		ll total = 0;	
		vector<ll> b;
		for(int i = l + 1; i <= r; i++)
			b.push_back(abs(a[i] - a[i - 1]));
		int n = b.size();
		vector<int> right(n);
		vector<int> left(n);
		stack<pii> temp;
		for(int i = 0; i <= n; i++) {
			while(!temp.empty() and (i == n or b[i] >= temp.top().first)) {
				pii curr = temp.top();	
				temp.pop();
				left[curr.second] = i - curr.second;			
			}
			if(i == n) break;
			temp.emplace(b[i], i);
		}
		for(int i = n - 1; i >= -1; i--) {
			while(!temp.empty() and (i == -1 or b[i] > temp.top().first)) {
				pii curr = temp.top();	
				temp.pop();
				right[curr.second] = curr.second - i;			
			}
			if(i == -1) break;
			temp.emplace(b[i], i);	
		}
		for(int i = 0; i < n; i++)
			total += b[i] * left[i] * right[i];
		printf("%I64d\n", total);
	}
}
