#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> storage(N);
	for(int i = 0; i < N; i++)
		cin >> storage[i];
	sort(storage.begin(), storage.end());	

	int temp = storage[0];
	storage[0] = storage[N - 1];
	storage[N - 1] = temp;

	for(int i = 0; i < N; i++) {
		cout << storage[i];
		if(i != N - 1)
			cout << " ";
	}
	cout << endl;
}
