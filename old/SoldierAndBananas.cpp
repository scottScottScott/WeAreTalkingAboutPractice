#include <iostream>

using namespace std;

int main() {
	int K, W, N;
	cin >> K >> N >> W;
	int totCost = 0;
	for(int w = 1; w <= W; w++)
		totCost += w * K;
	int borrow = (totCost > N ? totCost - N : 0);
	cout << borrow << endl;
}
