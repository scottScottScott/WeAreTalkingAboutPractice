#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<double, double> pdd;

double dist(pdd one, pdd two) {
	return sqrt(pow(one.first - two.first, 2) + pow(one.second - two.second, 2));
}

int main() {
	pdd A, B, T;	
	int N;
	cin >> A.first >> A.second >> B.first >> B.second >> T.first >> T.second;
	cin >> N;
	vector<double> distT(N);
	vector<vector<double>> distAB(2, vector<double>(N));

	for(int i = 0; i < N; i++) {
		pdd curr;
		scanf("%lf %lf", &curr.first, &curr.second);
		distT[i] = dist(T, curr);
		distAB[0][i] = distT[i] - dist(A, curr);
		distAB[1][i] = distT[i] - dist(B, curr);
	}

	double totalT = 2 * accumulate(distT.begin(), distT.end(), 0.0);
	double result;

	for(int X : {0, 1}) {
		int Y = (X + 1) % 2;
		vector<int> best(2);
		best[X] = 0; best[Y] = -1;
		for(int i = 0; i < N; i++)
			if(distAB[X][i] > distAB[X][best[X]]) best[X] = i;
		for(int i = 0; i < N; i++) {
			if(i == best[X] or distAB[Y][i] < 0) continue;
			else if(best[Y] == -1 or distAB[Y][i] > distAB[Y][best[Y]]) best[Y] = i;
		}
			
		double temp = totalT - distAB[X][best[X]] + (best[Y] == -1 ? 0 : -distAB[Y][best[Y]]);
		result = (X == 0 ? temp : min(temp, result));
	}
	
	cout << fixed << setprecision(9) << result << endl;
}
