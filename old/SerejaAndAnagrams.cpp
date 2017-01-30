#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> a(n);
	map<int, int> M;
	int need = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		if(!M.count(temp)) need++;
		M[temp]++;
	}
		
	vector<int> result;
	for(int i = 0; i < p; i++) {
		set<int> S;
		map<int, int> count;

		int num = 0;
		int start = i;
		for(int j = i; j < n; j += p) {
			if(num >= m) {
				int val = a[start];
				if(M.count(val)) {
					if(count[val] == M[val])
						S.erase(val);
					count[val]--;
				}
				start += p;
			}
			int temp = a[j];
			num++;
			if(M.count(temp)) {	
				count[temp]++;
				if(count[temp] == M[temp])
					S.insert(temp);	
			}
			if(S.size() == need)
				result.push_back(start);
		}
	}

	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for(int x : result)
		cout << x + 1 << (x == result.back() ? "\n" : " ");
}
