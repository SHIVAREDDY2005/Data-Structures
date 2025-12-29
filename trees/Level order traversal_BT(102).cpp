class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *>qe;
        qe.push(root);
        if(root==NULL) return {};
        vector<vector<int>>re;
        re.push_back({root->val});
        while(qe.size()>0){
            vector<int>res;
            int s=qe.size();
            for(int i=0;i<s;i++){
                TreeNode *cur=qe.front();
                qe.pop();
                if(cur->left!=nullptr){
                qe.push(cur->left);
                res.push_back(cur->left->val);
                }
                if(cur->right!=nullptr){
                qe.push(cur->right);
                res.push_back(cur->right->val);
                }
            }
           if(res.size()>0)
                re.push_back(res);
        }
        return re;
    }
};
