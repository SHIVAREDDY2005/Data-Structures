// https://www.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1
class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        vector<int>arr(n+1);
        arr[0]=0;
        arr[1]=1;
        arr[2]=2;
        if(n<=2)return n;
        for(int i=3;i<=n;i++){
            arr[i]=(arr[i-1]+arr[i-2]);
        }
        return arr[n];
    }
};
