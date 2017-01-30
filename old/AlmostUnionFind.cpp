#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> Parent; 
vector<int> Rank;
vector<int> OldParent; 
vector<int> Sum;
vector<int> Number;

int r_Find(int A) {
	if(A != Parent[A]) {
		if(OldParent[A] != 0) {
			if(A == OldParent[A])
				return A;
			return r_Find(OldParent[A]);
		}
		else
			Parent[A] = r_Find(Parent[A]);
	}
	return Parent[A];
}

int Find(int A) {
	if(A != Parent[A])
		Parent[A] = r_Find(Parent[A]);
	return Parent[A];
}

void Link(int A, int B) {
	if(A == B) return;	

	if(Rank[A] > Rank[B]) {
		if(OldParent[B] == 0)
			Parent[B] = A;
		else
			OldParent[B] = A;

		Sum[A] += Sum[B];
		Number[A] += Number[B];
	}
	else {
		if(OldParent[A] == 0)
			Parent[A] = B;
		else
			OldParent[A] = B;

		if(Rank[A] == Rank[B])
			Rank[B]++;

		Sum[B] += Sum[A];
		Number[B] += Number[A];
	}
}

void Union(int A, int B) {
	Link(Find(A), Find(B));
}

void Move(int A, int B) {
	int set_A = Find(A);
	int set_B = Find(B);
	if(set_A == set_B) return;

	Sum[set_B] += A;	
	Sum[set_A] -= A;	
	Number[set_B]++;
	Number[set_A]--;

	if(OldParent[A] == 0)
		OldParent[A] = Parent[A];
	Parent[A] = set_B;
}

int getNumber(int A) {
	return Number[Find(A)];
}

int getSum(int A) {
	return Sum[Find(A)];
}

int main() {
	string line;
	getline(cin, line);
	while(line != "") {
		int N, M;
		istringstream iss(line);
		iss >> N >> M;
		Parent.clear();
		Parent.resize(N + 1, 0);
		Sum.clear();
		Sum.resize(N + 1, 0);
		Rank.clear();
		Rank.resize(N + 1, 0);
		Number.clear();
		Number.resize(N + 1, 1);
		OldParent.clear();
		OldParent.resize(N + 1, 0);
		for(int i = 1; i <= N; i++) {
			Parent[i] = i;
			Sum[i] = i;
		}
		for(int i = 0; i < M; i++) {
			int A, B, C;
			cin >> C;
			switch(C) {
				case 1:
					cin >> A >> B;
					Union(A, B);
					break;
				case 2:
					cin >> A >> B;
					Move(A, B);
					break;
				case 3:
					cin >> A;
					cout << getNumber(A) << " " << getSum(A) << endl;
					break;
			}
		}
		getline(cin, line);
		getline(cin, line);
	}
}
