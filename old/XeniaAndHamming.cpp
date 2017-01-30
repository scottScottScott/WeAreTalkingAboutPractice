#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	ll n, m;
	cin >> n >> m;
	string x, y;
	cin >> x >> y;
	ll sx = x.size();
	ll sy = y.size();
	int G = gcd(sx, sy);
	ll segment = sx * sy / G;
	ll repeat = sx * n / segment;
	vector<vector<int>> count(G, vector<int>(26));
	for(int i = 0; i < G; i++) {
		int curr = i; 
		do {
			int c = x[curr] - 'a';
			count[i][c]++;
			curr = (curr + sy) % sx;
		} while(curr != i);
	}	
	ll result = 0;
	for(int i = 0; i < sy; i++) {
		int c = y[i] - 'a';
		result += count[i % G][c];
	}
	result *= repeat;
	cout << sx * n - result << endl;
}
