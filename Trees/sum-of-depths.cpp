using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

// Time: O(N) Space: O(N)
void nodeDepthsHelper(BinaryTree* root, int currDepth, int& answer) {
	if (root == NULL) return;
	currDepth += 1;
	nodeDepthsHelper(root->left, currDepth, answer);
	nodeDepthsHelper(root->right, currDepth, answer);
	answer += currDepth;
	return;
}

int nodeDepths(BinaryTree *root) {
	int ans = 0;
	nodeDepthsHelper(root->left, 0, ans);
	nodeDepthsHelper(root->right, 0, ans);
  return ans;
}
