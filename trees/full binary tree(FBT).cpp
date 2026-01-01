#include <bits/stdc++.h>
using namespace std;
struct tree{
    int val;
    tree* left;
    tree*  right;
    tree(int x):val(x),left(nullptr),right(nullptr){}
};
bool FBT(tree* root){
    if(!root)       return true;
    if(!root->left && !root->right)     return true;
    if(root->left && root->right)
    return FBT(root->left)&& FBT(root->right);
    return false;
}
tree* insert(tree* root,int x){
    if(!root){
        tree* node=new tree(x);
        return node;
    }
    if(root->val>x){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
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
        tree* t1=new  tree(x);
        for(int i=1;i<n;i++){
            cin>>x;
            t1=insert(t1,x);
        }
        if(FBT(t1)){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    } 
    return 0;
}
