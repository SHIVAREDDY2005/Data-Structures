class Solution {
public:
    vector<int> preorder(TreeNode * root,vector<int> &res){
        if(root!=NULL){
            res.push_back(root->val);
            preorder(root->left,res);
            preorder(root->right,res);
        }
        return res;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        preorder(root,res);
        return res;
        
    }
};
