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

void inorderTraversal(BinaryTree *tree, vector<BinaryTree *> &inorder) {
    if (!tree) return;
    inorderTraversal(tree->left, inorder);
    inorder.push_back(tree);
    inorderTraversal(tree->right, inorder);
}

// Time: O(N) | Space: O(1)
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
    vector<BinaryTree *> inorder;
    inorderTraversal(tree, inorder);

    for (int idx = 0; idx < inorder.size() - 1; idx++) {
        if (inorder[idx] == node) return inorder[idx + 1];
    }

    return nullptr;
}
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

void inorderTraversal(BinaryTree *tree, vector<BinaryTree *> &inorder) {
    if (!tree) return;
    inorderTraversal(tree->left, inorder);
    inorder.push_back(tree);
    inorderTraversal(tree->right, inorder);
}

// Time: O(N) | Space: O(1)
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
    vector<BinaryTree *> inorder;
    inorderTraversal(tree, inorder);

    for (int idx = 0; idx < inorder.size() - 1; idx++) {
        if (inorder[idx] == node) return inorder[idx + 1];
    }

    return nullptr;
}
