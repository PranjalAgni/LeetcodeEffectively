// https://leetcode.com/problems/valid-arrangement-of-pairs/

// This problem taught me about Euler Path in graph
// https://cp-algorithms.com/graph/euler_path.html
// Time: O(V+E) | Space: O(V + E)
// V = number of vertices
// E = number of edges
class Solution {
private:
    void euler(unordered_map<int, stack<int>>& graph, vector<vector<int>>& answer, int current) {
        auto& stk = graph[current];
        while (!stk.empty()) {
            int neighbour = stk.top();
            stk.pop();
            euler(graph, answer, neighbour);
            answer.push_back({current, neighbour});
        }
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, stack<int>> graph;
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;
        
        for (vector<int>& pair: pairs) {
            graph[pair[0]].push(pair[1]);
            indegree[pair[1]] += 1;
            outdegree[pair[0]] += 1;
        }
        
        int start = -1;
        for (auto& it: graph) {
            int vertex = it.first;
            if (outdegree[vertex] - indegree[vertex] == 1) {
                start = vertex;
                break;
            } 
        }
        
        // this means we have a euler cycle
        if (start == -1) {
            start = pairs[0][0];
        }
        
        vector<vector<int>> answer;
        euler(graph, answer, start);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};