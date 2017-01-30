#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int H, W;
map<char, set<char> > onTop;
set<char> frames;	

string path;
vector<string> solutions;
map<char, bool> visited;
int numVisited = 0;

void dfs(char start) {
	numVisited++;
	visited[start] = true;
	path += start;

	if(numVisited == frames.size()) {
		string temp = path;
		reverse(temp.begin(), temp.end());
		solutions.push_back(temp);
	}
	else {
		for(auto x : frames) {
			if(!visited[x]) {
				bool canVisit = true;
				for(auto y : onTop[x]) {
					if(!visited[y])
						canVisit = false;
				}
				if(canVisit) {
					dfs(x);
				}
			}
		}
	}

	numVisited--;
	visited[start] = false;
	path.pop_back();
}

int main() {
	ifstream fin("frameup.in");
	ofstream fout("frameup.out");

	fin >> H >> W;
	char map[H][W];

	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			fin >> map[i][j];
		}
	}

	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			char curr = map[i][j];
			if(curr != '.' && !frames.count(curr)) {
				frames.insert(curr);
				int top = i;	
				int left = j;
				int bottom = i;
				int right = j;
	
				for(int a = i; a < H; a++) {
					for(int b = 0; b < W; b++) {
						if(map[a][b] == curr) {
							if(a > bottom)
								bottom = a;
							if(b < left)
								left = b;
							if(b > right)
								right = b;
						}
					}
				}
				
				for(int a = top; a <= bottom; a++) {
					for(int b = left; b <= right; b++) {
						if(map[a][b] != curr) {
							if(a == top || a == bottom || b == left || b == right)
								onTop[curr].insert(map[a][b]);								
						}
					}
				}

			}
		}
	}


	for(auto x : frames) {
		if(onTop[x].empty()) {
			path = "";
			dfs(x);	
		}
	}	

	sort(solutions.begin(), solutions.end());	
	for(auto x : solutions)
		fout << x << endl;
}
