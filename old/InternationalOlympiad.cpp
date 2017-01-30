#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		char temp;
		for(int i = 0; i < 4; i++) cin >> temp;
		string curr;
		cin >> curr;
		long long start;
		long long place = 1;
		reverse(curr.begin(), curr.end());
		for(int i = 0; i < curr.size(); i++) {
			place *= 10;
			int digit = curr[i] - '0';
			if(i == 0) {
				if(digit == 9) start = 1989;
				else start = 1990 + digit;
			}
			else {
				string start_str = to_string(start);
				int N = start_str.size();
				if(i >= N or (i == N - 1 and digit == start_str[i]) ) {
					start_str = curr.substr(0, i + 1);	
					if(digit == 0 or digit == start_str[i])
						start_str += "1";	
					reverse(start_str.begin(), start_str.end());
				}
				else if( start_str[N - 1 - i] - '0' < digit) {
					start_str[N - 1 - i] = curr[i];
				}
				else {
					start -= start % place;
					start += place;
					start_str = to_string(start);
					N = start_str.size();
					for(int j = 0; j <= i; j++) {
						start_str[N - 1 - j] = curr[j];
					}
				}
				start = stoll(start_str);
			}
		}
		cout << start << endl;
	}
}
