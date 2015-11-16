#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("theme.in");
	ofstream fout("theme.out");

	int N;
	fin >> N;

	if(N < 10)  {
		fout << 0 << endl;
		return 0;
	}

	vector<int> changes;
	int prev;

	fin >> prev;
	for(int i = 1; i < N; i++) {
		int curr;
		fin >> curr;
		changes.push_back(curr - prev);
		prev = curr;
	}
	N--;

	int max_length = 0;
	for(int a = 0; a < N - 9; a++) {
		if((N - a) / 2 < max_length)
			continue;
		for(int b = a + 5; b < N - 4; b++) {
			int i = a;
			int j = b;
			int dist = 0;
			while(i < b - 1 && j < N && changes[i++] == changes[j++]) {
				dist++;
			}
			max_length = max(dist, max_length);
		}
	}
	max_length++;

	if(max_length < 5)
		fout << 0 << endl;
	else
		fout << max_length << endl;
}
