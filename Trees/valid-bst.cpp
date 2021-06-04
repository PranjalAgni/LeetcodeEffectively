class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validBstHelper(BST* tree, int left, int right) {
	if (tree == NULL) return true;
	
	if (tree->value < left || tree->value >= right) return false;
	
	return validBstHelper(tree->left, left, tree->value) && validBstHelper(tree->right, tree->value, right);
}

bool validateBst(BST *tree) {
  return validBstHelper(tree, INT_MIN, INT_MAX);
}
