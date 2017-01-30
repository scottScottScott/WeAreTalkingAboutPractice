#include <fstream>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("shuttle.in");
	ofstream fout("shuttle.out");
	
	int N;
	fin >> N;

	string A(N, 'W');
	string B(N, 'B');

	string init = A;
	init += " ";
	init += B;

	int l = init.size();

	string goal = init;
	reverse(goal.begin(), goal.end());

	deque<string> toVisit;	
	unordered_map<string, pair<string, char> > prev;
	
	toVisit.push_back(init);
	prev[init].first = init;
	bool gotGoal = false;
	while(!toVisit.empty() && !gotGoal) {
		string curr = toVisit.front();
		toVisit.pop_front();
		for(int i = 0; i < l; i++) {

			string next = curr;

			if( i + 1 < l && curr[i] == 'W' && curr[i + 1] == ' ') {
				next[i] = ' ';	
				next[i + 1] = 'W';
			}
			else if( i + 2 < l && curr[i] == 'W' && curr[i + 1] == 'B' && curr[i + 2] == ' ') {
				next[i] = ' ';
				next[i + 2] = 'W';
			}
			else if( i - 1 >= 0 && curr[i] == 'B' && curr[i - 1] == ' ') {
				next[i] = ' ';
				next[i - 1] = 'B';
			}
			else if( i - 2 >= 0 && curr[i] == 'B' && curr[i - 1] == 'W' && curr[i - 2] == ' ') {
				next[i] = ' ';
				next[i - 2] = 'B';
			}

			if(!prev.count(next)) {
				toVisit.push_back(next);
				prev[next].first = curr;
				prev[next].second = i + 1;
				if(next == goal) {
					gotGoal = true;	
					break;
				}	
			}

		}	
	}

	vector<int> solution;
	string currStr = goal;
	while(currStr!= init) {
		string prevStr = prev[currStr].first;
		solution.push_back(prev[currStr].second);	
		currStr = prevStr;
	}

	int count = 0;
	for(vector<int>::reverse_iterator x = solution.rbegin(); x != solution.rend(); x++) {
		if(count % 20 == 0 && count != 0)
			fout << endl;
		count++;
		if(count % 20 != 1)
			fout << " ";
		fout << *x;
	}
	fout << endl;
}
