#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	vector<int> visit(n + 1);	
	vector<int> loop, self;
	for(int i = 1; i <= n; i++) {
		if(visit[i] != 0) continue;
		visit[i] = i;
		deque<int> Q{i};
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			int next = a[curr];
			if(visit[next] == i) {
				if(next == curr)
					self.push_back(curr);
				else 
					loop.push_back(curr);
			}
			else if(visit[next] == 0){
				visit[next] = i;
				Q.push_back(next);
			}
		}
	}
	int result = loop.size() + (self.size() == 0 ? 0 : self.size() - 1);
	int parent = !self.empty() ? self.front() : loop.front();
	for(int x : loop) a[x] = parent;
	for(int x : self) a[x] = parent;
	cout << result << endl;
	for(int i = 1; i <= n; i++) {
		if(i != 1) printf(" ");
		printf("%d", a[i]);
	}
	cout << endl;
}
