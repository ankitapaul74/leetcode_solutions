/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
       queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>level(n);
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                int index=(flag)?i:(n-1-i);
                level[index]=temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                
            }
            flag=!flag;
            res.push_back(level);
        }
        return res;
    }
};