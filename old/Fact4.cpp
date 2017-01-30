#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");

	int N;
	fin >> N;
	int num5s = 0;
	vector<int> numbers(N + 1);
	for(int i = 1; i <= N; i++) {
		int temp = i;
		while(temp % 5 == 0) {
			temp /= 5;
			num5s++;
		}
		numbers[i] = temp;
	}
	for(int i = 1; i <= N; i++) {
		int temp = numbers[i];
		if(num5s == 0)
			break;
		while(temp % 2 == 0 && num5s > 0) {
			temp = temp / 2;
			num5s--;
		}
		numbers[i] = temp;
	}
	int rightMost = 1;
	for(int i = 1; i <= N; i++) {
		rightMost = rightMost * numbers[i];
		rightMost = rightMost % 10;
	}

	fout << rightMost << endl;

	return 0;
}
