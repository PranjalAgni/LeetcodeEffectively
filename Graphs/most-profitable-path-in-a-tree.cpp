// https://leetcode.com/problems/most-profitable-path-in-a-tree/

class Solution {
  public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // how to solve this problem 
        // with dfs + bfs

        // we dfs to find a path when bob reaches at node 0
        // we track the time as well for bob (at what time he reaches a node)
        
        // Now we have a timed path of bob reaching at node 0

        // we can now start a bfs from node 0 for Alice to make him reach a leaf node
        // track time for alice as well
        // when they reach a node compare it with time of bob
        // if it is less: means we can give profit to alice
        // if it is equal: means we can divide the profit
        // if it is more: nothing :(


        // we can track the maxProfit and that will be the answer   
    }
};