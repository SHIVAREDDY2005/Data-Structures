class Solution {
    void invert(TreeNode* root){
        if(root!=nullptr){
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
            invert(root->left);
            invert(root->right);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
