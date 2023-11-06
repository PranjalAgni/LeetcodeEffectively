// https://leetcode.com/problems/seat-reservation-manager/

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        pq = priority_queue<int, vector<int>, greater<int>>();
        for (int seatId = 1; seatId <= n; seatId++) {
          pq.push(seatId);
        }   
    }
    
    // Time: O(logN)
    // have to heapify again after removing top
    int reserve() {
        int seatId = pq.top();
        pq.pop();
        return seatId;
    }
    
    // Time: O(logN) insertion
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */


 // Optimizing further:

 class SeatManagerOptimized {
public:
    priority_queue<int, vector<int>, greater<int>> unreservedList;
    int lastSeat;
    SeatManager(int n) {
        unreservedList = priority_queue<int, vector<int>, greater<int>>();
      lastSeat = 0;
    }
    
    int reserve() {
        if (unreservedList.empty()) {
          lastSeat += 1;
          return lastSeat;
        }
      
        int seatId = unreservedList.top();
        unreservedList.pop();
        return seatId;
      
    }
    
    void unreserve(int seatNumber) {
        if (lastSeat == seatNumber) {
          lastSeat -= 1;
        } else {
          unreservedList.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

