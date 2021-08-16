#include <vector>
using namespace std;

// O(N) | O(1)
vector<int> threeNumberSort(vector<int> array, vector<int> order) {
    vector<int> frequency(3, 0);

    for (int elt : array) {
        if (order[0] == elt)
            frequency[0] += 1;
        else if (order[1] == elt)
            frequency[1] += 1;
        else
            frequency[2] += 1;
    }

    int N = array.size();
    for (int idx = 0; idx < N; idx++) {
        int pos = 0;
        if (frequency[0] > 0) {
            array[idx] = order[0];
            pos = 0;
        } else if (frequency[1] > 0) {
            array[idx] = order[1];
            pos = 1;
        } else {
            array[idx] = order[2];
            pos = 2;
        }

        frequency[pos] -= 1;
    }

    return array;
}
