#include <iostream>
#include <vector>

using namespace std;

int main() {
	int R, C, N, K;
	cin >> R >> C >> N >> K;	
	vector<vector<bool>>  grid(R, vector<bool>(C));

	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		grid[x][y] = 1;
	}

	int count = 0;
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			for(int r_end = r; r_end < R; r_end++) {
				for(int c_end = c; c_end < C; c_end++) {
			
					int violas = 0;
					for(int i = r; i <= r_end; i++) {
						for(int j = c; j <= c_end; j++) {
							if(grid[i][j] == 1)
								violas++;
						}
					}
					if(violas >= K)
						count++;
				}
			}
		}
	}
	cout << count << endl;
}
