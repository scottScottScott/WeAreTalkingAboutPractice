#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

class Fenwick {
	public: 
		Fenwick(int n, int val) {
			storage.resize(n + 1, val);
			size = n;
		}
		void update_max(int i, int x) {
			for( ; i <= size; i += (i & -i))
				storage[i] = max(storage[i], x);
		}
		void update_min(int i, int x) {
			for( ; i <= size; i += (i & -i))
				storage[i] = min(storage[i], x);
		}
		int find_max(int i) {
			int result = storage[i];
			for( ; i > 0; i -= (i & -i))	
				result = max(result, storage[i]);
			return result;
		}
		int find_min(int i) {
			int result = storage[i];
			for( ; i > 0; i -= (i & -i))	
				result = min(result, storage[i]);
			return result;
		}
	private:
		vector<int> storage;
		int size;
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	ll result = 0;	
	Fenwick fa(n, INT_MIN);
	Fenwick fb(n, INT_MAX);
	for(int i = n; i >= 1; i--) {
		fa.update_max(i, a[i]);
		fb.update_min(i, b[i]);
		int lo = i;
		int hi = n;
		int firstMatch = -1;
		while(lo <= hi) {
			int mid = lo + (hi - lo) / 2;	
			int aval = fa.find_max(mid);
			int bval = fb.find_min(mid);
			if(aval == bval) {
				firstMatch = mid;
			}
			if(aval >= bval) hi = mid - 1;
			else lo = mid + 1;
		}
		if(firstMatch == -1) continue;
		lo = i;
		hi = n;
		int lastMatch = n + 1;
		while(lo <= hi) {
			int mid = lo + (hi - lo) / 2;	
			int aval = fa.find_max(mid);
			int bval = fb.find_min(mid);
			if(aval > bval)
				lastMatch = mid;
			if(aval > bval) hi = mid - 1;
			else lo = mid + 1;
		}
		result += lastMatch - firstMatch;
	}
	cout << result << endl;
}
