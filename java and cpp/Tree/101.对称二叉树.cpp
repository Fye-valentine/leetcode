class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isS(root->left, root->right);
    }
    bool isS(TreeNode* Left, TreeNode* Right){
        if(Left==NULL&&Right==NULL){
            return true;
        }
        if(Left==NULL||Right==NULL){
            return false;
        }
        return (Left->val==Right->val)
            &&isS(Left->left,Right->right)
            &&isS(Left->right,Right->left);
    }
};
