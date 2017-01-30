#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct node {
	struct node *left;
	struct node *right;
	char val;
} node;

ifstream fin("heritage.in");
ofstream fout("heritage.out");

string inorder;
string preorder;
node *rootNode;

node *makeTree(string inorder, string preorder) {
	node *currNode = (node *) malloc(sizeof(node));
	currNode -> val = preorder[0];

	//cout << preorder[0] << endl;

	int indexFst;
	for(int i = 0; i < inorder.size(); i++) {
		if(inorder[i] == currNode -> val)
			indexFst = i;
	}

	string inFirst = inorder.substr(0, indexFst);

	if(inFirst.size() > 0) {
		currNode -> left = makeTree(inFirst, preorder.substr(1, indexFst));
	}

	if(indexFst + 1 < inorder.size()) {
		string inSecond = inorder.substr(indexFst + 1);
		if(inSecond.size() > 0) {
			currNode -> right = makeTree(inSecond, preorder.substr(indexFst + 1));
		}
	}

	return currNode;
}

void printPostOrder(node *currNode) {
	if(currNode -> left != NULL)
		printPostOrder(currNode -> left);
	if(currNode ->right != NULL)
		printPostOrder(currNode -> right);
	fout << currNode -> val;
}

int main() {
	fin >> inorder >> preorder;
	rootNode = makeTree(inorder, preorder);

	printPostOrder(rootNode);	
	fout << endl;

	return 0;
}
