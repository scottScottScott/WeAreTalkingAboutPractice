#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

int ownage[101][101];
int visited[101][101];
int controlled[101][101];
set< pair<int , int> > ownList;

void updateControls(int i, int j) {
	int numUpdates = 0;
	for(int k = 0; k <= 100; k++) {
		if(i != k) {
			controlled[i][k] += ownage[j][k];
			if(controlled[i][k] > 50 &&  visited[i][k] == 0) {
				ownList.insert(make_pair(i, k));
				visited[i][k] = 1;
				updateControls(i, k);
			}
		}
	}
}


int main() {
	ifstream fin("concom.in");	
	ofstream fout("concom.out");
	int N;
	fin >> N;

	for(int z = 0; z < N; z++) {
		int i, j, p;	
		fin >> i >> j >> p;
		ownage[i][j] = p;
		controlled[i][j] = p;
	}

	for(int i = 1; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			if(i != j) {
				pair<int, int> temp = make_pair(i, j);
				if(ownage[i][j] > 50 && visited[i][j] == 0) {
					ownList.insert(temp);	
					visited[i][j] = 1;
					updateControls(i, j);	
				}
			}

	for(set< pair<int, int> >::iterator itr = ownList.begin(); itr != ownList.end(); itr++)
		fout << (*itr).first << " " << (*itr).second << endl;
	
	return 0;
}
