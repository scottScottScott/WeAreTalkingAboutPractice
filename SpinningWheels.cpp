#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isInside(int a, int b, int c) {
	if(a <= b) {
		if(c >= a and c <= b)
			return true;
		else
			return false;
	} 
	else if(a > b) {
		if(c >= a || c <= b)
			return true;
		else
			return false;
	}
}

int main() {
	ifstream fin("spin.in");
	ofstream fout("spin.out");

	vector<int> start[5];
	vector<int> extent[5];
	int speed[5];
	for(int i = 0; i < 5; i++) {
		fin >> speed[i];
		int numWedges;	
		fin >> numWedges;
		for(int j = 0; j < numWedges; j++) {
			int S, E;
			fin >> S >> E;
			start[i].push_back(S);
			extent[i].push_back(E);
		}
	} 

	for(int s = 0; s < 360; s++) {
		for(int z = 0; z < 360; z++) {
			bool possible;
			for(int i = 0; i < 5; i++) {
				possible = false;
				for(int j = 0; j < start[i].size(); j++) {
					int fst = start[i][j];
					int snd = (start[i][j] + extent[i][j]) % 360;
					if(isInside(fst, snd, z))
						possible = true;
				}
				if(!possible)
					break;
			}
			if(possible) {
				fout << s << endl;	
				return 0;
			}
		}

		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < start[i].size(); j++) {
				start[i][j] = (start[i][j] + speed[i]) % 360;
			}
		}
	}
	
	fout << "none" << endl;
	return 0;
}
