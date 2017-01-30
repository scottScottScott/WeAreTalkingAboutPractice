#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class SegmentTree {
	public:
		SegmentTree(vector<long long> &input) {
			N = input.size();
			nodes.resize(getTreeSize(N));
			buildTree(input, 1, 0, N - 1);	
		}
		
		long long getMax(int lo, int hi) {
			return getMax(1, 0, N - 1, lo, hi);
		}
	
		void update(int index, long long value) {
			update(1, 0, N - 1, index, value);
		}

	private:
		int N;
		vector<long long> nodes;

		int getTreeSize(int N) {
			int size = 1;
			for( ; size < N; size <<= 1);
			return size << 1;
		}

		void buildTree(vector<long long> &input, int stIndex, int lo, int hi) {
			if(lo == hi) {
				nodes[stIndex] = input[lo];
				return;
			}
			
			int left = 2 * stIndex;
			int right = left + 1;
			int mid = (lo + hi) / 2;
			
			buildTree(input, left, lo, mid);
			buildTree(input, right, mid + 1, hi);
			nodes[stIndex] = max(nodes[left], nodes[right]);
		}

		long long getMax(int stIndex, int left, int right, int lo, int hi) {
			if(left == lo and right == hi)
				return nodes[stIndex];
			
			int mid = (left + right) / 2;
			if(lo > mid) 
				return getMax(2 * stIndex + 1, mid + 1, right, lo, hi);
			if(hi <= mid)
				return getMax(2 * stIndex, left, mid, lo, hi);

			long long leftResult = getMax(2 * stIndex, left, mid, lo, mid);
			long long rightResult = getMax(2 * stIndex + 1, mid + 1, right, mid + 1, hi);

			return max(leftResult, rightResult);
		}

		void update(int stIndex, int lo, int hi, int index, long long value) {
			if(lo == hi) {
				nodes[stIndex] = value;
				return;
			}

			int left = 2 * stIndex;
			int right = left + 1;
			int mid = (lo + hi) / 2;
			
			if(index <= mid)
				update(left, lo, mid, index, value);
			else 
				update(right, mid + 1, hi, index, value);

			nodes[stIndex] = max(nodes[left], nodes[right]);
		}
};

int main() {
	const double PI = 3.1415926535;
	int N;
	cin >> N;
	vector<long long> info;	
	for(int i = 0; i < N; i++) {
		long long R, H;
		cin >> R >> H;
		info.push_back(R * R * H);
	}
	
	vector<long long> info_copy = info;
	sort(info_copy.begin(), info_copy.end());
	unordered_map<long long, int> M;
	for(int i = 0; i < N; i++) {
		M[info_copy[i]] = i;
	}

	vector<long long> empty(N);
	SegmentTree ST(empty);
	long long maxVal = 0;
	for(long long X : info) {
		long long val = ST.getMax(0, M[X]);	
		ST.update(M[X], X + val);	
		maxVal = max(maxVal, X + val);
		M[X]--;
	}	
	cout.precision(20);
	cout << fixed << (double) maxVal * PI << endl;
}
