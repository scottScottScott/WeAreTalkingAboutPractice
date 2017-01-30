#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if(a.first > b.first)
		return true;
	else if(a.first < b.first) 
		return false;

	if(a.second.size() < b.second.size())
		return true;
	else if(b.second.size() < a.second.size())
		return false;

	if(a.second < b.second)
		return true;
	else
		return false;
}

int main() {
	ifstream fin("contact.in");
	ofstream fout("contact.out");

	int A, B, N;
	fin >> A >> B >> N;
	string line;
	string str;
	getline(fin, line);
	while(getline(fin, line)) {
		str += line;
	}
	vector<int> pow(13);
	int curr = 1;
	for(int i = 0; i <= 12; i++) {
		pow[i] = curr;
		curr *= 2;
	}

	vector< vector<int> > count(13);
	for(int i = A; i <= B; i++) {
		count[i].resize(pow[i]);
		int temp = 0;
		for(int j = 0; j < (int) str.size() - (i - 1); j++) {
			if(j == 0) {
				for(int k = 0; k < i; k++) {
					temp += (str[k] - '0') * pow[i - k - 1];	
				}
			}
			else {
				temp -= (str[j - 1] - '0') * pow[i - 1];
				temp *= 2;
				temp += str[j + i - 1] - '0';
			}
			count[i][temp] += 1;
		}
	}

	vector< pair<int, string> > info;
	for(int i = A; i<= B; i++) {
		for(int j = 0; j < count[i].size(); j++) {
			if(count[i][j] > 0) {
				int currVal = j;
				string tempStr;
				while(currVal != 0) {
					if(currVal % 2 == 1) {
						tempStr = "1" + tempStr;
					}
					else
						tempStr = "0" + tempStr;
					currVal /= 2;	
				}
				while(tempStr.size() < i)
					tempStr = "0" + tempStr;
				info.push_back(make_pair(count[i][j], tempStr));
			}
		}
	}

	sort(info.begin(), info.end(), cmp);
	int currIndex = 0;
	int currFreq = 0;

	for(int i = 0; i < N; i++) {
		if(currIndex >= info.size())
			break;
		currFreq = info[currIndex].first;
		fout << currFreq << endl;
		bool first = true;
		int count = 0;
		while(info[currIndex].first == currFreq) {
			if(first) {
				fout << info[currIndex].second;	
				first = false;
			}
			else
				fout << " " << info[currIndex].second;
			currIndex++;
			count++;
			if(count % 6 == 0) {
				fout << endl;
				first = true;
			}
			if(currIndex >= info.size())
				break;
		}
		if(count % 6 != 0)
			fout << endl;
	}	
	
	return 0;
}
