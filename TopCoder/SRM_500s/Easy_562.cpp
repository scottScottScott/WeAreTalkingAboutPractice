#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

class PastingPaintingDivOne {
public:
	vector<long long> countColors(vector <string>, int);
};

vector<long long> PastingPaintingDivOne::countColors(vector<string> clipboard, int T) {
	int N = clipboard.size();
	int M = clipboard[0].size();

	int A = min(N, M);
	int B = min(T, A);
	
	unordered_map<char, long long> count;
	vector<string> grid(N, string(M, '.'));
	for(int curr = 0; curr < B; curr++) {
		for(int row = curr; row < N; row++) {
			if(grid[row - curr][0] == '.')
				grid[row - curr][0] = clipboard[row][curr];
		}
		for(int col = curr; col < M; col++) {
			if(grid[0][col - curr] == '.')
				grid[0][col - curr] = clipboard[curr][col];
		}

		for(int row = 0; row < N; row++)
			count[grid[row][0]]++;
		for(int col = 1; col < M; col++) 
			count[grid[0][col]]++;
	}

	vector<string> grid2 = clipboard;
	for(int curr = 1; curr < A; curr++) {
		for(int next = curr + 1; next < A and next - curr < B; next++) {
			int diff = next - curr;
			for(int row = next; row < N; row++) {
				if(grid2[row - diff][curr] == '.')
					grid2[row - diff][curr] = clipboard[row][next];
			}
			for(int col = next; col < M; col++) {
				if(grid2[curr][col - diff] == '.')
					grid2[curr][col - diff] = clipboard[next][col];
			}
		}
		for(int row = curr; row < N; row++)
			count[grid2[row][curr]]++;
		for(int col = curr + 1; col < M; col++) 
			count[grid2[curr][col]]++;
	}

	T -= B;
	unordered_map<char, long long> M_temp;
	for(int row = 0; row < N; row++)
		M_temp[grid[row][0]]++;
	for(int col = 1; col < M; col++)
		M_temp[grid[0][col]]++;

	for(auto& x : M_temp)
		count[x.first] += T * x.second;
	

	vector<long long> result{ count['R'], count['G'], count['B'] };
	return result;
}
