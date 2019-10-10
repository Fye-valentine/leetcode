//自底向上
//提前阻断

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isB(root)!=-1;
    }

    int isB(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=isB(root->left);
        int right=isB(root->right);
        if(left==-1)
            return -1;
        if(right==-1)
            return -1;
        return abs(left-right)>1?-1:max(left,right)+1;
    }
};
