#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector< vector<bool> > adj(50, vector<bool>(50));
int endNode;

bool dfsRemove(int remove) {
	vector<bool> visited(endNode + 1, false);
	stack<int> toVisit;	

	visited[0] = true;	
	visited[remove] = true;
	toVisit.push(0);

	while(!toVisit.empty()) {
		int curr = toVisit.top();
		toVisit.pop();
		for(int i = 0; i <= endNode; i++) {
			if(adj[curr][i] && !visited[i]) {
				visited[i] = true;
				toVisit.push(i);

				if(i == endNode)
					return true;
			}
		}
	}

	return false;
}

bool dfsStart(int start) {
	vector<bool> inFirst(endNode + 1, false);
	stack<int> toVisit;	

	inFirst[0] = true;
	inFirst[start] = true;
	toVisit.push(0);

	while(!toVisit.empty()) {
		int curr = toVisit.top();
		toVisit.pop();
		for(int i = 0; i <= endNode; i++) {
			if(adj[curr][i] && !inFirst[i]) {
				inFirst[i] = true;
				toVisit.push(i);
			}
		}
	}

	vector<bool> visited(endNode + 1, false);
	toVisit.push(start);
	visited[start] = true;

	while(!toVisit.empty()) {
		int curr = toVisit.top();
		toVisit.pop();
		for(int i = 0; i <= endNode; i++) {
			if(adj[curr][i] && !visited[i]) {
				visited[i] = true;
				toVisit.push(i);
				if(inFirst[i])
					return true;
			}
		}
	}

	return false;
}

int main() {
	ifstream fin("race3.in");
	ofstream fout("race3.out");

	int temp;
	while(fin >> temp && temp != -1) {
		if(temp == -2)
			endNode++;
		else {
			adj[endNode][temp] = true;
		}
	}
	endNode--;

	vector<int> unavoid;	
	for(int i = 1; i < endNode; i++) {
		if(!dfsRemove(i))
			unavoid.push_back(i);
	}

	vector<int> separate;
	for(auto x : unavoid) {
		if(!dfsStart(x))
			separate.push_back(x);
	}

	fout << unavoid.size();
	for(auto x : unavoid) {
		fout << " " << x;
	}
	fout << endl;

	fout << separate.size();
	for(auto x : separate)
		fout << " " << x;
	fout << endl;
}
