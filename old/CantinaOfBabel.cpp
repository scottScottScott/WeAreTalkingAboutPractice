#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> finishOrder;		
vector<vector<bool>> adj;
vector<bool> visited;
int N;
int numNodes;

struct Info {
	string name;
	string speak;
	vector<string> listen;

	void print() {
		cout << name << endl;
		cout << speak << endl;
		for( auto x : listen)
			cout << x << " ";
		cout << endl;
		cout << endl << endl << endl;
	}
};

void dfs(int node) {
	for(int i = 0; i < N; i++) {
		if(adj[node][i] && !visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}	
	finishOrder.push(node);
}

void reverse_dfs(int node) {
	numNodes++;
	for(int i = 0; i < N; i++) {
		if(adj[i][node] && !visited[i]) {
			visited[i] = true;
			reverse_dfs(i);
		}
	}	
}

int maxSCC() {
	visited.resize(N);
	for(int i = 0; i < N; i++) {
		if(!visited[i])
			dfs(i);
	}

	int maxNodes = 0;
	fill(visited.begin(), visited.end(), 0);

	while(!finishOrder.empty()) {
		int currNode = finishOrder.top();
		finishOrder.pop();
		if(!visited[currNode]) {
			visited[currNode] = true;
			numNodes = 0;
			reverse_dfs(currNode);
			maxNodes = max(maxNodes, numNodes);
			//cout << numNodes << endl;
		}
	}

	return maxNodes;
}

int main() {
	cin >> N;
	string eat;
	getline(cin, eat);

	vector<Info *> getInfo;

	for(int i = 0; i < N; i++) {
		string line;
		string language;
		getline(cin, line);
		istringstream lineStream(line);

		Info *curr = new Info();	
		lineStream >> curr->name;
		lineStream >> language;
		curr->speak = language;
		(curr->listen).push_back(language);
		while(lineStream >> language)
			(curr->listen).push_back(language);
			
		getInfo.push_back(curr);
	}


/*
	for(auto x : getInfo)
		x -> print();
*/

	adj.resize(N);
	for(auto &vec : adj)
		vec.resize(N);

/*
	for(auto x : adj) {
		for(auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
*/


	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			Info *one = getInfo[i];
			Info *two = getInfo[j];
					
			for(int k = 0; k < (two->listen).size(); k++) {
				if(one->speak == (two->listen)[k]) {
					adj[i][j] = 1;
					break;
				}
			}

			for(int k = 0; k < (one->listen).size(); k++) {
				if(two->speak == (one->listen)[k]) {
					adj[j][i] = 1;
					break;
				}
			}

		}
	}

	cout << N - maxSCC() << endl;;
}
