#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

struct Node {
	Node(int X, int val) : left(X), right(X), minVal(val) {}; 	
	
	int left, right, minVal;
};

vector<int> Rank, parent;
vector<Node*> I;

int getParentIndex(int index) {
	if(parent[index] != index)
		parent[index] = getParentIndex(parent[index]);
	return parent[index];
}

Node* getParent(int index) {
	int i = getParentIndex(index);	
	return I[i];
}

void mergeCall(int A, int B) {
	Node *root;
	if(Rank[A] > Rank[B]) {
		parent[B] = A;
		root = I[A];
	}
	else {
		if(Rank[A] == Rank[B]) 
			Rank[B]++;
		parent[A] = B;
		root = I[B];
	}	

	root->minVal = min(I[A]->minVal, I[B]->minVal);
	root->right = max(I[A]->right, I[B]->right);
	root->left = min(I[A]->left, I[B]->left);
}

void merge(int A, int B) {
	mergeCall(getParentIndex(A), getParentIndex(B));	
}

int main() {
	int N;
	cin >> N;
	vector<int> height(N);
	vector<pii> H;
	for(int i = 0; i < N; i++) {
		scanf("%d", &height[i]);
		H.emplace_back(height[i], i);
	}
	sort(H.begin(), H.end());
	
	Rank.resize(N);
	parent.resize(N);
	I.resize(N);
	for(int i = 0; i < N; i++) {
		Rank[i] = 0;
		parent[i] = i;
		I[i] = new Node(i, height[i]);
	}

	bool valid;
	vector<int> result;
	for(int size = 1; size <= N; size++) {
		do {
			valid = false;
			pii curr = H.back();	
			int index = curr.second;
			int currVal = curr.first;
			int L, R;
			L = getParent(index)->left;
			R = getParent(index)->right;
			while(++R < N) {
				if(getParent(R)->minVal >= currVal) {
					merge(index, R);
					R = getParent(index)->right;
				}
				else break;
			}
			while(--L >= 0) {
				if(getParent(L)->minVal >= currVal) {
					merge(index, L);
					L = getParent(index)->left;
				}
				else break;
			}
			L = getParent(index)->left;
			R = getParent(index)->right;
			if(R - L + 1 >= size) {
				valid = true;
				result.push_back(currVal);
			}
			else
				H.pop_back();
		} while(valid == false);
	}
	
	for(int i = 0; i < N; i++) {
		printf("%d", result[i]);
		printf(i != N - 1 ? " " : "\n");
	}
}
