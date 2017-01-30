#include <iostream>
#include <vector>

using namespace std;

int getNext(int p, vector<int> &next) {
	if(next[p] != p and next[p] != next.size())
		next[p] = getNext(next[p], next);	
	return next[p];
}

int main() {
	int n, m;
	cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	cin >> m;
	vector<int> next(n);
	for(int i = 0; i < n; i++) 
		next[i] = i;
	vector<int> amount(n);
	for(int i = 0; i < m; i++) {
		int type, p;
		scanf("%d %d", &type, &p);
		p--;
		if(type == 1) {
			int x;
			cin >> x;
			while(x > 0) {
				if(amount[p] < c[p]) {
					int need = c[p] - amount[p];
					int add = min(need, x);	
					amount[p] += add;
					x -= add;
					if(amount[p] == c[p])
						next[p] = p + 1;
				}
				else {
					p = getNext(p, next);
					if(p == n) break;	
				}
			}
		}
		else if(type == 2)
			printf("%d\n", amount[p]);
	}	
}
