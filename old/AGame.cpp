#include <iostream>
#include <fstream>

using namespace std;

#define maxN 200

int diff[maxN][maxN];
int score1[maxN][maxN];
int score2[maxN][maxN];

int main() {
	ifstream fin("game1.in");
	ofstream fout("game1.out");

	int N;
	fin >> N;
	for(int i = 0; i < N; i++) {
		fin >> score1[i][i];
	}

	for(int size = 2; size <= N; size++) {
		for(int i = 0; i < N - size + 1; i++) {
			int j = i + size - 1;
			int pickFirstDiff = score1[i][i] - score1[i + 1][j] + score2[i + 1][j];
			int pickLastDiff = score1[j][j] - score1[i][j - 1] + score2[i][j - 1];
			if(pickFirstDiff > pickLastDiff) {
				score1[i][j] = score1[i][i] + score2[i + 1][j];
				score2[i][j] = score1[i + 1][j];
			}
			else {
				score1[i][j] = score1[j][j] + score2[i][j - 1];
				score2[i][j] = score1[i][j - 1];
			}
		}
	}

	fout << score1[0][N - 1] << " " << score2[0][N - 1] << endl;
	return 0;
}
