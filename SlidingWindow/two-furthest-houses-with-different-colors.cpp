// https://leetcode.com/problems/two-furthest-houses-with-different-colors/?envType=daily-question&envId=2026-04-20

/**
 * 
 *  Find the last house with different color of the fisrt house.
    Find the first house with different color of the last house.
    Return the max distance of these two options.
 */
// Time: O(N) | Space: O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int N = colors.size();
        int left = 0;
        int right = N - 1;
        while (colors[0] == colors[right]) {
            right -= 1;
        }

        while (colors[N - 1] == colors[left]) {
            left += 1;
        }

        return max(N - 1 - left, right);
    }   
};