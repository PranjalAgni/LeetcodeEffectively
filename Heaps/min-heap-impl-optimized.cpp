#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
   public:
    vector<int> heap;

    MinHeap(vector<int> vector) { heap = buildHeap(vector); }

    // O(n) | O(1)
    vector<int> buildHeap(vector<int> &vector) {
        int N = vector.size() - 1;
        int firstParent = (N - 1) / 2;
        for (int idx = firstParent; idx >= 0; idx--) {
            siftDown(idx, N, vector);
        }

        return vector;
    }

    // O(logN) | O(1)
    void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
        int childOne = currentIdx * 2 + 1;

        while (childOne <= endIdx) {
            int childTwo = currentIdx * 2 + 2;
            if (childTwo > endIdx) childTwo = -1;
            int idxToSwap = childOne;
            if (childTwo != -1 && heap[childTwo] < heap[childOne])
                idxToSwap = childTwo;

            if (heap[idxToSwap] >= heap[currentIdx]) break;
            swap(heap[idxToSwap], heap[currentIdx]);
            currentIdx = idxToSwap;
            childOne = currentIdx * 2 + 1;
        }
    }

    // O(logN) | O(1)
    void siftUp(int currentIdx, vector<int> &heap) {
        int parent = (currentIdx - 1) / 2;
        while (currentIdx >= 0) {
            if (heap[currentIdx] >= heap[parent]) break;
            swap(heap[currentIdx], heap[parent]);
            currentIdx = parent;
            parent = (parent - 1) / 2;
        }
    }

    // O(1) | O(1)
    int peek() { return heap[0]; }

    // O(logN) | O(1)
    int remove() {
        int N = heap.size() - 1;
        swap(heap[0], heap[N]);
        int val = heap.back();
        heap.pop_back();
        siftDown(0, N, heap);
        return val;
    }

    // O(logN) | O(1)
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1, heap);
    }
};
