#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int numPoints(string str) {
	int pts = 0;
	for(char c: str) {
		switch(c) {
			case 'e':
			case 'i':
			case 's': 
				pts += 1;
				break;
			case 'r':
			case 't':
			case 'a':
			case 'n':
				pts += 2;
				break;
			case 'o':
			case 'l':
				pts += 3;
				break;
			case 'u':
			case 'd':
			case 'c':
				pts += 4;
				break;
			case 'y':
			case 'p':
			case 'g':
			case 'h':
			case 'b':
			case 'm':
				pts += 5;
				break;
			case 'w':
			case 'f':
			case 'k':
			case 'v':
				pts += 6;
				break;
			case 'q':
			case 'j':
			case 'z':
			case 'x':
				pts += 7;
				break;
		}
	}
	return pts;
}

int main() {
	ifstream fin("lgame.in");
	ifstream dictInput("lgame.dict");
	ofstream fout("lgame.out");

	unordered_map<string, bool> dict;
	string tempWord;
	while(dictInput >> tempWord and tempWord != ".") {
		dict[tempWord] = true;
	}
		
	vector<char> inputStrVec;
	char tempChar;
	while(fin >> tempChar)
		inputStrVec.push_back(tempChar);
	int length = inputStrVec.size();

	int score = 0;
	set<string> answers;	
	sort(inputStrVec.begin(), inputStrVec.end());
	do {
		string inputStr;
		for(char c: inputStrVec)
			inputStr += c;	
		for(int i = 3; i <= length; i++) {
			string temp = inputStr.substr(0, i);
			if(dict.count(temp)) {
				if(numPoints(temp) > score) {
					score = numPoints(temp);
					answers.clear();
					answers.insert(temp);
				}
				else if(numPoints(temp) == score)
					answers.insert(temp);
			}
		}
		for(int i = 3; i < min(length, 5); i++) {
			string first = inputStr.substr(0, i);
			string second = inputStr.substr(i, length - i);
			if(dict.count(first) and dict.count(second) and first <= second) {
				if(numPoints(first) + numPoints(second) > score) {
					score = numPoints(first) + numPoints(second);
					answers.clear();
					answers.insert(first + " " + second);
				}
				else if (numPoints(first) + numPoints(second) == score)
					answers.insert(first + " " + second);
			}
		}	
		if(length == 7) {
			string first = inputStr.substr(0, 3);
			string second = inputStr.substr(4, 3);
			if(dict.count(first) and dict.count(second) and first <= second) {
				if(numPoints(first) + numPoints(second) > score) {
					score = numPoints(first) + numPoints(second);
					answers.clear();
					answers.insert(first + " " + second);
				}
				else if (numPoints(first) + numPoints(second) == score)
					answers.insert(first + " " + second);
			}
		}
	} while(next_permutation(inputStrVec.begin(), inputStrVec.end()));

	fout << score << endl;
	for(string str: answers)
		fout << str << endl;
}
