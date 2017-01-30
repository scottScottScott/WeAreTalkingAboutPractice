#include <iostream>
#include <vector>

using namespace std;

void r_config(vector<vector<int>> &choices, vector<int>& currChoice, int B, int D, int N) {
	if(currChoice.size() == D) {
		choices.push_back(currChoice);
		return;
	}

	for(int i = 1; i <= B; i++) {
		currChoice.push_back(i);
		r_config(choices, currChoice, B, D, N);
		currChoice.pop_back();
		if(choices.size() >= N)
			return;
	}
}

int main() {
	int N, B, D;
	cin >> N >> B >> D;

	bool valid = false;
	long long count = 0;
	for(int i = 0; i < D; i++) {
		if(i == 0) count = B;	
		else count *= B;

		if(count >= N) {
			valid = true;	
			break;
		}
	}
	if(!valid) {
		cout << -1 << endl;
		return 0;
	}

	vector<vector<int>> choices;
	vector<int> currChoice;
	r_config(choices, currChoice, B, D, N);

	for(int day = 0; day < D; day++) {
		for(int student = 0; student < N; student++) {
			if(student != 0) printf(" ");
			printf("%d", choices[student][day]);
		}
		cout << endl;
	}
}
