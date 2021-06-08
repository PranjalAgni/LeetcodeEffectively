#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
   public:
    int value;
    BST *left;
    BST *right;

    BST(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST &insert(int val) {
        if (val < value) {
            if (left == nullptr) {
                BST *newNode = new BST(val);
                left = newNode;
            } else {
                left->insert(val);
            }
        } else {
            if (right == nullptr) {
                BST *newNode = new BST(val);
                right = newNode;
            } else {
                right->insert(val);
            }
        }

        return *this;
    }

    bool contains(int val) {
        if (value == val) return true;
        if (left && val < value)
            return left->contains(val);
        else if (right && val > value)
            return right->contains(val);
        else
            return false;
    }

    BST &remove(int val, BST *parent = nullptr) {
        if (val < value) {
            if (left != nullptr) left->remove(val, this);
        } else if (val > value) {
            if (right != nullptr) right->remove(val, this);
        } else {
            if (left != nullptr && right != nullptr) {
                value = right->getMinValue();
                right->remove(value, this);
            } else if (parent == nullptr) {
                if (left != nullptr) {
                    value = left->value;
                    right = left->right;
                    left = left->left;
                } else if (right != nullptr) {
                    value = right->value;
                    left = right->left;
                    right = right->right;
                }
            } else if (parent->left == this) {
                parent->left = left != nullptr ? left : right;
            } else if (parent->right == this) {
                parent->right = left != nullptr ? left : right;
            }
        }

        return *this;
    }

    int getMinValue() {
        if (left == nullptr)
            return value;
        else
            return left->getMinValue();
    }
};
