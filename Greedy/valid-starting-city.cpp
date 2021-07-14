#include <vector>
using namespace std;

// Time: O(N) | Space: O(1)
int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
    int minFuelSoFar = 0;
    int currentFuel = 0;
    int startCity = 0;
    int N = distances.size();
    for (int idx = 0; idx < N; idx++) {
        int maxMilesCanTravel = currentFuel + fuel[idx] * mpg;
        currentFuel = maxMilesCanTravel - distances[idx];
        if (currentFuel < minFuelSoFar) {
            minFuelSoFar = currentFuel;
            startCity = idx + 1;
        }
    }

    return startCity % N;
}
