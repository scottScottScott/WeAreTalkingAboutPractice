#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M;	
	char eat;
	cin >> N >> M;
	scanf("%c", &eat);	
	char temp[5000];
	vector<vector<bool>> grid(N, vector<bool> (M));
	for(int r = 0; r < N; r++) {
		scanf("%s", temp);
		for(int c = 0; c < M; c++)
			grid[r][c] = (temp[c] == '1' ? 1 : 0);
	}	

	int result = 0;
	vector<vector<int>> memo(N, vector<int> (M));
	for(int r = 0; r < N; r++) {
		for(int c = M - 1; c >= 0; c--) {
			if(grid[r][c] == 1)
				memo[r][c] = 1 + (c != M - 1 ? memo[r][c + 1] : 0);
		}
	}
	for(int c = 0; c < M; c++) {
		vector<int> width;
		for(int r = 0; r < N; r++) {
			if(memo[r][c] != 0) 
				width.push_back(memo[r][c]);
		}
		sort(width.rbegin(), width.rend());
		for(int i = 0; i < width.size(); i++) {
			int area = (i + 1) * width[i];
			result = max(result, area);
		}	
	}
	cout << result << endl;
}
