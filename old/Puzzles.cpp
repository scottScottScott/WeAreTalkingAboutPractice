#include <iostream>
#include <iomanip>
#include <deque>
#include <vector>

using namespace std;

int n;

void r_size(int i, vector<vector<int>> &children, vector<int> &size) {
	int &temp = size[i];
	temp = 1;
	for(int x : children[i]) {
		r_size(x, children, size);
		temp += size[x];	
	}	
}

int main() {
	cin >> n;
	vector<vector<int>> children(n);
	for(int i = 1; i < n; i++) {
		int p;
		scanf("%d", &p);
		p--;
		children[p].push_back(i);	
	}
	vector<int> size(n, -1);
	r_size(0, children, size);
	vector<double> EV(n);
	EV[0] = 1;
	deque<int> Q{0};
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		int numC = children[curr].size();
		int total = 0;
		for(int x : children[curr]) 
			total += size[x];
		for(int x : children[curr]) {
			double temp_total = total - size[x];
			temp_total /= 2;
			temp_total += EV[curr] + 1;
			EV[x] = temp_total;
			Q.push_back(x);
		}
	}
	for(int i = 0; i < n; i++) {
		if(i != 0) printf(" ");
		printf("%.7f", EV[i]);
	}
	cout << endl;
}
