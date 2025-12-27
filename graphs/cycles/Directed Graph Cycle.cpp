class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>degree(V,0);
        queue<int>q;
        for(auto  it:edges){
            adj[it[0]].push_back(it[1]);
            degree[it[1]]++;
        }
        for(int i=0;i<V;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int c=q.front();
            q.pop();
            for(int i:adj[c]){
                degree[i]--;
                if(degree[i]==0){
                    q.push(i);
                }
            }
        }
        for(int i:degree){
            if(i!=0)return true;
        }
        return false;
    }
    
};
