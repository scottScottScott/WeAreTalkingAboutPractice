#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int getGCD(int a, int b) {
	int gcd = 1;
	int minNum = min(a, b);
	int maxnum = max(a, b);
	for(int i = 2; i <= minNum; i++) {
		if(a % i == 0 && b % i == 0)	
			gcd = i;
	}
	return gcd;
}

int main() {
	ifstream fin("nuggets.in");
	ofstream fout("nuggets.out");

	int N;
	fin >> N;

	vector<int> numbers(N);
	for(int i = 0; i < N; i++) {
		fin >> numbers[i];
	}

	int gcd = numbers[0];
	for(int i = 1; i < N; i++) {
		gcd = getGCD(gcd, numbers[i]);
	}
	if(gcd != 1) {
		fout << 0 << endl;
		return 0;
	}
		
	int minNum = *(min_element(numbers.begin(), numbers.end()));
	int numRepeats = 0;	
	int currNum = 0;
	int impossible = 0;
	vector<bool> memo;
	memo.push_back(1);
	while(numRepeats != minNum) {
		currNum++;
		int i;
		for(i = 0; i < N; i++) {
			if(currNum - numbers[i] >= 0 && memo[currNum - numbers[i]]) {
				break;
			}
		}
		if(i != N) {
			memo.push_back(1);
			numRepeats++;
		}
		else {
			memo.push_back(0);
			numRepeats = 0;
			impossible = currNum;
		}
	}

	cout << impossible << endl;
	fout << impossible << endl;

	return 0;
}
