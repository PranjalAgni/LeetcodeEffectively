#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
   public:
    vector<int> heap;

    MinHeap(vector<int> vector) { heap = buildHeap(vector); }

    vector<int> buildHeap(vector<int> &nums) {
        heap = vector<int>(nums.begin(), nums.end());
        sort(heap.begin(), heap.end());
        return heap;
    }

    void siftDown(int currentIdx, int endIdx, vector<int> &heap) {}

    void siftUp(int currentIdx, vector<int> &heap) {}

    int peek() {
        // Write your code here.
        return heap[0];
    }

    int remove() {
        int front = peek();
        heap.erase(heap.begin());
        return front;
    }

    void insert(int value) {
        heap.push_back(value);
        sort(heap.begin(), heap.end());
    }
};
