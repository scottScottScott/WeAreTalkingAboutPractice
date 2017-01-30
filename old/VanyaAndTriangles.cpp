#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

double const eps = 1e-5;

int getGCD(int a, int b) {
	if(b != 0) return getGCD(b, a % b);
	return a;
}

void simplify(int &a, int &b) {
	if(a == 0) {
		b = 1; 
		return;
	}
	if(b == 0) {
		a = 1;
		return;
	}
	int gcd = getGCD(abs(a), abs(b));
	a /= gcd;
	b /= gcd;
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> grid(201, vector<int>(201, -1));
	vector<pii> p;
	vector<vector<bool>> v(N, vector<bool>(N));
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		x += 100; y += 100;
		p.emplace_back(x, y);
		grid[x][y] = i;
	}
	int total = (long long) N * (N - 1) * (N - 2) / 6;
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(v[i][j]) continue;
			int sy = p[j].second - p[i].second;
			int sx = p[j].first - p[i].first;
			simplify(sy, sx);
			vector<int> temp;
			for(pii inc : { pii{sx, sy}, pii{-sx, -sy} }) {
				int cx = p[i].first;
				int cy = p[i].second;
				while(cx <= 200 and cy <= 200 and cx >= 0 and cy >= 0) {
					if(grid[cx][cy] != -1)
						temp.push_back(grid[cx][cy]);
					cx += inc.first;
					cy += inc.second;
				}
			}
			int count = temp.size() - 1;
			for(int a : temp) {
				for(int b : temp) {
					v[a][b] = 1;
					v[b][a] = 1;
				}
			}
			total -= (long long) count * (count - 1) * (count - 2) / 6;
		}
	}
	cout << total << endl;
}
