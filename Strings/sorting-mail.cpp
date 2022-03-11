// https://binarysearch.com/problems/Sorting-Mail

// Nice BFS based question, to sort the mails
// Time: O(V) | Space: O(V)
// V = number of nodes = max(mailboxes.length) * max(mailboxes[i].length)
vector<string> solve(vector<vector<string>>& mailboxes) {
    vector<string> answer;
    int rows = mailboxes.size();
    queue<pair<int, int>> queue;
    for (int row = 0; row < rows; row++) {
        queue.push({row, 0});
    }

    while (!queue.empty()) {
        int row = queue.front().first;
        int pos = queue.front().second; 
        queue.pop();
        string type = mailboxes[row][pos];
        if (type != "junk") answer.push_back(type);
        if (pos + 1 < mailboxes[row].size()) {
            queue.push({row, pos + 1});
        }
    }

    return answer;
}