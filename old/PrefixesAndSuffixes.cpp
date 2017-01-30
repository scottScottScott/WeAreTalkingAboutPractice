#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;	
	getline(cin, s);
	int n = s.size();

	vector<int> z(n);
	z[0] = n;
	int l, r;
	l = r = 0;
	int result = 0;
	for(int i = 1; i < n; i++) {
		if(i > r) {
			l = i;
			int j = i;
			while(j < n and s[j] == s[j - l]) {
				j++;
				z[i]++;	
			}
			j--;
			r = j;
		}
		else {
			int length = z[i - l];
			if(i + length - 1 >= r) {
				length = r - i + 1;
				while(i + length < n and s[i + length] == s[length])
					length++;
				l = i;
				r = i + length - 1;
			}
			z[i] = length;
		}
	}

	vector<int> count(n + 1);	
	for(int i = 0; i < n; i++)
		count[z[i]]++;
	for(int i = n - 1; i >= 0; i--)
		count[i] += count[i + 1];

	for(int i = n - 1; i >= 0; i--) {
		int length = n - i;
		if(z[i] == length)
			result++;
	}
	cout << result << endl;
	for(int i = n - 1; i >= 0; i--) {
		int length = n - i;
		if(z[i] == length)
			printf("%d %d\n", length, count[length]);
	}
}
