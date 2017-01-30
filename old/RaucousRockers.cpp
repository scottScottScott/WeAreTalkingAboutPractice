#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("rockers.in");
	ofstream fout("rockers.out");

	int N, T, M;
	fin >> N >> T >> M;	
	
	int memo[M + 1][T];
	memset(memo, 0, sizeof(memo));
	for(int currSong = 0; currSong < N; currSong++) {
		int duration;
		fin >> duration;
		for(int diskUsed = M; diskUsed >= 0; diskUsed--) {
			for(int leftOver = 0; leftOver < T; leftOver++) {
				if(leftOver == 0 && diskUsed == 0|| memo[diskUsed][leftOver] != 0) {
					if(duration <= leftOver) {
						memo[diskUsed][leftOver - duration] = max(memo[diskUsed][leftOver - duration], memo[diskUsed][leftOver] + 1);
						//cout << diskUsed << " " << leftOver - duration << " " << memo[diskUsed][leftOver - duration] << endl;
					}
					else if(diskUsed != M && duration <= T){
						memo[diskUsed + 1][T - duration] = max(memo[diskUsed + 1][T - duration], memo[diskUsed][leftOver] + 1);
						//cout << diskUsed + 1 << " " << T - duration << " " << memo[diskUsed + 1][T - duration] << endl;
					}
				}
			}
		}
	}

	int maxSongs = memo[0][0];
	for(int i = 0; i <= M; i++) {
		for(int j = 0; j < T; j++) {
			if(memo[i][j] > maxSongs)
				maxSongs = memo[i][j];
		}
	}

	fout << maxSongs << endl;

	return 0;
}
