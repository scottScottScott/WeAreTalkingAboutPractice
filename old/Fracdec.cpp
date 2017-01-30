#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");

	int num, denom;
	fin >> num >> denom;

	int intVal = 0;
	while(num >= denom) {
		intVal++;
		num -= denom;
	}

	map<int, int> remainder;	
	vector<int> deciDigit;
	while(true) {
		int currRemain = num;

		if(currRemain == 0 || remainder.count(currRemain)) {
			string result = to_string(intVal) + ".";
			for(int i = 0; i < deciDigit.size(); i++) {
				if(i == remainder[currRemain] && currRemain != 0) {
					result += "(";
				}
				result += to_string(deciDigit[i]);
			}
			if(deciDigit.size() == 0)
				result += "0";
			if(num != 0)
				result += ")";
			int numCharacters;	
			for(int j = 0; j < result.size(); j++) {
				fout << result[j];
				if( (j + 1) % 76 == 0) 
					fout << endl;
			}
			if(result.size() % 76 != 0)
				fout << endl;
			return 0;
		}

		num *= 10;
		int currDigit = num / denom;
		num = num - currDigit * denom;	
		deciDigit.push_back(currDigit);
		remainder[currRemain] = deciDigit.size() - 1;
	}	
	
	return 0;
}
