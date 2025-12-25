class Solution {
public:
    void dim(int idx,int &r,int &c,int n){
        r=idx/n;
        c=idx%n;
        if(r%2!=0)
        c=n-1-c;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        reverse(board.begin(),board.end());
        queue<pair<int,int>>q;
        vector<bool>visit(n*n+1,false);
        q.push({1,0});
        visit[1]=true;
        while(!q.empty()){
            auto point=q.front();
            int cur=point.first;
            int moves=point.second;
            q.pop();
            for(int i=1;i<=6;i++){
                if(cur+i>n*n)continue;
                int r,c,res;
                dim(cur+i-1,r,c,n);
                if(board[r][c]==-1)         res=cur+i;
                else                        res=board[r][c];
                if(res==n*n)                return moves+1;
                if(!visit[res]){
                    q.push({res,moves+1});
                    visit[res]=true;
                }
            }
        }
        return -1;
    }
};
