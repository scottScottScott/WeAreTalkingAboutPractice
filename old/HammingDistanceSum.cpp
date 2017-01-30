#include <iostream>
#include <string>

using namespace std;

int main() {
	string A, B;	
	cin >> A >> B;

	int zero_cnt = 0;
	int one_cnt = 0;
	
	for(int i = 0; i < B.size() - A.size() + 1; i++) {
		if(B[i] == '0') zero_cnt++;
		else one_cnt++;
	}

	long long result = 0;
	for(int i = 0; i < A.size(); i++) {
		if(A[i] == '0') result += one_cnt;	
		else result += zero_cnt;

		if(B[i] == '0') zero_cnt--;	
		else one_cnt--;

		int next = B.size() - A.size() + (i + 1);
		if(next < B.size()) {
			if(B[next] == '0') zero_cnt++;
			else one_cnt++;
		}
	}

	cout << result << endl;
}
