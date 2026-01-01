#include <bits/stdc++.h>
using namespace std;
struct tree{
    int val;
    tree* left;
    tree* right;
    tree(int x):val(x),left(nullptr),right(nullptr){}
};
tree* insert(tree* root,int n){
    if(!root){
        tree* node =new tree(n);
        return node;
    }
    if(root->val>n)root->left=insert(root->left,n);
    else           root->right=insert(root->right,n);
    return root;
}
void levelorder(tree* root,vector<vector<int>>&arr){
    queue<tree*>q;
    q.push(root);
    arr.push_back({root->val});
    while(!q.empty()){
        int n=q.size();
        vector<int>a;
        for(int i=0;i<n;i++){
            auto point=q.front();
            q.pop();
            if(point->left){
                q.push(point->left);
                a.push_back(point->left->val);
            } 
            if(point->right){
                q.push(point->right);
                a.push_back(point->right->val);
            }
        }
        if(a.size()>0)arr.push_back(a);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        tree* root=new tree(x);
        for(int i=1;i<n;i++){
            cin>>x;
            root=insert(root,x);
        }
        vector<vector<int>>arr;
        levelorder(root,arr);
        for(auto it:arr){
            cout<<it[it.size()-1]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}
