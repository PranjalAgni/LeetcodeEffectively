using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int arrPtr = 0;
    int seqPtr = 0;
    int len = array.size();
    int seqLen = sequence.size();

    while (arrPtr < len && seqPtr < seqLen) {
        if (array[arrPtr] == sequence[seqPtr]) {
            seqPtr += 1;
        }
        arrPtr += 1;
    }

    return seqPtr == seqLen;
}
