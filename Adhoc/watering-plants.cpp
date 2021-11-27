// https://leetcode.com/contest/weekly-contest-268/problems/watering-plants/

class Solution {
   public:
    // Time: O(N) | Space: O(1)
    int wateringPlants(vector<int>& plants, int capacity) {
        int numPlants = plants.size();
        int currentCapacity = capacity;
        int steps = 0;
        for (int idx = 0; idx < numPlants; idx++) {
            currentCapacity -= plants[idx];
            // checks if next plant is there
            bool isNextPossible = (idx + 1) < numPlants;
            if (isNextPossible && currentCapacity < plants[idx + 1]) {
                // refill tank
                currentCapacity = capacity;
                // going back to river + coming from river to nextPlant
                steps += (idx + 1) + (idx + 2);
            } else
                steps += 1;
        }

        return steps;
    }
};
