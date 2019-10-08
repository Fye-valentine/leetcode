//双队列记录层次
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> s1;
        queue<TreeNode*> s2;
        vector<int> v2;
        vector<vector<int>> v1;
        if(root==NULL) return v1;
        s1.push(root);
        v2.push_back(s1.front()->val);
        if(s1.front()->left!=NULL) s2.push(s1.front()->left);
        if(s1.front()->right!=NULL) s2.push(s1.front()->right);
        s1.pop();
        v1.push_back(v2);
        v2.clear();
        while(!(s1.empty()&&s2.empty())){
            if(s1.empty()){
                while(!s2.empty()){
                    v2.push_back(s2.front()->val);
                    if(s2.front()->left!=NULL) s1.push(s2.front()->left);
                    if(s2.front()->right!=NULL) s1.push(s2.front()->right);
                    s2.pop();
                }
            }
            else if(s2.empty()){
                while(!s1.empty()){
                    v2.push_back(s1.front()->val);
                    if(s1.front()->left!=NULL) s2.push(s1.front()->left);
                    if(s1.front()->right!=NULL) s2.push(s1.front()->right);   
                    s1.pop();
                }
            }
            v1.push_back(v2);
            v2.clear();
        }
        return v1;
    }
};
