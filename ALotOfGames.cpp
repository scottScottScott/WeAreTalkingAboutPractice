#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
	public:
		Node() {
			next.resize(26);
		}
	vector<Node*> next;	
};

Node *root = new Node();

void addWord(string str) {
	Node *curr = root;	
	for(char C : str) {
		int X = C - 'a';
		if(curr->next[X] == nullptr)
			curr->next[X] = new Node();
		curr = curr->next[X];
	}
}

bool r_win(Node *curr) {
	for(int i = 0; i < 26; i++) {
		if(curr->next[i] == nullptr)
			continue;
		bool step = r_win(curr->next[i]);
		if(step == 1) return 0;
	}
	return 1;
}

bool r_lose(Node *curr) {
	bool isEnd = true;
	for(int i = 0; i < 26; i++) {
		if(curr->next[i] == nullptr)
			continue;
		isEnd = false;
		bool step = r_lose(curr->next[i]);
		if(step == 1) return 0; 
	}
	return !isEnd; 
}

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		addWord(s);		
	}
		
	bool canWin = false;
	bool canLose = false;
	for(int i = 0; i < 26; i++) {
		if(root->next[i] == nullptr) continue;
		if(r_win(root->next[i])) canWin = true;
		if(r_lose(root->next[i])) canLose = true;
	}

	bool result = false;
	if(canWin and canLose)
		result = true;
	else if(canWin and k % 2 == 1)
		result = true;
	cout << (result ? "First" : "Second") << endl;
}
