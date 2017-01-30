#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int total = accumulate(a.begin(), a.end(), 0);
	int people = n / 2;
	int sum = total / people;
	vector<bool> used(n);
	for(int i = 0; i < n; i++) {
		if(used[i] == 1) continue;
		used[i] = 1;
		cout << i + 1 << " ";
		for(int j = i + 1; j < n; j++) {
			if(used[j] == 0 and a[i] + a[j] == sum) {
				used[j] = 1;
				cout << j + 1 << endl;
				break;
			}
		}
	}
}
