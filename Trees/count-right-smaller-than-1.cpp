// https://www.geeksforgeeks.org/count-smaller-elements-on-right-side/
using namespace std;

class SpecialBST {
   public:
    int value;
    int idx;
    int numSmallerAtInsertTime;
    int leftSubtreeSize;
    SpecialBST* left;
    SpecialBST* right;

    SpecialBST(int value, int idx, int numSmallerAtInsertTime) {
        this->value = value;
        this->idx = idx;
        this->numSmallerAtInsertTime = numSmallerAtInsertTime;
        this->leftSubtreeSize = 0;
        this->left = NULL;
        this->right = NULL;
    }

    void insert(int value, int idx, int numSmallerAtInsertTime) {
        if (value < this->value) {
            this->leftSubtreeSize += 1;
            if (this->left == NULL) {
                this->left = new SpecialBST(value, idx, numSmallerAtInsertTime);
            } else {
                this->left->insert(value, idx, numSmallerAtInsertTime);
            }
        } else {
            numSmallerAtInsertTime += this->leftSubtreeSize;
            if (value > this->value) numSmallerAtInsertTime += 1;
            if (this->right == NULL) {
                this->right =
                    new SpecialBST(value, idx, numSmallerAtInsertTime);
            } else {
                this->right->insert(value, idx, numSmallerAtInsertTime);
            }
        }
    }
};

void getRightSmallerCount(SpecialBST* specialBST,
                          vector<int>& rightSmallerCount) {
    if (specialBST == NULL) return;
    rightSmallerCount[specialBST->idx] = specialBST->numSmallerAtInsertTime;
    getRightSmallerCount(specialBST->left, rightSmallerCount);
    getRightSmallerCount(specialBST->right, rightSmallerCount);
}

// Average case: when BST is balanced
// Time: O(Nlog(N)) | Space: O(N)
// N = length of the array
// Worst case: when BST is skewed, created like a linkedlist
// Time: O(N^2) | Space: O(N)
vector<int> rightSmallerThan(vector<int> array) {
    int N = array.size();
    if (N == 0) return {};
    SpecialBST* specialBST = new SpecialBST(array[N - 1], N - 1, 0);
    vector<int> rightSmallerCount(N);

    for (int idx = N - 2; idx >= 0; idx--) {
        specialBST->insert(array[idx], idx, 0);
    }

    getRightSmallerCount(specialBST, rightSmallerCount);
    return rightSmallerCount;
}
