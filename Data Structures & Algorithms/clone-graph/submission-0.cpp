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

        if(!node) return nullptr;

        unordered_map<Node*,Node*> mp;

        mp[node] =  new Node(node->val);


        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* tempN = q.front();

            q.pop();

            for(Node* nei:tempN->neighbors) {
                if(mp.find(nei) == mp.end()) {
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }

                mp[tempN]->neighbors.push_back(mp[nei]);
            }
        }

        return mp[node];
    }
};
