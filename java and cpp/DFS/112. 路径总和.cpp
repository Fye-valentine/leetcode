//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

class Solution {
public:
    int flag=0;
    bool hasPathSum(TreeNode* root, int sum) {
        int add=0;
        if(root!=NULL)
            hPS(root, sum, add);
        return flag==1?true:false;
    }
    void hPS(TreeNode* root, int sum, int add){
        add+=root->val;
        if(add==sum&&root->left==NULL&&root->right==NULL)
            flag=1;
        if(root->left!=NULL){
            hPS(root->left, sum, add);
        }
        if(root->right!=NULL){
            hPS(root->right, sum, add);
        }
    }
};
