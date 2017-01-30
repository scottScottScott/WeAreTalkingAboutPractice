#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

struct Node {
	Node(int X): val{X}, rank{0}, parent{this} {}
	int val;
	int rank;
	Node* parent;
};

Node* Find_Set(Node *A) {
	if(A != A->parent)
		A->parent = Find_Set(A->parent);
	return A->parent;
}

void Link(Node *A, Node *B) {
	if(A->rank > B->rank)
		B->parent = A;
	else {
		A->parent = B;
		if(A->rank == B->rank)
			B->rank++;
	}
}

void Union(Node *A, Node *B) {
	Link(Find_Set(A), Find_Set(B));
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<pii> blue, red;
	for(int i = 0; i < M; i++) {
		char color;
		int U, V;
		cin >> color >> U >> V;
		U--, V--;
		if(color == 'R')
			red.emplace_back(U, V);
		else if(color == 'B')
			blue.emplace_back(U, V);
	}

	int numBlue = 0;
	vector<Node*> Nodes(N);
	for(int i = 0; i < N; i++)
		Nodes[i] = new Node(i);
	for(pii curr : red) {
		if(Find_Set(Nodes[curr.first]) != Find_Set(Nodes[curr.second])) {
			Union(Nodes[curr.first], Nodes[curr.second]);			
		}
	}
	for(pii curr : blue) {
		if(Find_Set(Nodes[curr.first]) != Find_Set(Nodes[curr.second])) {
			Union(Nodes[curr.first], Nodes[curr.second]);			
			numBlue++;
		}
	}

	if(numBlue > K) {
		printf("0\n");
		return 0;
	}

	int blueUsed = 0;
	Nodes.clear();	
	Nodes.resize(N);
	for(int i = 0; i < N; i++)
		Nodes[i] = new Node(i);
	for(pii curr : blue) {
		if(Find_Set(Nodes[curr.first]) != Find_Set(Nodes[curr.second])) {
			Union(Nodes[curr.first], Nodes[curr.second]);			
			blueUsed++;
		}
	}

	cout << (blueUsed >= K ? 1 : 0) << endl;
}
