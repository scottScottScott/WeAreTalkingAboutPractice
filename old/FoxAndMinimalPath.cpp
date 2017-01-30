#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjMat(1001, vector<int> (1001));

void connect(vector<int> &a, vector<int> &b) {
	for(int x : a) {
		for(int y : b)
			adjMat[x][y] = adjMat[y][x] = 1;
	}
	a = move(b);
	b.clear();
}

int main() {
	int k;
	cin >> k;

	int node = 3;
	for(int i = 0; i < 15; i++) {
		int curr = k % 4;
		k -= k % 4;
		k /= 4;
		if(curr == 0) continue;
		
		vector<int> prev {1};
		vector<int> next;
		for(int j = 0; j < curr; j++)
			next.push_back(node++);
		connect(prev, next);	
		int j = 1;
		for( ; j <= i; j++) {
			for(int k = 0; k < 4; k++)
				next.push_back(node++);
			connect(prev, next);
		}
		for( ; j < 15; j++) {
			next.push_back(node++);
			connect(prev, next);
		}
		next.push_back(2);
		connect(prev, next);
	}
	cout << node - 1 << endl;
	for(int i = 1; i < node; i++) {
		for(int j = 1; j < node; j++)
			printf("%c", adjMat[i][j] == 1 ? 'Y' : 'N');
		printf("\n");
	}
}
