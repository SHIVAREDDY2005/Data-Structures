class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {w
        vector<int>visited(V,false);
        vector<vector<int>>adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            int s=i;
            if(visited[s])continue;
            visited[s]=true;
            queue<pair<int,int>>q;
            q.push({i,-1});
            while(!q.empty()){
                auto p=q.front();
                int cur=p.first;
                int pa=p.second;
                q.pop();
                for(int i:adj[cur]){
                    if(!visited[i]){
                        q.push({i,cur});
                        visited[i]=true;
                    }
                    else if(pa!=i){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
