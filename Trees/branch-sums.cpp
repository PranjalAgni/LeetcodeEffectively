using namespace std;

// This is the class of the input root. Do not edit it.
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

void branchSumsHelper(BinaryTree* root, int currSum, vector<int>& answer) {
	if (root == NULL) return;
	
	if (root->left == NULL && root->right == NULL) {
		answer.push_back(currSum + root->value);
	}
	
	branchSumsHelper(root->left, currSum + root->value, answer);
	branchSumsHelper(root->right, currSum + root->value, answer);	
}

vector<int> branchSums(BinaryTree *root) {
	vector<int> answer;
	branchSumsHelper(root, 0, answer);
  return answer;
}
