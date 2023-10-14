// https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    unordered_map<int, int> hashMap;
  
    int getElement(MountainArray &mountainArr, int eltIdx) {
      if (hashMap.find(eltIdx) != hashMap.end()) {
        return hashMap[eltIdx];
      }
      
      int val =  mountainArr.get(eltIdx);
      hashMap[eltIdx] = val;
      return val;
    }
    int getPivotIdx(MountainArray &mountainArr, int N) {
      int low = 0;
      int high = N - 1;
      
      while (low < high) {
        int mid = low + (high - low) / 2;
        int current = getElement(mountainArr, mid);
        if (mid + 1 < N) {
          int nextElt = getElement(mountainArr, mid + 1);
          if (nextElt > current) {
            low = mid + 1;
            continue;
          }
        }
        
        if (mid - 1 >= 0) {
          int prevElt = getElement(mountainArr, mid - 1);
          if (prevElt > current) {
            high = mid - 1;
            continue;
          }
        }
        
        return mid;
      }
      
      return low;
    }
public:
    // Time: O(3logN) | Space: O(N)
    // N = number of elements
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int N = mountainArr.length();
        hashMap = unordered_map<int, int>();
        int pivotIdx = getPivotIdx(mountainArr, N);
        if (getElement(mountainArr, pivotIdx) == target) return pivotIdx;
      
        // search in left range
        int low = 0;
        int high = pivotIdx;
        while (low <= high) {
          int mid = low + (high - low) / 2;
          int current = getElement(mountainArr, mid);
      
          if (current == target) return mid;
          else if (current < target) {
            low = mid + 1;
          } else {
            high = mid - 1;
          }
        }
      
        if (low >= 0 && low < N) {
          if (getElement(mountainArr, low) == target) return low;
        }
      
        // search in right range
        low = pivotIdx + 1;
        high = N;
        while (low <= high) {
          int mid = low + (high - low) / 2;
          int current = getElement(mountainArr, mid);
          if (current == target) return mid;
          else if (current < target) {
            high = mid - 1;
          } else {
            low = mid + 1;
          }
        }
        
        if (low >= 0 && low < N) {
          if (getElement(mountainArr, low) == target) return low;
        }
        
        return -1;
    }
};