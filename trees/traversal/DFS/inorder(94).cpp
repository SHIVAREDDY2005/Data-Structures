class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        inorder(root->left, res);        // Traverse left subtree
        res.push_back(root->val);        // Visit node
        inorder(root->right, res);       // Traverse right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
