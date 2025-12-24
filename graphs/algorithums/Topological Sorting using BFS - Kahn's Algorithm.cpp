//https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>arr(V,0);
        queue<int>q;
        vector<vector<int>>adj(V);
        for(auto  it:edges){
            adj[it[0]].push_back(it[1]);
            arr[it[1]]++;
        }
        for(int i=0;i<V;i++){
            if(arr[i]==0){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto it:adj[n]){
                arr[it]--;
                if(arr[it]==0){
                    q.push(it);
                }
            }
            res.push_back(n);
        }
        return res;
        
        // ------------------------------while doing with edges TLE----------------------------------------------------------------
        
        
        
        // for(int i=0;i<V;i++){
        //     if(arr[i]==0){
        //         q.push(i);
        //         visited[i]=true;
        //     }
        // }
        // vector<int>res;
        // while(!q.empty()){
        //     int n=q.front();
        //     q.pop();
        //     res.push_back(n);
        //     for(auto it:edges){
        //         if(n==it[0]){
        //             arr[it[1]]--;
        //             if(arr[it[1]]==0){
        //                 q.push(it[1]);
        //             }
        //         }
        //     }
        // }
        // return res;
    }
};
