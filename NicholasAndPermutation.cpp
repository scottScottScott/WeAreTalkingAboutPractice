#include <iostream>

using namespace std;

int main() {
	int N;
	int loc_1, loc_2;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		int temp;	
		cin >> temp;
		if(temp == 1) loc_1 = i;
		else if(temp == N) loc_2 = i;
	}

	int min_loc = min(loc_1, loc_2);
	int max_loc = max(loc_1, loc_2);

	if(min_loc - 1 >= N - max_loc) min_loc = 1;
	else max_loc = N;

	cout << max_loc - min_loc << endl;
}
