class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode *>q;
        vector<vector<int>>res;
        q.push(root);
        res.push_back({root->val});
        int  c=0;
        while(!q.empty()){
            c++;
            int s=q.size();
            vector<int>level;
            for(int i=0;i<s;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left!=nullptr){
                    level.push_back(cur->left->val);
                    q.push(cur->left);
                }
                if(cur->right!=nullptr){
                    level.push_back(cur->right->val);
                    q.push(cur->right);
                }        
            }
            if(c%2==1)              reverse(level.begin(),level.end());    
            if(level.size()>0)      res.push_back(level);
        }
        return  res;
    }
};
