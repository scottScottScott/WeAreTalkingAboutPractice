#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	ifstream fin("fence9.in");
	ofstream fout("fence9.out");

	double N, M, P;
	fin >> N >> M >> P;
	
	int numPts = 0;
	for(int y = 1; y < M; y++) {
		int left = floor( (N * y) / M + 1);
		int right = ceil( P - y * (P - N) / M - 1);
		numPts += right - left + 1;
	}
	fout << numPts << endl;

	return 0;
}
