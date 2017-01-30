#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int main() {
	ifstream fin("fence6.in");
	ofstream fout("fence6.out");

	int N;
	fin >> N;

	map< set<int>, int> segsToEdge; 
	int currEdge = 0;
	vector<int> edge1;
	vector<int> edge2;
	vector<int> dist;
	for(int i = 0; i < N; i++) {
		int segNum;
		int segLength;
		int numAdj[2];
		set<int> segs[2];

		fin >> segNum >> segLength;
		fin >> numAdj[0] >> numAdj[1];

		for(int j = 0; j < 2; j++) {
			segs[j].insert(segNum);
			for(int k = 0; k < numAdj[j]; k++) {
				int temp;
				fin >> temp;
				segs[j].insert(temp);
			}
			if(!segsToEdge.count(segs[j])) {
				segsToEdge[segs[j]] = currEdge;
				currEdge++;
			}
		}
		edge1.push_back(segsToEdge[segs[0]]);
		edge2.push_back(segsToEdge[segs[1]]);
		dist.push_back(segLength);
		//cout << edge1[i] << " " << edge2[i] << " " << dist[i] << endl;
	}

	int adjMat[currEdge][currEdge];

	int minPerim = 25500;
	for(int z = 0; z < N; z++) {
		memset(adjMat, -1, sizeof(adjMat));
		for(int i = 0; i < N; i++) {
			adjMat[edge1[i]][edge2[i]] = dist[i];
			adjMat[edge2[i]][edge1[i]] = dist[i];
		}
		adjMat[edge1[z]][edge2[z]] = -1;
		adjMat[edge2[z]][edge1[z]] = -1;
		for(int k = 0; k < currEdge; k++) {
			for(int i = 0; i < currEdge; i++) {
				for(int j = 0; j < currEdge; j++) {
					if(adjMat[i][k] != -1 && adjMat[k][j] != -1) { 
						if(adjMat[i][j] == -1 || adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) 
							adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
					}
				}
			}
		}
		if(adjMat[edge1[z]][edge2[z]] > 0 && adjMat[edge1[z]][edge2[z]] + dist[z] < minPerim) {
			minPerim = adjMat[edge1[z]][edge2[z]] + dist[z];
		}
	}

	/*
	for(int i = 0; i < currEdge; i++) {
		for(int j = 0; j < currEdge; j++) {
			cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}
	*/

	fout << minPerim << endl;

	return 0;
}
