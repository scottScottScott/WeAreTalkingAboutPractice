#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Entry {
	int first;
	int second;
	int p;
};

int cmp(Entry A, Entry B) {
	if(A.first == B.first)
		return A.second < B.second;
	return A.first < B.first;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		string temp;	
		cin >> temp;
		
		int N = temp.size();	
		vector<vector<int>> memo(1, vector<int> (N));
		for(int i = 0; i < N; i++) {
			if(temp[i] >= 'a' and temp[i] <= 'z')
				memo[0][i] = temp[i] - 'a';
			else
				memo[0][i] = temp[i] - 'A' + 26;
		}

		int width = 1;
		vector<struct Entry> L(N);
		int m_i = 0;
		while(width / 2 < N) {
				
			for(int i = 0; i < N; i++) {
				L[i].first = memo[m_i][i];
				L[i].second = i + width < N ? memo[m_i][i + width] : -1;
				L[i].p = i;
			}

			sort(L.begin(), L.end(), cmp);
				
			memo.push_back( vector<int> (N) );	
			m_i++;
			for(int i = 0; i < N; i++) {
				memo[m_i][L[i].p] = i > 0 and L[i].first == L[i - 1].first and L[i].second == L[i - 1].second ? memo[m_i][L[i - 1].p] : i;
			}			

			width *= 2;
		}

		vector<int> LCP = { 0 };
		for(int i = 1; i < N; i++) {

			int x = L[i].p;
			int y = L[i - 1].p;
			
			int similar = 0;
			for(int j = m_i; j >= 0 and x < N and y < N; j--) {
				if(memo[j][x] == memo[j][y]) {
					x += 1 << j;
					y += 1 << j;	
					similar += 1 << j;
				}
			}
			LCP.push_back(similar);
		}
	
		int count = 0;
		for(int i = 1; i < LCP.size(); i++) {
			int diff = LCP[i] - LCP[i - 1];
			if(diff > 0)
				count += diff;
		}
		
		cout << count << endl;
	}
}
