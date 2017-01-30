#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;
	
	vector<pii> vertex;
	for(int i = 0; i < N + 1; i++) {
		int X, Y;
		cin >> X >> Y;
		vertex.emplace_back(X, Y);
	}

	vector<char> direction;
	for(int i = 1; i < vertex.size(); i++) {
		if(vertex[i].first == vertex[i - 1].first) {
			if(vertex[i].second > vertex[i - 1].second) 
				direction.push_back('N');
			else 
				direction.push_back('S');
		}
		else {
			if(vertex[i].first > vertex[i - 1].first)
				direction.push_back('E');
			else
				direction.push_back('W');
		}
	}

	int dangerous = 0;
	for(int i = 0; i + 1 < direction.size(); i++) {
		if(direction[i] == 'E' and direction[i + 1] == 'N') dangerous++;	
		if(direction[i] == 'S' and direction[i + 1] == 'E') dangerous++;
		if(direction[i] == 'W' and direction[i + 1] == 'S') dangerous++;
		if(direction[i] == 'N' and direction[i + 1] == 'W') dangerous++; 
	}
	cout << dangerous << endl;
}
