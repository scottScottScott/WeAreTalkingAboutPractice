#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <deque>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

int main() {
	int h, w;
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");

	fin >> w >> h;
	vector< vector<int> > adj(w * h);
	vector<ii> doors; 

	//parsing
	string temp;
	getline(fin, temp);
	for(int i = 0; i < 2 * h + 1; i++) {
		string temp;
		getline(fin, temp);
		cout << temp << " " <<  temp.size() << endl;
		for(int j = 0; j < 2 * w + 1; j++) {
			char curr = temp[j];
			if(i == 0) {
				if(curr == ' ') 
					doors.push_back(make_pair(0, (j - 1) / 2));
			}
			else if(i == 2 * h) {
				if(curr == ' ') 
					doors.push_back(make_pair(h - 1, (j - 1) / 2));
			}
			else if(j == 0) {
				if(curr == ' ')
					doors.push_back(make_pair((i - 1) / 2, 0));
			}
			else if(j == 2 * w) {
				if(curr == ' ')
					doors.push_back(make_pair((i - 1) / 2, w - 1));
			}
			else if(i % 2 == 1) { //vertical walls
				if(j % 2 == 0 && curr == ' ') {
					int currH = (i - 1) / 2;
					int currW = j / 2 - 1;
					adj[currH * w + currW].push_back(currH * w + currW + 1);	
					adj[currH * w + currW + 1].push_back(currH * w + currW);	
				}
			}
            else if(i % 2 == 0) { //horizontal walls
				if(j % 2 == 1 && curr == ' ')	{
					int currH = i / 2 - 1;
					int currW = (j - 1) / 2;
					adj[currH * w + currW].push_back((currH + 1) * w + currW);
					adj[(currH + 1) * w + currW].push_back(currH * w + currW);
				}
			}
		}
	}

	for(int i = 0; i < h * w; i++) {
		cout << "Node: " << i << endl;
		for(int j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
		cout << endl;
	}

	int minSteps[h * w];
	for(int i = 0; i < h * w; i++) {
		minSteps[i] = 3800;
	}
	for(int i = 0; i < doors.size(); i++) {
		int currDoor = doors[i].first * w + doors[i].second;
		cout << currDoor << endl;
		int visited[h * w];
		memset(visited, -1, sizeof(visited));
		visited[currDoor] = 0;
		minSteps[currDoor] = 0;
		deque<int> toVisit;
		toVisit.push_back(currDoor);
		while(!toVisit.empty()) {
			int currCell = toVisit.front();
			toVisit.pop_front();
			for(int j = 0; j < adj[currCell].size(); j++) {
				int nextCell = adj[currCell][j];
				if(visited[nextCell] == -1) {
					visited[nextCell] = visited[currCell] + 1;
					toVisit.push_back(nextCell);
					if(visited[nextCell] < minSteps[nextCell])
						minSteps[nextCell] = visited[nextCell];
				}
			}
		}
	}

	int max = 0;
	for(int i = 0; i < w * h; i++) {
		if(max < minSteps[i]) {
			max = minSteps[i];
		}
	}

	fout << max + 1 << endl;
	return 0;
}
