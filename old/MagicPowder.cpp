#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tpl;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	vector<int> B(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	vector<tpl> info;
	for(int i = 0; i < N; i++) {
		int cookies = B[i] / A[i];
		int extra = B[i] % A[i];
		info.emplace_back(cookies, extra, A[i]);
	}	
	sort(info.begin(), info.end());

	int currCookies = -1;
	long long total = 0;
	long long needed = 0;
	for(int i = 0; i < N; i++) {
		int newCookies = get<0>(info[i]);
		if(currCookies == -1 or newCookies == currCookies) {
			total += get<1>(info[i]);
			needed += get<2>(info[i]);
			currCookies = newCookies;
		}
		else {
			int change = newCookies - currCookies;
			long long choco_chip = change * needed - total;
			if(choco_chip <= K) {
				K -= choco_chip;
				total = get<1>(info[i]);
				needed += get<2>(info[i]);
				currCookies = newCookies;
			}
			else break;
		}
	}

	if(K >= needed - total) {
		currCookies++;
		K -= needed - total;
	}
	currCookies += K / needed;

	cout << currCookies << endl;
}
