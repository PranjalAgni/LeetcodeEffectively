#include <vector>
using namespace std;

void permute(vector<int>& array, vector<vector<int>>& answer, int low,
             int high) {
    if (low == high) {
        answer.push_back(array);
    } else {
        for (int idx = low; idx <= high; idx++) {
            swap(array[low], array[idx]);
            permute(array, answer, low + 1, high);
            swap(array[low], array[idx]);
        }
    }
}
vector<vector<int>> getPermutations(vector<int> array) {
    vector<vector<int>> answer;
    permute(array, answer, 0, array.size() - 1);
    return answer;
}
