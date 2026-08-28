/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        
        unordered_map<int, Node*> mpp;

        queue<Node*> q;

        Node* startNode;

        startNode = new Node(node->val);
        mpp[node->val] = startNode;

        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            Node* newCurr = mpp[curr->val];

            for (auto &neighbor : curr->neighbors) {
                Node* newNeighbor;
                if (mpp.find(neighbor->val) == mpp.end()) {
                    newNeighbor = new Node(neighbor->val);
                    mpp[neighbor->val] = newNeighbor;
                    q.push(neighbor);
                } else {
                    newNeighbor = mpp[neighbor->val];
                }

                newCurr->neighbors.push_back(newNeighbor);
            }
        }

        return startNode;
    }
};
