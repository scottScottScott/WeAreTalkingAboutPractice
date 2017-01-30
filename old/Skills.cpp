#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ll N, A, C1, C2, M;
	cin >> N >> A >> C1 >> C2 >> M;
	ll M_store = M;
	vector<pii> I(N);
	ll total = 0;
	for(int i = 0; i < N; i++) {
		scanf("%d", &I[i].first);
		total += I[i].first;
		I[i].second = i;
	}
	sort(I.begin(), I.end());

	if(total + M >= A * N) {
		cout << C1 * N + C2 * A << endl;
		for(int i = 0; i < N; i++) {
			printf("%I64d", A);
			printf(i + 1 == N ? "\n" : " ");
		}	
		return 0;
	}

	long long result = 0;
	for(int T : {1, 2} ) {
		M = M_store;	
		long long currVal = 0;
		vector<int> IB(N);
		for(int i = N - 1; i >= 0; i--) {
			int fill = A - I[i].first;
			if(M < fill) fill = M;
			else currVal += C1;
			M -= fill;
			IB[i] = I[i].first + fill;
		}

		long long next_i = 1;
		long long f_val = I[0].first;
		long long f_cnt = 1;
		for(int i = 0; i <= N; i++) {
			result = max(result, currVal + (f_val / f_cnt) * C2);
			if(T == 2 and result == currVal + (f_val / f_cnt) * C2) {
				for(int j = 0; j < f_cnt; j++)
					IB[j] = f_val / f_cnt;
				vector<int> answer(N);
				for(int j = 0; j < N; j++)
					answer[I[j].second] = IB[j];
				cout << result << endl;
				for(int j = 0; j < N; j++) {
					printf("%d", answer[j]);
					printf(j + 1 == N ? "\n" : " ");
				}
				return 0;
			}
			if(i == N) break;
			if(IB[i] == A) currVal -= C1;
			f_val += IB[i] - I[i].first;
			IB[i] = I[i].first;
			while( next_i <= i and (f_val / f_cnt) >= IB[next_i] ) {
				f_cnt++;
				f_val += IB[next_i];
				next_i++;
			}
		}
	}
}
