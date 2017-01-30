#include <iostream>
#include <vector>

using namespace std;

long GCD(long a, long b) {
	while(b != 0) {
		long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long LCM(long a, long b) {
	long gcd = GCD(a, b);
	return (a / gcd) * b;
}

int nextCard(int i, int n, int k) {
	int pile, extra, pileCnt, place;
	pile = i % k;
	extra = min(n % k, pile);
	pileCnt =  n / k + (n % k > pile ? 1 : 0);
	place = i / k;
	i = pile * (n / k) + extra + (pileCnt - 1 - place);
	return i;
}

int main() {
	int n, k;
	cin >> n >> k;
	while(n && k) {
		vector<bool> visited(n);	
		long lcm = 1;
		for(int i = 0; i < n; i++) {
			if(visited[i]) continue;
			visited[i] = 1;
			int j = nextCard(i, n, k);
			int rounds = 1;
			while(j != i) {
				visited[j] = 1;
				j = nextCard(j, n, k);
				rounds++;
			}
			lcm = LCM(lcm, rounds);
		}
		cout << lcm << endl;
		cin >> n >> k;
	}	
}
