#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int maxMin = n / m;
	vector<int> A(n);
	vector<int> count(m + 1);
	vector<int> changeable;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		if(A[i] <= m) {
			if(count[A[i]] == maxMin)
				changeable.push_back(i);
			else
				count[A[i]]++;
		}
		else
			changeable.push_back(i);
	}
	int result = 0;
	for(int i = 1; i <= m; i++) {
		while(count[i] < maxMin) {
			count[i]++;
			int j = changeable.back();
			changeable.pop_back();
			A[j] = i;
			result++;
		}
	}
	cout << maxMin << " " << result << endl;
	for(int i = 0; i < n; i++)
		cout << A[i] << (i + 1 != n ? " " : "\n");
}
