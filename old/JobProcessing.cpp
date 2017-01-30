#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M1, M2;
vector<int> A;
vector<int> B;
vector<int> currA(30);
vector<int> currB(30);

int main() { 
	ifstream fin("job.in");
	ofstream fout("job.out");

	fin >> N >> M1 >> M2;

	for(int i = 0; i < M1; i++) {
		int temp;
		fin >> temp;
		A.push_back(temp);
	}

	for(int i = 0; i < M2; i++) {
		int temp;
		fin >> temp;
		B.push_back(temp);
	}

	vector<int> aTimes;
	vector<int> bTimes;

	for(int i = 0; i < N; i++) {
		int minTime;
		int index;
		for(int j = 0; j < M1; j++) {
			if(j == 0) {
				minTime = currA[0] + A[0];
				index = 0;
			}
			if(currA[j] + A[j] < minTime) {
				minTime = currA[j] + A[j];
				index = j;
			}
		}
		currA[index] += A[index];
		aTimes.push_back(minTime);
	}
	fout << aTimes[N - 1] << " ";

	for(int i = 0; i < N; i++) {
		int minTime;
		int index;
		for(int j = 0; j < M2; j++) {
			if(j == 0) {
				minTime = currB[0] + B[0];
				index = 0;
			}
			if(currB[j] + B[j] < minTime) {
				minTime = currB[j] + B[j];
				index = j;
			}
		}
		currB[index] += B[index];
		bTimes.push_back(minTime);
	}

	reverse(bTimes.begin(), bTimes.end());
	int maxTime;	
	maxTime = aTimes[0] + bTimes[0];
	for(int i = 0; i < N; i++) {
		maxTime = max(aTimes[i] + bTimes[i], maxTime);
	}
	fout << maxTime << endl;
}
