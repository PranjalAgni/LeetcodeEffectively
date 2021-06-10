using namespace std;

// This is an input class. Do not edit.
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

struct TreeInfo {
    int heightOfTree;
    int diameterOfTree;
};

// Time: O(N) | Space: O(H)
TreeInfo binaryTreeDiameterHelper(BinaryTree *tree) {
    if (!tree) return TreeInfo{0, 0};
    TreeInfo leftSubTree = binaryTreeDiameterHelper(tree->left);
    TreeInfo rightSubTree = binaryTreeDiameterHelper(tree->right);
    int maxHeight =
        1 + max(leftSubTree.heightOfTree, rightSubTree.heightOfTree);
    int maxDiameter =
        max(leftSubTree.diameterOfTree, rightSubTree.diameterOfTree);
    maxDiameter =
        max(maxDiameter, leftSubTree.heightOfTree + rightSubTree.heightOfTree);
    return TreeInfo{maxHeight, maxDiameter};
}

int binaryTreeDiameter(BinaryTree *tree) {
    TreeInfo treeInfo = binaryTreeDiameterHelper(tree);
    return treeInfo.diameterOfTree;
}
