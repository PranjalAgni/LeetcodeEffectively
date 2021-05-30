#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
    int len = array.size();
    int idx = 0;
    for (; idx < len; idx++)
        if (array[idx] >= 0) break;

    int negPtr = idx - 1;
    int posPtr = idx;
    vector<int> answer(len);
    int pos = 0;

    while (negPtr >= 0 && posPtr < len) {
        if (abs(array[negPtr]) < array[posPtr]) {
            answer[pos] = array[negPtr] * array[negPtr];
            negPtr -= 1;
        } else {
            answer[pos] = array[posPtr] * array[posPtr];
            posPtr += 1;
        }
        pos += 1;
    }

    while (negPtr >= 0) {
        answer[pos] = array[negPtr] * array[negPtr];
        negPtr -= 1;
        pos += 1;
    }

    while (posPtr < len) {
        answer[pos] = array[posPtr] * array[posPtr];
        posPtr += 1;
        pos += 1;
    }

    return answer;
}
