using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
   public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

struct TreeInfo {
    int height;
    bool isBalanced;
};

// Time: O(N) | Space: O(N)
TreeInfo heightBalancedBinaryTreeHelper(BinaryTree *tree) {
    if (!tree) return {0, true};
    TreeInfo leftSubtree = heightBalancedBinaryTreeHelper(tree->left);
    TreeInfo rightSubtree = heightBalancedBinaryTreeHelper(tree->right);

    int height = 1 + max(leftSubtree.height, rightSubtree.height);
    bool isBalanced = leftSubtree.isBalanced && rightSubtree.isBalanced &&
                      abs(leftSubtree.height - rightSubtree.height) <= 1;
    return TreeInfo{height, isBalanced};
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
    TreeInfo treeInfo = heightBalancedBinaryTreeHelper(tree);
    return treeInfo.isBalanced;
}
