#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

deque<pii> R;

pii getI(vector<int> &temp) {
	int n = temp.size();
	int m1 = 0;
	for(int i = 0; i < n; i++) {
		if(temp[i] < temp[m1])
			m1 = i;
	}
	int m2 = (m1 + 1) % n;
	for(int i = 0; i < n; i++) {
		if(temp[i] < temp[m2] and i != m1)
			m2 = i;
	} 
	R.emplace_back(temp[m1], temp[m2]);
	return pii{min(m1, m2), max(m1, m2)};
}

void r_break(vector<int> &temp) {
	if(temp.size() <= 1)
		return;
	pii A = getI(temp);	
	vector<int> X(temp.begin() + A.first + 1, temp.begin() + A.second + 1);
	vector<int> Y(temp.begin() + A.second + 1, temp.end());
	Y.insert(Y.end(), temp.begin(), temp.begin() + A.first + 1);
	r_break(X);	
	r_break(Y);
}

int main() {
	int n;
	cin >> n;
	vector<int> P(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> P[i];
	int m;
	cin >> m;
	int swaps = 0;
	vector<int> V(n + 1);
	deque<int> Q;
	for(int i = 1; i <= n; i++) {
		if(V[i]) continue;
		V[i] = 1;
		Q.push_back(i);
		int length = 0;
		int curr = i;
		int next;
		vector<int> temp{i};
		while( (next = P[curr]) != curr and !V[next]) {
			length++;
			V[next] = true;
			curr = next;
			temp.push_back(curr);
		}
		r_break(temp);
		swaps += length;
	}
	int k = abs(m - swaps);
	vector<int> result;
	while(swaps < m) {
		int A = Q.front();		
		Q.pop_front();
		int B = Q.front();
		Q.pop_front();
		result.push_back(A);	
		result.push_back(B);
		Q.push_front(A);
		swaps++;
	}
	sort(R.begin(), R.end());
	while(swaps > m) {
		pii A = R.front();
		R.pop_front();
		result.push_back(A.first);	
		result.push_back(A.second);	
		swaps--;
	}
	cout << k << endl;
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << (i + 1 == result.size() ? "\n" : " ");
}
