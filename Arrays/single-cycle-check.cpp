using namespace std;

int getNextPos(int currPos, vector<int>& array) {
    int N = array.size();
    int val = array[currPos] % N;
    int nextPos = currPos + val;
    if (nextPos < 0) nextPos += N;
    nextPos = abs(nextPos) % N;
    return nextPos;
}

// Time: O(N) | Space: O(1)
bool hasSingleCycle(vector<int> array) {
    int N = array.size();

    int nodesVisited = 0;
    int pos = 0;

    while (nodesVisited < N) {
        if (nodesVisited > 0 && pos == 0) return false;
        pos = getNextPos(pos, array);
        nodesVisited += 1;
    }

    return pos == 0;
}
