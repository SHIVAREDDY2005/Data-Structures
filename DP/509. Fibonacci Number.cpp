class Solution {
public:
    int solve(vector<int>&arr,int n){
        if(n<=1)return n;
        if(arr[n]!=-1){
            return arr[n];
        }
        arr[n]=solve(arr,n-1)+solve(arr,n-2);
        return arr[n];
    }
    int fib(int n) {
        vector<int>arr(n+1,-1);
        return solve(arr,n); 
    }
};
