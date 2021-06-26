#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
   public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    // Time: O(V + E) | Space: O(V)
    vector<string> breadthFirstSearch(vector<string> *array) {
        queue<Node *> q;
        q.push(this);
        while (!q.empty()) {
            int N = q.size();

            while (N-- > 0) {
                Node *curr = q.front();
                q.pop();
                array->push_back(curr->name);
                int len = curr->children.size();
                for (int idx = 0; idx < len; idx++) {
                    q.push(curr->children[idx]);
                }
            }
        }

        return *array;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
