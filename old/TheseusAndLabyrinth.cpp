#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tpl;

unordered_map<char, char> other{ {'-', '|'}, {'|', '-'} };
unordered_map<char, int> M1 { {'R', 0}, {'D', 1}, {'L', 2}, {'U', 3} };	
unordered_map<int, char> r_M1 { {0, 'R'}, {1, 'D'}, {2, 'L'}, {3, 'U'} };
unordered_map<char, int> M2 { {'>', 0}, {'v', 1}, {'<', 2}, {'^', 3} };	
unordered_map<int, char> r_M2 { {0, '>'}, {1, 'v'}, {2, '<'}, {3, '^'} };

char lookup(char X, int rot) {
	if(X == '+' or X == '*') return X;
	else if(X == '-' or X == '|') {
		if(rot % 2 == 0) return X;
		else return other[X];
	}
	else if(X == 'R' or X == 'D' or X == 'L' or X == 'U') {
		int num = M1[X];
		num = (num + rot) % 4;
		return r_M1[num];
	}	
	else {
		int num = M2[X];
		num = (num + rot) % 4;
		return r_M2[num];
	}
}

bool valid(char X, int direc) {
	if(X == '+') return true;

	if(direc == 0 or direc == 2)
		if(X == '-') return true;	

	if(direc == 1 or direc == 3)
		if(X == '|') return true;

	if(X == 'R' or X == 'D' or X == 'L' or X == 'U')
		if(M1[X] != direc) return true;

	if(X == '>' or X == 'v' or X == '<' or X == '^') 
		if(M2[X] == direc) return true;

	return false;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> G(N, vector<char> (M));
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < M; c++) {
			cin >> G[r][c];
		}
	}

	pii S, E;
	cin >> S.first >> S.second >> E.first >> E.second;
	S.first--;
	S.second--;
	E.first--;
	E.second--;
	
	vector<vector<vector<int>>> memo(N, vector<vector<int>> (M, vector<int> (4, -1)));
	deque<tpl> Q;
	Q.emplace_back(S.first, S.second, 0);
	memo[S.first][S.second][0] = 0;	
	int moves = 1;
	while(!Q.empty()) {
		int A = Q.size();	
		for(int a = 0; a < A; a++) {
			tpl curr = Q.front();
			Q.pop_front();
			int row = get<0>(curr);
			int col = get<1>(curr);
			int rot = get<2>(curr);

			int rot_next = (rot + 1) % 4;	
			if(memo[row][col][rot_next] == -1) {
				Q.emplace_back(row, col, rot_next);
				memo[row][col][rot_next] = moves;
			}
				
			vector<pii> change_vec{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			int direc = -1;
			for(pii change : change_vec) {
				direc++;
				pii next {row + change.first, col + change.second};
				if(next.first < 0 or next.first >= N) continue;
				if(next.second < 0 or next.second >= M) continue;
				
				char d_1 = lookup(G[row][col], rot);
				char d_2 = lookup(G[next.first][next.second], rot);	

				if(valid(d_1, direc) and valid(d_2, (direc + 2) % 4)) {
					if(memo[next.first][next.second][rot] == -1) {
						memo[next.first][next.second][rot] = moves;
						Q.emplace_back(next.first, next.second, rot);
					}
				}
			}
		}
		moves++;
	}

	int minDist = -1;
	for(int i = 0; i < 4; i++) {
		if(memo[E.first][E.second][i] != -1) {
			if(minDist == -1) minDist = memo[E.first][E.second][i];
			else minDist = min(minDist, memo[E.first][E.second][i]);
		}
	}
	cout << minDist << endl;
}
