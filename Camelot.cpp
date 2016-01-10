#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <deque>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main() {
	ifstream fin("camelot.in");
	ofstream fout("camelot.out");

	int R, C;
	fin >> R >> C;

	vector<int> posX;
	vector<int> posY;
	int rVal;
	char cVal;
	while(fin >> cVal) {
		fin >> rVal;
		posX.push_back(cVal - 'A');	
		posY.push_back(rVal - 1);
	}

	int minMoves = -1;
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			//cout << r << " " << c << endl;
			int dist[R][C];
			memset(dist, -1, sizeof(dist));
			dist[r][c] = 0;	
			deque<ii> toVisit = {make_pair(r, c)};
			while(!toVisit.empty()) {
				ii currPair = toVisit.front();
				toVisit.pop_front();
				int currY = currPair.first;
				int currX = currPair.second;
				vector<ii> nxtMove;
				nxtMove.push_back(make_pair(currY + 1, currX + 2));
				nxtMove.push_back(make_pair(currY + 1, currX - 2));
				nxtMove.push_back(make_pair(currY + 2, currX + 1));
				nxtMove.push_back(make_pair(currY + 2, currX - 1));
				nxtMove.push_back(make_pair(currY - 1, currX + 2));
				nxtMove.push_back(make_pair(currY - 1, currX - 2));
				nxtMove.push_back(make_pair(currY - 2, currX + 1));
				nxtMove.push_back(make_pair(currY - 2, currX - 1));
				for(int i = 0; i < nxtMove.size(); i++) {
					int nxtY = nxtMove[i].first;
					int nxtX = nxtMove[i].second;
					if(0 <= nxtY && nxtY < R && 0 <= nxtX && nxtX < C) {
						if(dist[nxtY][nxtX] == -1) {
							dist[nxtY][nxtX] = dist[currY][currX] + 1;
							toVisit.push_back(nxtMove[i]);
						}
					}
				}
			}
			int numMoves = 0;
			int i;
			for(i = 1; i < posX.size(); i++) {
				if(dist[posY[i]][posX[i]] == -1)
					break;
				numMoves += dist[posY[i]][posX[i]];
			}
			if(i != posX.size())
				continue;
			int distToKing = -1;
			int onPath[R][C];
			memset(onPath, -1, sizeof(dist));
			for(int i = 1; i < posX.size(); i++) {
				toVisit.push_back(make_pair(posY[i], posX[i]));
				onPath[posY[i]][posX[i]] = 1;
			}
			toVisit.push_back(make_pair(r, c));
			onPath[r][c] = 1;
			while(!toVisit.empty()) {
				ii currPair = toVisit.front();
				toVisit.pop_front();
				int currY = currPair.first;
				int currX = currPair.second;
				if(distToKing == -1) {
					distToKing = max(abs(posY[0] - currY), abs(posX[0] - currX));
				}
				else {
					distToKing = min(distToKing , max(abs(posY[0] - currY), abs(posX[0] - currX)));
				}
				vector<ii> nxtMove;
				nxtMove.push_back(make_pair(currY + 1, currX + 2));
				nxtMove.push_back(make_pair(currY + 1, currX - 2));
				nxtMove.push_back(make_pair(currY + 2, currX + 1));
				nxtMove.push_back(make_pair(currY + 2, currX - 1));
				nxtMove.push_back(make_pair(currY - 1, currX + 2));
				nxtMove.push_back(make_pair(currY - 1, currX - 2));
				nxtMove.push_back(make_pair(currY - 2, currX + 1));
				nxtMove.push_back(make_pair(currY - 2, currX - 1));
				for(int i = 0; i < nxtMove.size(); i++) {
					int nxtY = nxtMove[i].first;
					int nxtX = nxtMove[i].second;
					if(0 <= nxtY && nxtY < R && 0 <= nxtX && nxtX < C) {
						if(dist[nxtY][nxtX] < dist[currY][currX] && onPath[nxtY][nxtX] != 1) {
							onPath[nxtY][nxtX] = 1;
							toVisit.push_back(nxtMove[i]);
						}
					}
				}
			}
			//cout << r << " " << c << " " << numMoves << " " << distToKing << endl;
			numMoves += distToKing;
			if(minMoves == -1)
				minMoves = numMoves;
			else
				minMoves = min(minMoves, numMoves);	
		}
	}

	fout << minMoves << endl;
}
