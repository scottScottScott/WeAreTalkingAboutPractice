#include <iostream>
#include <utility>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> Q;
	vector<pii> records;
	while(N--) {
		string S;
		int X;
		cin >> S;
		if(S == "insert") {
			cin >> X;
			Q.push(X);
			records.emplace_back(0, X);
		}
		else if(S == "getMin") {
			cin >> X;
			while(!Q.empty() and Q.top() < X) {
				Q.pop();
				records.emplace_back(2, 2);
			}
			if(Q.empty() or Q.top() > X) {
				Q.push(X);
				records.emplace_back(0, X);
			}
			records.emplace_back(1, X);	
		}
		else if(S == "removeMin") {
			if(Q.empty())
				records.emplace_back(0, 0);
			else
				Q.pop();
			records.emplace_back(2, 2);	
		}
	}

	cout << records.size() << endl;
	for(pii &curr : records) {
		if(curr.first == 0)
			printf("insert %d\n", curr.second);
		else if(curr.first == 1)
			printf("getMin %d\n", curr.second);
		else	
			printf("removeMin\n");
	}
}
