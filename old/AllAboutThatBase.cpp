#include <iostream>
#include <cctype>

using namespace std;

char print_base(int base) {
	if(base <= 9)
		return base + '0';
	if(base == 36)
		return '0';
	return 'a' + (base - 10);
}

bool valid(string str, int base) {
	if(base == 36)
		return true;

	bool isLetter = false;
	char cap;
	if(base > 10) {
		isLetter = true;
		cap = 'a' + (base - 11);
	}
	for(int i = 0; i < str.size(); i++) {
		if(base == 1) {
			if(str[i] != '1')
				return false;
		}
		else {
			if(isdigit(str[i])) {
				if( !(isLetter || (str[i] - '0') < base) )
					return false;
			}
			else {
				if(str[i] > cap)
					return false;
			}
		}
	}
	return true;
}

int to_number(char ch) {
	if('0' <= ch and ch <= '9')
		return ch - '0';
	else
		return (ch - 'a') + 10;
}

int convert(string str, int base) {
	int result = 0;
	for(int i = 0; i < str.size(); i++) {
		result *= base;
		result += to_number(str[i]);	
	}
	return result;
}

int main() {
	int N;	
	cin >> N;
	while(N--) {
		string first, second, result;
		char operation, equal;
		bool found = false;
		cin >> first >> operation >> second >> equal >> result;
		for(int base = 1; base <= 36; base++) {
			if(!valid(first, base) || !valid(second, base) || !valid(result, base))
				continue;
			double a = convert(first, base);
			double b = convert(second, base);
			double c = convert(result, base);
			switch(operation) {
				case '+' : {
					if(a + b == c) {
						found = true;
						cout << print_base(base);
					}
					break;
				}
				case '-' : {
					if(a - b == c) {
						found = true;
						cout << print_base(base);
					}
					break;
				}
				case '*' : {
					if(a * b == c) {
						found = true;
						cout << print_base(base);
					}	
					break;
				}
				case '/' : {
					if(a / b == c) {
						found = true;
						cout << print_base(base);
					}
					break;
				}
			}
		}

		if(!found)
			cout << "invalid";
		cout << endl;
	}
}
