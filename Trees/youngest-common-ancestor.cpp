#include <vector>
using namespace std;

class AncestralTree {
   public:
    char name;
    AncestralTree *ancestor;

    AncestralTree(char name) {
        this->name = name;
        this->ancestor = nullptr;
    }

    void addAsAncestor(vector<AncestralTree *> descendants);
};

int getDescendantDepth(AncestralTree *descendantOne,
                       AncestralTree *topAncestor) {
    int depth = 0;

    while (descendantOne != topAncestor) {
        depth += 1;
        descendantOne = descendantOne->ancestor;
    }

    return depth;
}

AncestralTree *backTrackAncestralTree(AncestralTree *lowerDescendant,
                                      AncestralTree *higherDescendant,
                                      int diff) {
    while (diff-- > 0) {
        lowerDescendant = lowerDescendant->ancestor;
    }

    while (lowerDescendant != higherDescendant) {
        lowerDescendant = lowerDescendant->ancestor;
        higherDescendant = higherDescendant->ancestor;
    }

    return lowerDescendant;
}

// Time: O(D) | Space: O(1)
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
    int depthOne = getDescendantDepth(descendantOne, topAncestor);
    int depthTwo = getDescendantDepth(descendantTwo, topAncestor);

    if (depthOne > depthTwo) {
        return backTrackAncestralTree(descendantOne, descendantTwo,
                                      depthOne - depthTwo);
    } else {
        return backTrackAncestralTree(descendantTwo, descendantOne,
                                      depthTwo - depthOne);
    }

    return nullptr;
}
