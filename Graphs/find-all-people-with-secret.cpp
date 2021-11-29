// https://leetcode.com/problems/find-all-people-with-secret/

class Solution {
   public:
    void addToSecretMap(int person,
                        unordered_map<int, int>& personWhoKnowSecret,
                        vector<int>& answer) {
        if (personWhoKnowSecret[person] == 0) answer.push_back(person);
        personWhoKnowSecret[person] = 1;
    }

    bool doesPersonKnowSecret(int& person,
                              unordered_map<int, int>& personWhoKnowSecret) {
        return personWhoKnowSecret[person] != 0;
    }

    unordered_map<int, vector<pair<int, int>>> buildGraph(
        vector<vector<int>>& meetings) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for (vector<int>& meeting : meetings) {
            graph[meeting[0]].push_back({meeting[1], meeting[2]});
            graph[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        return graph;
    }

    // Time: O(NlogN) | Space: O(N)
    // priority queue inserting N persons, each take logN time

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        vector<int> answer;
        unordered_map<int, vector<pair<int, int>>> graph = buildGraph(meetings);
        unordered_map<int, int> personWhoKnowSecret;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pqueue;

        // add people who know the secret
        addToSecretMap(0, personWhoKnowSecret, answer);
        addToSecretMap(firstPerson, personWhoKnowSecret, answer);
        pqueue.push({0, 0});
        pqueue.push({0, firstPerson});
        vector<bool> visited(n, false);

        while (!pqueue.empty()) {
            pair<int, int> attendeeWithTime = pqueue.top();
            pqueue.pop();
            int time = attendeeWithTime.first;
            int attendee = attendeeWithTime.second;
            if (visited[attendee]) continue;
            visited[attendee] = true;
            if (doesPersonKnowSecret(attendee, personWhoKnowSecret))
                addToSecretMap(attendee, personWhoKnowSecret, answer);

            for (pair<int, int>& neighbour : graph[attendee]) {
                if (!visited[neighbour.first] && time <= neighbour.second) {
                    pqueue.push({neighbour.second, neighbour.first});
                    addToSecretMap(neighbour.first, personWhoKnowSecret,
                                   answer);
                }
            }
        }

        return answer;
    }
};