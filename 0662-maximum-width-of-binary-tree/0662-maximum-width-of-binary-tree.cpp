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
    int widthOfBinaryTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int min=q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                int curr=q.front().second-min;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=curr;
                if(i==n-1) last=curr;
                if(node->left!=NULL){
                  q.push({node->left,(long long)curr*2 +1});
                }
                if(node->right!=NULL){
                    q.push({node->right,(long long)curr*2 +2});
                }
            }
        ans=max(ans,last-first+1);
        }
        return ans;
    }
};