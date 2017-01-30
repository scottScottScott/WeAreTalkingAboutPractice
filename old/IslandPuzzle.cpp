#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> start;
	vector<int> end;
	
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if(temp != 0)
			start.push_back(temp);
	}
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if(temp != 0)
			end.push_back(temp);
	}

	int j = 0;
	for(int i = 0; i < N; i++) {
		if(end[i] == start[j]) {
			while(N--) {
				j = (j + 1) % start.size();
				i = (i + 1) % end.size();
				if(end[i] != start[j]) {
					cout << "NO" << endl;
					return 0;
				}
			}
			cout << "YES" << endl;
			return 0;
		}	
	}
	return 0;
}
