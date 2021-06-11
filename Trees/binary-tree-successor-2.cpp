using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
   public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;
    BinaryTree *parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

BinaryTree *findLeftMostNode(BinaryTree *tree) {
    if (!tree) return tree;
    while (tree->left != NULL) {
        tree = tree->left;
    }

    return tree;
}

BinaryTree *getRightMostParent(BinaryTree *tree) {
    BinaryTree *curr = tree;
    while (curr->parent && curr->parent->right == curr) {
        curr = curr->parent;
    }

    return curr->parent;
}

// Time: O(H) | Space: O(1)
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
    if (node->right) return findLeftMostNode(node->right);
    return getRightMostParent(node);
}
