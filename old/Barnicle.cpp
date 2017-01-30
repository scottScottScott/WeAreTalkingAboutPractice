#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int d = -1;
	int e = -1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '.') d = i;
		else if(s[i] == 'e') e = i;
	}
	string temp = s.substr(e + 1);
	int b = stoi(temp);
	s = s.substr(0, e);
	for(int i = 0; i < b; i++, d++) {
		if(d + 1 < s.size()) {
			s[d] = s[d + 1];
			s[d + 1] = '.';
		}
		else if(d < s.size())
			s[d] = '0';	
		else 	
			s += '0';
	}
	reverse(s.begin(), s.end());
	while(s.back() == '0' and s.size() > 2 and s[s.size() - 2] != '.') 
		s.pop_back(); 
	reverse(s.begin(), s.end());
	while(s.back() == '.' or (s.size() > 2 and s.back() == '0' and s[s.size() - 2] == '.')) 
		s.pop_back();
	cout << s << endl;
}
