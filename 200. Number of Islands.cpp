class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j,int n,int m){
        if((i<0 || i>=n) || (j<0 ||j>=m)|| grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),c=0;
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    c++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return c;
    }
};
