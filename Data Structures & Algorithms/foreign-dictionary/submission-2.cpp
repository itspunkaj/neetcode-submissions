class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        for(int i = 0; i < words.size(); i++) {
            for(auto c : words[i]) {
                adj[c];
                indegree[c];
            }
        }
        for(int i = 0; i < words.size()-1; i++) {
            int len1 = words[i].size();
            int len2 = words[i+1].size();

            if(len1 > len2) {

                if(words[i].substr(0,len2) == words[i+1].substr(0,len2)) return "";
            }

            for(int j = 0; j < min(len1, len2); j++) {
                if(words[i][j] != words[i+1][j]) {
                    adj[words[i][j]].push_back(words[i+1][j]);
                    indegree[words[i+1][j]]++;
                    break;
                }

            }
        }

        queue<char> q;

        for(auto it : adj) {
            if(indegree[it.first] == 0) q.push(it.first);
        }

        string ans = "";

        while(!q.empty()) {
            char node = q.front();

            q.pop();
            ans += node;
            for(auto adjNode : adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        if(ans.size() == adj.size()) return ans;
        return "";


    }
};
