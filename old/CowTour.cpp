#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#include <deque>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

double getDist(ii a, ii b) {
	int x1, y1, x2, y2;
	x1 = a.first;
	y1 = a.second;
	x2 = b.first;
	y2 = b.second;
	return sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) );
}

int main() {
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");

	vector<ii> points;

	int N;
	fin >> N;
	for(int i = 0; i < N; i++) {
		int X, Y;
		fin >> X >> Y;
		points.push_back(make_pair(X, Y));
	}

	double adj[N][N];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			char isAdj;
			fin >> isAdj;
			if(isAdj == '1') {
				adj[i][j] = getDist(points[i], points[j]);
			}
			else
				adj[i][j] = 0;
		}
	}

	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(adj[i][k] > 0 && adj[k][j] > 0 && i != j) 
					if(adj[i][k] + adj[k][j] < adj[i][j] || adj[i][j] == 0)
						adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}

	int currField = 1;
	vector<int> fieldNum(N);
	vector<double> diameter(N);
	for(int i = 0; i < N; i++) {
		if(!fieldNum[i]) {
			fieldNum[i] = currField;
			for(int j = 0; j < N; j++) {
				if(adj[i][j] != 0)
					fieldNum[j] = currField;
			}
			double longestPath = 0;
			for(int j = 0; j < N; j++) {
				for(int k = 0; k < N; k++) {
					if(fieldNum[j] == currField && fieldNum[k] == currField) {
						if(adj[j][k] > longestPath)
							longestPath = adj[j][k];
					}
				}
			}
			for(int j = 0; j < N; j++) {
				if(fieldNum[j] == currField) {
					diameter[j] = longestPath;
				}
			}
			currField++;
		}
	}

	for(int i = 0; i < N; i++) {
		cout << fieldNum[i] << " " << diameter[i] << endl;
	}

	double minDiameter = -1;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(fieldNum[i] != fieldNum[j]) {
				double maxNewDist = getDist(points[i], points[j]);					
				double dist1 = 0;
                double dist2 = 0;
				for(int k = 0; k < N; k++) {
					if(fieldNum[k] == fieldNum[i] && adj[k][i] > dist1) {
						dist1 = adj[k][i];
					}
				}
				for(int k = 0; k < N; k++) {
					if(fieldNum[k] == fieldNum[j] && adj[k][j] > dist2) {
						dist2 = adj[k][j];
					}
				}
				maxNewDist += dist1;
				maxNewDist += dist2;
				maxNewDist = max(maxNewDist, diameter[i]);
				maxNewDist = max(maxNewDist, diameter[j]);
				if(maxNewDist < minDiameter || minDiameter == -1)
					minDiameter = maxNewDist;
			}
		}
	}
	fout << setprecision(6) << fixed << minDiameter << endl;
	

	return 0;
}
