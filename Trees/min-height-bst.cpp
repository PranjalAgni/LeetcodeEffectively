using namespace std;

class BST {
   public:
    int value;
    BST* left;
    BST* right;

    BST(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value) {
        if (value < this->value) {
            if (left == nullptr) {
                left = new BST(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == nullptr) {
                right = new BST(value);
            } else {
                right->insert(value);
            }
        }
    }
};

BST* minHeightHelper(vector<int>& array, BST* tree, int low, int high) {
    if (high < low) return nullptr;
    int mid = low + (high - low) / 2;
    int value = array[mid];

    if (tree == nullptr) {
        tree = new BST(value);
    } else {
        tree->insert(value);
    }

    minHeightHelper(array, tree, low, mid - 1);
    minHeightHelper(array, tree, mid + 1, high);
    return tree;
}

BST* minHeightBst(vector<int> array) {
    int low = 0;
    int high = array.size() - 1;
    return minHeightHelper(array, nullptr, low, high);
}
