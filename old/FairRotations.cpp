#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> bread(N);
	for(int i = 0; i < N; i++)
		cin >> bread[i];
	int count = 0;
	for(int i = 0; i < N - 1; i++) {
		if(bread[i] % 2 == 1) {
			bread[i]++;
			bread[i + 1]++;
			count += 2;
		}
	}

	if(bread[N - 1] % 2 == 1)
		cout << "NO" << endl;
	else cout << count << endl;
}
