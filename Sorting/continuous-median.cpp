#include <bits/stdc++.h>
using namespace std;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler {
   public:
    double median;
    set<int> numsSet;

    ContinuousMedianHandler() { numsSet = set<int>(); }

    // Time: O(logN) | Space: O(1)
    void insert(int number) { numsSet.insert(number); }

    // Time: O(N) | Space: O(N)
    double getMedian() {
        int N = numsSet.size();
        bool isEven = (N % 2 == 0);
        int mid = isEven ? (N / 2) - 1 : (N / 2);
        int pos = 0;
        bool isNext = false;
        for (auto const& elt : numsSet) {
            if (isNext) {
                median += elt;
                break;
            }
            if (pos == mid) {
                median = elt;
                if (isEven)
                    isNext = true;
                else
                    break;
            }
            pos += 1;
        }

        if (isEven) median = median / 2;
        return median;
    }
};
