#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> pts;
vector<int> mins;

int memo[10001];

int calcMax(int currMins) {
	if(memo[currMins] != -1)
		return memo[currMins];
	int maxPts = 0;
	for(int i = 0; i < N; i++) {
		if(currMins - mins[i] >= 0 && pts[i] + calcMax(currMins - mins[i]) > maxPts)
			maxPts = pts[i] + calcMax(currMins - mins[i]);
	}
	memo[currMins] = maxPts;
	return maxPts;
}

int main() {
	ifstream fin("inflate.in");	
	ofstream fout("inflate.out");

	int M;
	fin >> M >> N;
	pts.resize(N);
	mins.resize(N);
	for(int i = 0; i < N; i++) {
		fin >> pts[i];
		fin >> mins[i];
	}

	memset(memo, -1, sizeof(memo));
	memo[0] = 0;
	fout << calcMax(M) << endl;

	return 0;
}
