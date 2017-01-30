#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");
	unsigned long N, L, I;
	fin >> N >> L >> I;

	int choose[N][N + 1];
	memset(choose, 0, sizeof(choose));
	choose[0][0] = 1;
	for(int n = 1; n < N; n++) {
		choose[n][0] = choose[n - 1][0];
		cout << choose[n][0] << " ";
		for(int l = 1; l <= N; l++) {
			choose[n][l] = choose[n - 1][l - 1] + choose[n - 1][l]; 
			cout << choose[n][l] << " ";
		}
		cout << endl;
	}

	int memo[N][L + 1];
	memset(memo, 0, sizeof(memo));
	for(int l = 0; l <= L; l++) {
		memo[0][l] = 0;
	}
	for(int n = 1; n < N; n++) {
		memo[n][0] = 1;
		cout << "n: " << n << " i: " << 0 << " COMBOS: " << memo[n][0] << endl;
		for(int l = 1; l <= L; l++) {
			memo[n][l] = memo[n][l - 1] + choose[n][l];	
			cout << "n: " << n << " i: " << l << " COMBOS: " << memo[n][l] << endl;
		}
	}
	string ret;
	int l = L;
	for(int n = N; n > 0; n--) {
		cout << I << " " << n - 1 << " " << l << " " << memo[n - 1][l] << endl;
		if(n == 1) {
			if(I == 1)
				ret += "0";
			else
				ret += "1";
			break;
		}
		if(I <= memo[n - 1][l]) {
			ret += "0";
		} 
		else {
			ret += "1";
			I -= memo[n - 1][l];
			l -= 1;
		}
	}
	fout << ret << endl;
	return 0;
}
