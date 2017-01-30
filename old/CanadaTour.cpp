#include <iostream> 
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	ifstream fin("tour.in");	
	ofstream fout("tour.out");

	unordered_map<string, int> M_Name;

	int N, V;
	fin >> N >> V;

	for(int i = 0; i < N; i++) {
		string s;
		fin >> s;
		M_Name[s] = i;
	}

	vector<vector<int>> adjList(N);
	
	for(int i = 0; i < V; i++) {
		string s1, s2;
		fin >> s1 >> s2;
		int id1, id2;
		id1 = M_Name[s1];	
		id2 = M_Name[s2];

		if(id1 > id2) 
			adjList[id1].push_back(id2);
		else
			adjList[id2].push_back(id1);
	}

	int memo[N][N];
	memset(memo, 0, sizeof(memo));
	memo[0][0] = 1;

	/*
		memo[i][j] = number of distinct cities visited by two paths 
					 with one ending at i and another ending at j	
		Base Case: memo[0][0] = 1 
		Formula: memo[i][j] (i != j) = max(memo[k][j] + 1) where k is node with edge to i
	*/

	for(int i = 1; i < N; i++) {
		if(i == N - 1) {
			int maxVal = 0;
			for(int id1 : adjList[i]) {
				for(int id2 : adjList[i]) {
					if(memo[id1][id2] > 0)
						maxVal = max(memo[id1][id2] + 1, maxVal);
				}
			}
			memo[i][i] = maxVal;
		}
		else {
			for(int a = 0; a < i; a++) {
				int maxVal = 0;
				for(int id : adjList[i]) {
					// cout << id << endl;
					if(memo[a][id] > 0)
						maxVal = max(maxVal, memo[a][id] + 1);	
				}
				memo[a][i] = maxVal;
				memo[i][a] = maxVal;
			}
		}
	}

	fout << (memo[N - 1][N - 1] ? memo[N - 1][N - 1] : 1) << endl;
}
