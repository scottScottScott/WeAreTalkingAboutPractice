#include <iostream>
#include <vector>

using namespace std;

vector<int> Parent;
vector<int> Rank;

int Find(int A) {
	if(A != Parent[A])
		Parent[A] = Find(Parent[A]);
	return Parent[A];
}

void Link(int A, int B) {
	if(A == B) return;
	
	if(Rank[A] > Rank[B])
		Parent[B] = A;
	else {
		Parent[A] = B;
		if(Rank[B] == Rank[A])
			Rank[B]++;
	}
}

void Union(int A, int B) {
	Link(Find(A), Find(B));
}

int main() {
	int N, Q;
	cin >> N >> Q;
	Parent.resize(N);
	Rank.resize(N);
	for(int i = 0; i < N; i++)
		Parent[i] = i;
	for(int i = 0; i < Q; i++) {
		char C;
		int a, b;
		cin >> C >> a >> b;
		if(C == '=') {
			Union(a, b);
		}
		else if(C == '?') {
			if(Find(a) == Find(b))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
}
