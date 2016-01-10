#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");

	int Goal[3];
	fin >> Goal[0] >> Goal[1] >> Goal[2];
	int Mixtures[3][3];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			fin >> Mixtures[i][j];
		}
	}

	int min = -1;
	int solution[4];
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			for(int k = 0; k < 100; k++) {
				int feed[3];
				int z;
				int multiple = -1;
				for(z = 0; z < 3; z++) {
					feed[z] = i * Mixtures[0][z] + j * Mixtures[1][z] + k * Mixtures[2][z];
					if(Goal[z] == 0) {
						if(feed[z] != 0)
							break;
						else 
							continue;
					}
					if(multiple == -1)
						multiple = feed[z] / Goal[z];

					if(Goal[z] * multiple != feed[z] || multiple == 0)
						break;
				}
				if(z == 3 && (min == -1 || i + j + k < min)) {
					min = i + j + k;
					solution[0] = i;
					solution[1] = j;
					solution[2] = k;
					solution[3] = multiple;
				}
			}
		}
	}	

	if(min == -1)
		fout << "NONE" << endl;
	else
		fout << solution[0] << " " << solution[1]  << " " << solution[2] << " " << solution[3] << endl;	

	return 0;	
}
