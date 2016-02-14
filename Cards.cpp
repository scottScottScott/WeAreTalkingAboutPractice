#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int visited[200 + 1][200 + 1][200 + 1];

void r_dp(int B, int G, int R, bool &B_last, bool &G_last, bool &R_last) {
	if(B < 0 or G < 0 or R < 0)
		return;

	if(visited[B][G][R] == 1)
		return;

	visited[B][G][R] = 1;

	if(B + G + R == 1) {
		if(B == 1)
			B_last = true;
		else if(G == 1)
			G_last = true;
		else if(R == 1)
			R_last = true;
		return;
	}

	if(B >= 2) {
		r_dp(B - 1, G, R, B_last, G_last, R_last);
	}
	if(G >= 2) {
		r_dp(B, G - 1, R, B_last, G_last, R_last);
	}	
	if(R >= 2) {
		r_dp(B, G, R - 1, B_last, G_last, R_last);
	}	

	if(B >= 1 and G >= 1) {
		r_dp(B - 1, G - 1, R + 1, B_last, G_last, R_last);
	}
	if(B >= 1 and R >= 1) {
		r_dp(B - 1, G + 1, R - 1, B_last, G_last, R_last);
	}
	if(G >= 1 and R >= 1) {
		r_dp(B + 1, G - 1, R - 1, B_last, G_last, R_last);
	}

}

int main() {
	int N;
	cin >> N;

	memset(visited, -1, sizeof(visited));
		
	int B, G, R;
	B = G = R = 0;

	for(int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		
		switch(temp) {
			case 'B':
				B++;
				break;
			case 'G':
				G++;
				break;
			case 'R':
				R++;
				break;
		}
	}

	bool B_last, G_last, R_last;
	B_last = G_last = R_last = false;
	r_dp(B, G, R, B_last, G_last, R_last);	

	string outputStr;
	if(B_last)
		outputStr += 'B';
	if(G_last)
		outputStr += 'G';
	if(R_last)
		outputStr += 'R';
	
	cout << outputStr << endl;
}
