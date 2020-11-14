// Tree를 만든 후 후위 순회하는 방법

#include<iostream>

using namespace std;

struct NODE {
	int key;
	NODE* left;
	NODE* right;

	NODE(int val) : key(val), left(NULL), right(NULL) {}
	void setLeft(NODE* newNode) {
		left = newNode;
	}
	void setRight(NODE* newNode) {
		right = newNode;
	}

};

NODE* insertNode(NODE* root, NODE* newNode) {
	if (root == NULL) {
		root = newNode;
	}
	else {
		if (root->key > newNode->key) {
			root->setLeft(insertNode(root->left, newNode));
		}
		else {
			root->setRight(insertNode(root->right, newNode));
		}
	}

	return root;
}

void print_post(NODE* cur) {
	if (cur == NULL) return;

	print_post(cur->left);
	print_post(cur->right);
	cout << cur->key << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	NODE* tree = NULL;
	int inp;

	while (cin >> inp) {
		tree = insertNode(tree, new NODE(inp));
	}

	print_post(tree);

	return 0;
}
