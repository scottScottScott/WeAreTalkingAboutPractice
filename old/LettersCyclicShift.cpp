#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;	
	cin >> s;
	int n = s.size();
	bool done = false;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'a') continue;	
		else {
			done = true;
			int j = i;
			while(j < n and s[j] != 'a')
				s[j++]--;	
			break;
		}
	}
	if(!done)
		s.back() = 'z';
	cout << s << endl;
}
