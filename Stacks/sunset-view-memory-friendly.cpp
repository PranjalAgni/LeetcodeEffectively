using namespace std;

// Time: O(N) | Space: O(N)
// This is a more memory friendly solution
// Keeps track of maximum running height till the ith poisition
vector<int> sunsetViews(vector<int> buildings, string direction) {
    int N = buildings.size();
    if (direction == "EAST") reverse(buildings.begin(), buildings.end());
    vector<int> buildingIndexes;
    int startIdx = 0;
    int maxHeight = 0;

    while (startIdx < N) {
        if (buildings[startIdx] > maxHeight) {
            maxHeight = buildings[startIdx];
            int correctIdx =
                (direction == "EAST") ? N - 1 - startIdx : startIdx;
            buildingIndexes.push_back(correctIdx);
        }
        startIdx += 1;
    }

    if (direction == "EAST")
        reverse(buildingIndexes.begin(), buildingIndexes.end());

    return buildingIndexes;
}
