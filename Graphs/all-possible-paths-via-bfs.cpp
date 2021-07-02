class Solution {
   public:
    vector<vector<int>> performBFS(vector<vector<int>>& graph, int src,
                                   int dest) {
        vector<vector<int>> allPaths;
        queue<vector<int>> q;
        unordered_map<int, bool> visitedMap;
        q.push({src});

        while (!q.empty()) {
            vector<int> current = q.front();
            q.pop();

            int latest = current[current.size() - 1];
            for (int neighbour : graph[latest]) {
                vector<int> currentPath = current;
                currentPath.push_back(neighbour);
                if (neighbour == dest)
                    allPaths.push_back(currentPath);
                else
                    q.push(currentPath);
            }
        }

        return allPaths;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = graph.size() - 1;
        return performBFS(graph, src, dest);
    }
};