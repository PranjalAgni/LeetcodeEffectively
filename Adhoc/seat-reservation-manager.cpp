// https://leetcode.com/problems/seat-reservation-manager/

class SeatManager {
public:
    list<int> unreservedList;
    SeatManager(int n) {
        unreservedList = list<int>();
        for (int seatId = 1; seatId <= n; seatId++) {
          unreservedList.push_back(seatId);
        }   
    }
    
    int reserve() {
        int seatId = unreservedList.front();
        unreservedList.pop_front();
        return seatId;
    }
    
    void unreserve(int seatNumber) {
        int firstSeatId = unreservedList.front();
        if (seatNumber < firstSeatId) {
          unreservedList.push_front(seatNumber);
        } else {
          auto itr = unreservedList.begin();
          int advance = (seatNumber - firstSeatId);
          while(advance-- > 0) {
            itr++;
          }
          
          unreservedList.insert(itr, 1, seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */


// [1,2,3,4,5,6,7]
// 123 ->4567
// 14567
// r,u,r,u,r,u,r,r,r,u,r,r,r,r
// [],[1],[],[1],[],[1],[],[],[],[1],[],[],[],[]