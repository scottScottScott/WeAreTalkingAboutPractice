#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 1e5 * 2;

int main() {
	int n;
	cin >> n;
	vector<int> count(MAX);
	vector<vector<int>> info(MAX);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		count[temp]++;
		info[temp].push_back(i + 1);
	}
	vector<int> result;	
	int curr = -1;
	while(true) {
		bool validLoop = curr - 2 >= 0 and count[curr - 2] > 0 and count[curr - 1] > 0 and count[curr] > 0;
		if(validLoop) curr -= 3;
		else if(curr + 1 < MAX and count[curr + 1] > 0) {
			curr++;
			count[curr]--;
			result.push_back(info[curr].back());
			info[curr].pop_back();
		}
		else break;
	}
	while(curr + 1 >= 0) {
		if(curr + 1 < MAX and count[curr + 1] > 0) {
			curr++;
			count[curr]--;
			result.push_back(info[curr].back());
			info[curr].pop_back();
		}
		else curr -= 3;
	}

	if(accumulate(count.begin(), count.end(), 0) != 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	
	cout << "Possible" << endl;
	for(int i = 0; i < result.size(); i++) {
		if(i != 0) printf(" ");
		printf("%d", result[i]);
	}
	cout << endl;
}
