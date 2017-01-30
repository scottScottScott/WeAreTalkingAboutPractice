#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long A, long long B) {
	while(B != 0) {
		long long temp = B;
		B = A % B;
		A = temp;
	}
	return A;
}

long long LCM(long long A, long long B) {
	long long gcd = GCD(A, B);
	long long retVal = (A / gcd) * B;
	return retVal;
}

int main() {
	int N;
	cin >> N;
	long long totalApples = 0;
	vector<int> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		totalApples += A[i];
	}
	vector<vector<int>> adjList(N);
	for(int i = 1; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		X--, Y--;
		adjList[X].push_back(Y);	
		adjList[Y].push_back(X);
	}
	
	vector<int> seen(N, -1);
	seen[0] = 0;
	vector<vector<int>> layers;
	vector<int> curr_layer{0};
	while(!curr_layer.empty()) {
		layers.push_back(curr_layer);	
		vector<int> next_layer;
		for(int node : curr_layer) {
			for(int Y : adjList[node]) {
				if(seen[Y] == -1) { 
					next_layer.push_back(Y);
					seen[Y] = layers.size();
				}
			}
		}
		curr_layer = move(next_layer);
	}	

	vector<long long> B(A.begin(), A.end());	
	vector<long long> multiple(N, 1);
	int numLayers = layers.size();
	for(int i = numLayers - 2; i >= 0; i--) {
		for(int X : layers[i]) {
			int numChildren = 0;
			long long minApples = -1;
			long long lcm = 1;
			for(int Y : adjList[X]) {
				if(seen[Y] > i) {
					numChildren++;	
					lcm = LCM(lcm, multiple[Y]);
				}
			}
			if(numChildren == 0) continue;
			for(int Y : adjList[X]) {
				if(seen[Y] > i) {
					long long divisor = lcm / multiple[Y];
					long long tempVal = (B[Y] - (B[Y] % divisor)) / divisor;
					if(minApples == -1) minApples = tempVal;
					minApples = min(tempVal, minApples);
				}
			}
			multiple[X] = numChildren * lcm;
			B[X] = minApples;	
			if(minApples == 0) {
				cout << totalApples << endl;
				return 0;
			}
		}	
	}

	cout << totalApples - B[0] * multiple[0] << endl;
}
