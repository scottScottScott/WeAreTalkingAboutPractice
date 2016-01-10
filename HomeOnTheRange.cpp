#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int getAddr(int a, int b, int c) {
	return a * 251 * 251 + b * 251 + c;
}

int main() {
	ifstream fin("range.in");
	ofstream fout("range.out");

	int N;
	fin >> N;
	vector<bool> memo(251 * 251 * 251, 0);
	//memset(memo, 0, sizeof(memo));
	for(int size = 1; size <= N; size++) {
		//cout << size << endl;
		if(size == 1) {
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= N ; j++) {
					char temp;
					fin >> temp;
					int addr = getAddr(i, j, size);
					memo[addr] = temp - '0';
				}
			}
			continue;
		}
		
		int numOfSize = 0;
		for(int i = 1; i <= N - size + 1; i++) {
			for(int j = 1; j <= N - size + 1; j++) {
				int ul, ur, ll, lr;
				int subSize;
				int gap;
				if(size % 2 == 1) {
					subSize = size / 2 + 1;	
					gap = 1;
				}
				else {
					subSize = size / 2;
					gap = 0;
				}
				//cout << "size: " << size << " subSize: " << subSize << endl;
				int addr;
				addr = getAddr(i, j, subSize);
				ul = memo[addr];

				addr = getAddr(i, j + subSize - gap, subSize);
				ur = memo[addr];

				addr = getAddr(i + subSize - gap, j, subSize);
				ll = memo[addr];	

				addr = getAddr(i + subSize - gap, j + subSize - gap, subSize);
				lr = memo[addr];
				//cout << ul << ur << endl; 
				//cout << ll << lr << endl;

				if(ul and ur and ll and lr) {
					addr = getAddr(i, j, size);
					memo[addr] = 1;	
					numOfSize++;
				}
			}
		}	
		if(numOfSize != 0)
			fout << size << " " << numOfSize << endl;
	}

	return 0;
}
