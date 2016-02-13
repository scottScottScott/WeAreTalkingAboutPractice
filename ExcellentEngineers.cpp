#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

class Fenwick {	
	public:	
		Fenwick(int N) {
			storage.resize(N + 1, 100001);
		}

		void update(int i, int x) {
			for( ; i < storage.size() ; i += i & -i) 
				storage[i] = min(storage[i], x);
		}

		int getMin(int i) {
			int minVal = storage[i];
			for ( ; i > 0 ; i -= i & -i)
				minVal = min(minVal, storage[i]);
			return minVal;
		}

	private:
		vector<int> storage;
};

int main() {
	
	int T;
	cin >> T;
	while(T--) {
		int N;		
		cin >> N;
		
		vector<pii> skill_2;
		unordered_map<int, int> skill_3;

		Fenwick FTree(N);

		for(int n = 0; n < N; n++) {
			int r1, r2, r3;
			cin >> r1 >> r2 >> r3;
			skill_2.emplace_back(r1, r2);
			skill_3[r2] = r3;
		}

		sort(skill_2.begin(), skill_2.end());

		int listSize = 0;	
		for(int n = 0; n < skill_2.size(); n++) {
			// cout << skill_2[n].first << " " << FTree_2.getMin(n + 1) << endl;
			
			FTree.update(skill_2[n].second, skill_3[skill_2[n].second]);	
			
			if( FTree.getMin(skill_2[n].second) == skill_3[skill_2[n].second] ) {
				listSize++;
			}
		}

		cout << listSize << endl;
	}
}
