#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<char> operators;
	int numPlus = 1;
	
	char c;
	while(cin >> c) {
		if(c == '?') continue;
		else if(c == ' ') continue;
		else if(c == '+') numPlus++;
		else if(c == '=') {
			cin >> N;
			break;
		}
		operators.push_back(c);
	}	

	int numMinus = operators.size() + 1 - numPlus;
	if(N * numPlus - numMinus >= N and numPlus - N * numMinus <= N) {
		cout << "Possible" << endl;
		vector<int> Plus;
		vector<int> Minus;
		if(numPlus == numMinus + 1) {
			Plus.resize(numPlus, N);		
			Minus.resize(numMinus, N);
		}
		else if(numPlus > numMinus + 1) {
			Minus.resize(numMinus, N);	
			int total = N * (numMinus + 1);
			Plus.resize(numPlus, 1);
			total -= numPlus;
			for(int &X : Plus) {
				if(total > 0) {
					X += min(N - 1, total);
					total -= min(N - 1, total);	
				}
			}
		}
		else { 
			Plus.resize(numPlus, N);	
			int total = N * (numPlus - 1);
			Minus.resize(numMinus, 1);
			total -= numMinus;
			for(int &X : Minus) {
				if(total > 0) {
					X += min(N - 1, total);
					total -= min(N - 1, total);	
				}
			}
		}

		int p_idx = 0;
		int m_idx = 0;
		cout << Plus[p_idx++] << " ";
		for(char X : operators) {
			if(X == '+') cout << "+ " << Plus[p_idx++] << " ";
			if(X == '-') cout << "- " << Minus[m_idx++] << " ";
		}
		cout << "= " << N << endl;
	}
	else cout << "Impossible" << endl;
}
