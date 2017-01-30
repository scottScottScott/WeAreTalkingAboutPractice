#include <iostream>
#include <utility>
#include <fstream>
#include <vector>

using namespace std;

int max_dist;
int N;
vector<vector<char>> grid(120, vector<char>(120, '.'));

void dfs(int y, int x, int curr_dist) {
	bool has_path = false;
	vector<pair<int, int>> directions;
	switch(grid[y][x]) {
		case('S'):
			directions.emplace_back(1, 0);
			directions.emplace_back(0, 1);
			break;
		case('V'):	
			directions.emplace_back(0, -1);
			directions.emplace_back(0, 1);
			break;
		case('H'):
			directions.emplace_back(-1, 0);
			directions.emplace_back(1, 0);
			break;
	}

	for(auto pnt : directions) {
		int direc_y = pnt.first;	
		int direc_x = pnt.second;

		int next_y = y + direc_y;
		int next_x = x + direc_x;
		int next_dist = curr_dist;;

		while(next_x < N && next_x >= 0 && next_y < N && next_y >= 0 && grid[next_y][next_x] == '.') {
			grid[next_y][next_x] = '-';
			next_y += direc_y;
			next_x += direc_x;
			next_dist++;
		}

		if(next_dist != curr_dist) {
			next_x -= direc_x;
			next_y -= direc_y;

			has_path = true;
			grid[next_y][next_x] = (direc_y == 0 ? 'H' : 'V');
			if(next_x + direc_x < N && next_x + direc_x >= 0 && 
				next_y + direc_y < N && next_y + direc_y >= 0 && 
				grid[next_y + direc_y][next_x + direc_x] != '#') {
				max_dist = max(next_dist, max_dist);
			}
			else {
				dfs(next_y, next_x, next_dist);
			}

			while(next_y != y || next_x != x) {
				grid[next_y][next_x] = '.';
				next_y -= direc_y;
				next_x -= direc_x;
			}
		}
	}
	
	if(!has_path) {
		max_dist = max(curr_dist, max_dist);
	}
}

int main() {
	ifstream fin("snail.in");
	ofstream fout("snail.out");

	int B;
	fin >> N >> B;
	for(int i = 0; i < B; i++) {
		char across;
		int down;
		fin >> across >> down;
		//cout << across << " " << down << endl;
		grid[down - 1][across - 'A'] = '#';
	}

	/*
	for(auto a : input_map) {
		for(auto b : a) {
			cout << b;
		}
		cout << endl;
	}
	*/
	
	grid[0][0] = 'S';
	dfs(0, 0, 1);
	fout << max_dist << endl;	
}
