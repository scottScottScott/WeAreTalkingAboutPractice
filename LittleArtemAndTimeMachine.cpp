#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct info {
	int order, time, type;
	info(int order, int time, int type) : order(order), time(time), type(type) {}
};

class Fenwick {
	public:
		Fenwick(int N) {
			size = N;
			storage.resize(size + 1);
		}

		void add(int i, int val) {
			for( ; i <= size; i += (i & -i)) 
				storage[i] += val;
		}

		int count(int i) {
			int result = 0;
			for( ; i > 0; i -= (i & -i)) 
				result += storage[i];
			return result;
		}
	private:
		int size;
		vector<int> storage;
};

int main() {
	int N;
	cin >> N;
	
	map<int, vector<info>> M;	
	for(int i = 0; i < N; i++) {
		int A, T, X;	
		scanf("%d %d %d", &A, &T, &X);
		M[X].emplace_back(i, T, A);	
	}

	unordered_map<int, int> result;
	for(auto iter = M.begin(); iter != M.end(); iter++) {
		vector<info> &curr_V = iter->second;		
		vector<int> time_V;
		for(info &X : curr_V)
			time_V.push_back(X.time);
		sort(time_V.begin(), time_V.end());
		int N = time_V.size();
		unordered_map<int, int> other_T;
		for(int i = 0; i < N; i++) 
			other_T[time_V[i]] = i;

		Fenwick F(N);
		for(info &X : curr_V) {
			int other_time = other_T[X.time];
			if(X.type == 1) 
				F.add(other_time + 1, 1);
			else if(X.type == 2) 
				F.add(other_time + 1, -1);
			else {
				int count = F.count(other_time);
				result[X.order] = count;	
			}
		}
	}	

	for(int i = 0; i < N; i++)
		if(result.count(i)) printf("%d\n", result[i]);
}
