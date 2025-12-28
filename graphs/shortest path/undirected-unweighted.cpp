// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
class Solution {
  public:
    vector<int> shortestPath(int v, vector<vector<int>> &edges, int src) {
        // code here
        vector<int>dis(v,-1);
        dis[src]=0;
        queue<int>q;
        q.push(src);
        vector<vector<int>>adj(v);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int it:adj[cur]){
                if(dis[it]==-1){
                    dis[it]=dis[cur]+1;
                    q.push(it);
                }
            }
        }
        return dis;
    }
};
