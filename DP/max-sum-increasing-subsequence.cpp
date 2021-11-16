#include <vector>
using namespace std;

struct SubsequenceNode {
    vector<int> sequence;
    int value;
};

// Time: O(N*N) | Space: O(N)
vector<vector<int> > maxSumIncreasingSubsequence(vector<int> array) {
    int N = array.size();
    vector<SubsequenceNode> subsequence(N);

    for (int idx = 0; idx < N; idx++) {
        int current = array[idx];
        SubsequenceNode newNode = {{current}, current};
        subsequence[idx] = newNode;

        for (int jdx = 0; jdx < idx; jdx++) {
            if (current > array[jdx]) {
                newNode = subsequence[idx];
                SubsequenceNode node = subsequence[jdx];
                int newTotal = node.value + current;
                // if newTotal formed is greater than the total we have seen so
                // far then its the max answer so far for idx
                if (newTotal > newNode.value) {
                    vector<int> sequence = node.sequence;
                    sequence.push_back(current);
                    newNode = {sequence, newTotal};
                    subsequence[idx] = newNode;
                }
            }
        }
    }

    int maxIdx = 0;
    for (int idx = 1; idx < N; idx++) {
        SubsequenceNode maxSoFar = subsequence[maxIdx];
        SubsequenceNode current = subsequence[idx];
        if (current.value > maxSoFar.value) maxIdx = idx;
    }

    SubsequenceNode answer = subsequence[maxIdx];
    return {{answer.value}, answer.sequence};
}
