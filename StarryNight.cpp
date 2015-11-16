#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int W, H;
set<pair<int, int>> visited;	

vector<vector<int>> getShape(vector<vector<bool>> &map_input, int a, int b) {
	queue<pair<int, int>> toVisit;	
	visited.emplace(a, b);
	toVisit.emplace(a, b);

	int max_X = b;
	int min_X = b;
	int max_Y = a;

	while(!toVisit.empty()) {
		int h = toVisit.front().first;
		int w = toVisit.front().second;
		toVisit.pop();	

		if(h > max_Y) 
			max_Y = h;
		if(w > max_X)
			max_X = w;
		if(w < min_X) 
			min_X = w;
		
		for(int x : {-1, 0, 1} ) {
			for(int y : { -1, 0, 1} ) {
				if(0 <= h + y && h + y < H && 0 <= w + x && w + x < W) {
					if(map_input[h + y][w + x] && !visited.count(make_pair(h + y, w + x))) {
						toVisit.emplace(h + y, w + x);
						visited.emplace(h + y, w + x);
						//cout << "FOUND: " << h + y << " " << w + x << endl;
					}
				}
			}
		}
	}

	vector<vector<int>> ret(max_Y - a + 1, vector<int> (max_X - min_X + 1));
	for(auto point : visited) {
		int y = point.first - a;
		int x = point.second - min_X;
		ret[y][x] = 1;
	}	

	return ret;
}

vector<vector<int>> rotateShape(vector<vector<int>> &shape) {
	vector<vector<int>>	new_vector(shape[0].size(), vector<int>(shape.size()));
	for(int i = shape.size() - 1; i >= 0; i--) {
		for(int j = 0; j < shape[0].size(); j++) {
			new_vector[j][shape.size() - 1 - i] = shape[i][j];
		}
	}
	return new_vector;
}

void flipShape(vector<vector<int>> &shape) {
	for(int i = 0; i < shape.size(); i++) {
		reverse(shape[i].begin(), shape[i].end());
	}	
}

void colorShape(vector<vector<char>> &marked, char color) {
	for(auto x : visited) {
		int a = x.first;
		int b = x.second;
		marked[a][b] = color;
	}
}

int main() {
	ifstream fin("starry.in");
	ofstream fout("starry.out");
	
	fin >> W >> H;

	vector<vector<bool>> map_input(H, vector<bool>(W));
	vector<vector<char>> marked(H, vector<char>(W, '0'));
	map<vector<vector<int>>, char> identify;
	char curr = 'a';

	string temp;
	getline(fin, temp);
	for(int a = 0; a < H; a++) {
		getline(fin, temp);
		for(int b = 0; b < W; b++) {
			map_input[a][b] = temp[b] - '0';
			//cout << map_input[a][b];
		}
		//cout << endl;
	}

	for(int a = 0; a < H; a++) {
		for(int b = 0; b < W; b++) {
			if(map_input[a][b] && marked[a][b] == '0') {
				visited.clear();

				vector<vector<int>> shape = getShape(map_input, a, b);
				bool found = false;
				char match;

				for(int i = 0; i < 4; i++) {
					if(i != 0)
						shape = rotateShape(shape);
					if(identify.count(shape)) {
						match = identify[shape];
						found = true;
						break;
					}
				}
				if(!found) {
					flipShape(shape);
					for(int i = 0; i < 4; i++) {
						if(i != 0)
							shape = rotateShape(shape);
						if(identify.count(shape)) {
							match = identify[shape];
							found = true;
							break;
						}
					}
				}

				if(!found) {
					identify[shape] = curr;
					match = curr;
					curr++;
				}

				colorShape(marked, match);	
			}	
		}
	}

	for(int a = 0; a < H; a++) {
		for(int b = 0; b < W; b++) {
			fout << marked[a][b];
		}
		fout << endl;
	}
	
}
