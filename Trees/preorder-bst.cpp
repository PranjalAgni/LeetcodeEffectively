using namespace std;

// This is an input class. Do not edit.
class BST {
   public:
    int value;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) { this->value = value; }
};

BST* reconstructBst(vector<int> preOrderTraversalValues) {
    int nodes = preOrderTraversalValues.size();
    if (nodes == 0) return nullptr;

    int rootVal = preOrderTraversalValues[0];
    int rightTreeIdx = nodes;

    for (int idx = 1; idx < nodes; idx++) {
        if (preOrderTraversalValues[idx] >= rootVal) {
            rightTreeIdx = idx;
            break;
        }
    }

    BST* leftTree = reconstructBst(
        vector<int>(preOrderTraversalValues.begin() + 1,
                    preOrderTraversalValues.begin() + rightTreeIdx));

    BST* rightTree = reconstructBst(
        vector<int>(preOrderTraversalValues.begin() + rightTreeIdx,
                    preOrderTraversalValues.end()));

    BST* rootNode = new BST(rootVal);
    rootNode->left = leftTree;
    rootNode->right = rightTree;
    return rootNode;
}
