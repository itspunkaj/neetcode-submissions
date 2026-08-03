class Solution {
public:
    int findParent(int node, vector<int>&parent) {
        if(parent[node] == node) return node;
        else return parent[node] = findParent(parent[node],parent);
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<int> size(n), parent(n);

        for(int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            int ulp_u = findParent(u,parent);
            int ulp_v = findParent(v,parent);
            if(size[u] > size[v]) {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            } else {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }

        set<int> par;

        for(int i = 0 ;i < n; i++) {
            int ulp = findParent(i,parent);
            par.insert(ulp);
        }

        return par.size();
    }
};
