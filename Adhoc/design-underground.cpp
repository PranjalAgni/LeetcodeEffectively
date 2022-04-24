// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
public:
    // Time: O(N) | Space: O(N)
    unordered_map<int, pair<string, int>> travellerIdVsStationMap;
    unordered_map<string, pair<double, int>> stationVsDistanceMap;
    UndergroundSystem() {
      travellerIdVsStationMap = unordered_map<int, pair<string, int>>();
      stationVsDistanceMap = unordered_map<string, pair<double, int>>();
    }
    
    // Time: O(1) | Space: O(1)
    void checkIn(int id, string stationName, int t) {
        travellerIdVsStationMap[id] = make_pair(stationName, t);
    }
    
    // Time: O(1) | Space: O(1)
    void checkOut(int id, string stationName, int t) {
        pair<string, int> currentTraveller = travellerIdVsStationMap[id];
      
        string checkInStation = currentTraveller.first;
        travellerIdVsStationMap.erase(id);
        string stationKey = checkInStation + "-" + stationName;
        stationVsDistanceMap[stationKey].first += t - currentTraveller.second;
      
        stationVsDistanceMap[stationKey].second += 1;
    }

    // Time: O(1) | Space: O(1)
    double getAverageTime(string startStation, string endStation) {
      string stationKey = startStation + "-" + endStation;
      return stationVsDistanceMap[stationKey].first / stationVsDistanceMap[stationKey].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */