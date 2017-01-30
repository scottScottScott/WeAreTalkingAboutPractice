#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>
#include <cmath>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M, P;
	cin >> N >> M >> P;
	vector<vector<pii>> info(P);
	for(int row = 0; row < N; row++) {
		for(int col = 0; col < M; col++) {
			int temp;
			scanf("%d", &temp);
			temp--;
			info[temp].emplace_back(row, col);	
		}
	}

	int B = sqrt(N * M);
	vector<vector<int>> dist(N, vector<int> (M, INT_MAX));
	for(pii curr : info[0])
		dist[curr.first][curr.second] = curr.first + curr.second;
	for(int chest = 1; chest < P; chest++) {
		int size = info[chest].size();	
		if(size <= B) {
			for(pii curr : info[chest - 1]) {
				for(pii next : info[chest]) {
					int currDist = abs(curr.first - next.first) + abs(curr.second - next.second);
					currDist += dist[curr.first][curr.second];
					dist[next.first][next.second] = min(dist[next.first][next.second], currDist);
				}
			}
		}
		else {
			vector<vector<bool>> visited(N, vector<bool> (M));	
			vector<vector<bool>> nextLevel(N, vector<bool> (M));
			for(pii next : info[chest])
				nextLevel[next.first][next.second] = true;

			deque<pii> side_info;
			for(int i = 0; i < info[chest - 1].size(); i++) {
				pii curr = info[chest - 1][i];
				side_info.emplace_back(dist[curr.first][curr.second], i);
			}
			sort(side_info.begin(), side_info.end());

			int time = side_info[0].first;
			deque<pii> toVisit;
			while(!side_info.empty() and side_info.front().first == time) {
				pii curr = info[chest - 1][side_info[0].second];
				if(visited[curr.first][curr.second] == 0) {
					visited[curr.first][curr.second] = 1;
					toVisit.push_back(curr);	
				}
				side_info.pop_front();
			}
			while(!toVisit.empty()) {
				time++;
				int A = toVisit.size();
				while(A--) {
					pii curr = toVisit.front();
					toVisit.pop_front();
					for(int x : {1, 0, -1}) {
						for(int y : {1, 0, -1}) {
							if(x != 0 and y != 0) continue;
							pii next{curr.first + x, curr.second + y};
							if(next.first < 0 or next.first >= N) continue;
							if(next.second < 0 or next.second >= M) continue;

							if(!visited[next.first][next.second]) {
								visited[next.first][next.second] = true;
								if(nextLevel[next.first][next.second])
									dist[next.first][next.second] = time;
								toVisit.push_back(next);
							}	

						}
					}	

				}
				while(!side_info.empty() and side_info.front().first == time) {
					pii curr = info[chest - 1][side_info[0].second];
					if(visited[curr.first][curr.second] == 0) {
						visited[curr.first][curr.second] = 1;
						toVisit.push_back(curr);	
					}
					side_info.pop_front();
				}
			}
		}
	}
	
	int minDist = INT_MAX;
	for(pii curr : info[P - 1])
		minDist = min(minDist, dist[curr.first][curr.second]);
	cout << minDist << endl;
}
