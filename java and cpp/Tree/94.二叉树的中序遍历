// 非递归栈实现中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *temp=root;
        vector<int> res;
        stack<TreeNode*> path;
        while(temp!=NULL){
            path.push(temp);
            temp=temp->left;
        }  
        while(!path.empty()){
            temp=path.top();
            res.push_back(temp->val);
            path.pop();
            temp=temp->right;
            while(temp!=NULL){
                path.push(temp);
                temp=temp->left;
            }
        }
        return res;
    }
};
