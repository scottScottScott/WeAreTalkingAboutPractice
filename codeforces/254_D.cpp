#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll x;

ll getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

void swap(int &A, int &B) {
	int temp = A;
	A = B;
	B = temp;
}

int main() {
	ios::sync_with_stdio(false);
	int n, d;
	cin >> n >> d >> x;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		a[i] = i + 1;
	for(int i = 0; i < n; i++)
		swap(a[i], a[getNextX() % (i + 1)]);
	for(int i = 0; i < n; i++)
		b[i] = i < d;
	for(int i = 0; i < n; i++)
		swap(b[i], b[getNextX() % (i + 1)]);
	int bCnt = 0;
	vector<int> bIdx;
	set<pii> S;
	for(int i = 0; i < n; i++) {
		bCnt += b[i];
		S.emplace(a[i], i);
		int mVal = 0;
		if(bCnt < 2000) {
			if(b[i]) bIdx.push_back(i);
			for(int j : bIdx)
				mVal = max(mVal, a[i - j]);
		}
		else {
			for(set<pii>::reverse_iterator itr = S.rbegin(); itr != S.rend(); itr++) {
				pii temp = *itr;		
				int j = itr->second;
				if(b[i - j]) {
					mVal = itr->first;
					break;
				}
			}
		}
		cout << mVal << endl;
	}
}
