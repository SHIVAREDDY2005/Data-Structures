// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root==nullptr)return -1;
        int lt=height(root->left);
        int rt=height(root->right);
        return max(lt,rt)+1;
    }
};
