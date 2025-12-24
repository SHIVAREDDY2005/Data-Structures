class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pp) {
        vector<vector<int>>pre(n);
        vector<int>arr(n,0);
        for(auto it:pp){
            pre[it[0]].push_back(it[1]);
            arr[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
            q.push(i);
        }
        int c=0;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            c++;
            for(int i:pre[n]){
                arr[i]--;
                if(arr[i]==0){
                    q.push(i);
                }
            }
        }
        return(c==n)?true:false;
    }
};
