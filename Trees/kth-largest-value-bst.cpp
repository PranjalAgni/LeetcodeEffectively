using namespace std;

// This is an input class. Do not edit.
class BST {
   public:
    int value;
    BST *left = nullptr;
    BST *right = nullptr;

    BST(int value) { this->value = value; }
};

struct TreeInfo {
    int numberOfNodesVisited;
    int latestVisitedNodeValue;
};

void reverseInorder(BST *node, int k, TreeInfo &treeInfo) {
    if (!node || treeInfo.numberOfNodesVisited >= k) return;
    reverseInorder(node->right, k, treeInfo);
    if (treeInfo.numberOfNodesVisited < k) {
        treeInfo.numberOfNodesVisited += 1;
        treeInfo.latestVisitedNodeValue = node->value;
        reverseInorder(node->left, k, treeInfo);
    }
}

int findKthLargestValueInBst(BST *tree, int k) {
    TreeInfo treeInfo = TreeInfo{0, -1};
    reverseInorder(tree, k, treeInfo);
    return treeInfo.latestVisitedNodeValue;
}
