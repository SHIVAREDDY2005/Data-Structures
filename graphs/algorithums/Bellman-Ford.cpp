//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dis(V,1e8);
        dis[src]=0;
        for(int i=0;i<V;i++){
            for(auto  it:edges){
                long long v=it[0];
                long long u=it[1];
                long long wt=it[2];
                if(dis[v]!=1e8 && dis[v]+wt<dis[u]){
                    if(i==V-1)return {-1};
                    dis[u]=dis[v]+wt;
                }
            }
        }
        return dis;
    }
};
