#include <vector>
using namespace std;

class BinaryTree {
   public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};

// Time: O(N * N) | Space: O(H)
void invertBinaryTree(BinaryTree *tree) {
    if (!tree) return;
    // nothing to swap if leaf node
    if (!tree->left && !tree->right) return;
    BinaryTree *temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;
    invertBinaryTree(tree->left);
    invertBinaryTree(tree->right);
}
