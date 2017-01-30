#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

typedef pair<double, double> pdd;

const double PI = 3.14159265358979323846;

double square(double A) {
	return A * A;
}

double calcDSq(pdd A, pdd B)  {
	return square(A.first - B.first) + square(A.second - B.second);
}

struct Vec {
	Vec(pdd A, pdd B) : start(A), end(B) {
		dist.first = end.first - start.first;
		dist.second = end.second - start.second;
	}

	pdd scale(double U) {
		pdd result {start.first + dist.first * U, start.second + dist.second * U};
		return result;
	}
	
	pdd start, end, dist;
};

double dot(Vec A, Vec B) {
	return A.dist.first * B.dist.first + A.dist.second * B.dist.second;
}

int main() {
	int N;
	pdd root;
	double minDist, maxDist, currMinDist, currMaxDist;
	cin >> N >> root.first >> root.second;
	vector<pdd> points(N);
	for(int i = 0; i < N; i++)
		scanf("%lf %lf", &points[i].first, &points[i].second);
	for(int i = 0; i < N; i++) {
		pdd A = points[i];
		pdd B = (i + 1 == N ? points[0] : points[i + 1]);
		currMaxDist = currMinDist = calcDSq(A, root);

		if(i == 0) minDist = maxDist = currMaxDist;

		Vec AB(A, B);
		Vec AR(A, root);
		double U = dot(AB, AR) / calcDSq(A, B);
		if(0 < U and U < 1) minDist = min(minDist, calcDSq(AB.scale(U), root));
		minDist = min(minDist, currMinDist);
		maxDist = max(maxDist, currMaxDist);
	}
	double result = (maxDist - minDist) * PI;
	cout << fixed << setprecision(9) << result << endl;
}
