class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBstRec(BST *tree, int& target, int minDiff, int answer) {
	if (tree == NULL) return answer;
	int currVal = tree->value;
	if (currVal == target) return target;
	int currDiff = abs(target - currVal);
	if (currDiff < minDiff) {
		minDiff = currDiff;
		answer = currVal;
	}
	
	if (target > currVal) {
		tree = tree->right;
	} else {
		tree = tree->left;
	}
	 
	return findClosestValueInBstRec(tree, target, minDiff, answer);
}

int findClosestValueInBst(BST *tree, int target) {
  int minDifference = INT_MAX;
	int answer = findClosestValueInBstRec(tree, target, minDifference, -1);
  return answer;
}
