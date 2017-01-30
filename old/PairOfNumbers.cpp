#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<int> left(n);
	for(int i = 1; i < n; i++) {
		int curr = i;
		while(curr - 1 >= 0 and a[curr - 1] % a[i] == 0)
			curr = left[curr - 1];
		left[i] = curr;
	}
	vector<int> right(n);
	for(int i = n - 1; i >= 0; i--) {
		int curr = i;
		while(curr + 1 < n and a[curr + 1] % a[i] == 0)
			curr = right[curr + 1];
		right[i] = curr;
	}
	vector<int> length(n);
	for(int i = 0; i < n; i++)
		length[left[i]] = max(length[left[i]], right[i] - left[i]);
	int result = *max_element(length.begin(), length.end());
	int count = 0;
	for(int x : length)
		if(x == result) count++;
	cout << count << " " << result << endl;
	for(int i = 0; i < n; i++) {
		if(length[i] == result) {
			count--;
			printf("%d", i + 1);
			printf(count == 0 ? "\n" : " ");
		}
	}
}
