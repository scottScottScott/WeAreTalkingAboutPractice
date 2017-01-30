#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> beauty(N);
	for(int i = 0; i < beauty.size(); i++)
		cin >> beauty[i];
	sort(beauty.begin(), beauty.end());
	vector<int> repeat(N + 1);
	int currVal = -1;
	int currRep = -1;
	for(int i = 0; i < beauty.size(); i++) {
		if(i == 0 or beauty[i] != beauty[i - 1]) {
			currVal = beauty[0];
			currRep = 1;
		}	
		else {
			currRep++;
		}
		repeat[currRep]++;
	}	
	int count = 0;
	for(int X : repeat) {
		if(X > 1)
			count += X - 1;
	}
	cout << count << endl;
}
