#include <bits/stdc++.h>
using namespace std;
struct tree{
    int val;
    tree* left;
    tree* right;
    tree(int x):val(x),right(nullptr),left(nullptr){}
};
tree* insert(tree* root,int n){
    if(!root){
        tree* node =new tree(n);
        return node;
    }
    if(root->val>n) root->left=insert(root->left,n);
    else            root->right=insert(root->right,n);
    return root;
}
bool search(tree* root,int n){
    if(!root)return false;
    if(root->val==n)return true;
    else if(root->val>n){
        return search(root->left,n);
    }
    else{
        return search(root->right,n);
    }
}
tree* delete_node(tree* root,int n){
    if(!root)return nullptr;
    else if(root->val>n)root->left=delete_node(root->left,n);
    else if(root->val<n)root->right=delete_node(root->right,n);
    else{
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        else if(!root->right){
            tree* temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left){
            tree* temp=root->right;
            delete root;
            return temp;
        }
        else{
            tree* temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            root->val=temp->val;
            root->right=delete_node(root->right,temp->val);
        }
    }
    return root;
} 
void preorder(tree* root){
    if(root){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
            cout<<"Case #"<<i<<":"<<endl;
        int n;
        cin>>n;
        tree* root=nullptr;
        while(n--){
            int op;
            cin>>op;
            switch(op){
                case 1:{
                    int x;
                    cin>>x;
                    root=insert(root,x);
                    break;
                }
                case 2:{
                    int x;
                    cin>>x;
                    root=delete_node(root,x);
                    break;
                }
                case 3:{
                    int x;
                    cin>>x;
                    if(search(root,x)){
                        cout<<"Yes"<<endl;
                    }
                    else{
                        cout<<"No"<<endl;
                    }
                    break;
                }
                case 4:{
                    if(root)
                    preorder(root);
                    else
                    cout<<"null";
                    cout<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
