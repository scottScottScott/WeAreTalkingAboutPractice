#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> C(n);
	for(int i = 0; i < n; i++)
		cin >> C[i];
	const int MAX = 5e5;
	vector<bool> V(MAX + 1);
	V[0] = 1;
	for(int X : C) {
		for(int i = MAX; i >= X; i--) {
			if(V[i - X])
				V[i] = 1;
		}
	}
	vector<int> temp;
	for(int i = 0; i <= MAX; i++)
		if(V[i]) temp.push_back(i);
	int curr = 0;
	int steps = 0;
	while(true) {
		auto itr = lower_bound(temp.begin(), temp.end(), curr + d);
		if(itr != temp.begin() and (itr == temp.end() or *itr > curr + d)) itr--;
		int longest = *itr;
		if(longest == curr)
			break;
		curr = longest;
		steps++;
	}
	cout << curr << " " << steps << endl;
}
