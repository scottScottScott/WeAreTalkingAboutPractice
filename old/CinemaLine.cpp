#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> change = {0, 0, 0};	
	while(N--) {
		int curr;
		cin >> curr;
		bool possible = true;

		switch(curr) {
			case 25:
				change[0]++;
				break;
			case 50:
				change[1]++;
				change[0]--;
				if(change[0] < 0) possible = false;
				break;
			case 100:
				change[2]++;
				change[0]--;
				if(change[1] > 0)
					change[1]--;
				else
					change[0] -= 2;
				if(change[0] < 0) possible = false;
				break;
		}

		if(!possible) {
			cout << "NO" << endl;
			return 0 ;
		}
	}
	cout << "YES" << endl;
}
