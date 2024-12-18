// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

// Time: O(N*N) | Space: O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        vector<int> answer;
        for (int idx = 0; idx < N; idx++) {
            int start = idx + 1;
            int discount = 0;
            while (start < N) {
                if (prices[start] <= prices[idx]) {
                    discount = prices[start];
                    break;
                }
                start += 1;
            }
            
            answer.push_back(prices[idx] - discount);
        }
        
        return answer;
        
    }
};