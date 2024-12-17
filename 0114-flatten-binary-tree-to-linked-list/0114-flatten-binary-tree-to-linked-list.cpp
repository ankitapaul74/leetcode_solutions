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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right!=NULL){
                st.push(curr->right);
            }
            if(curr->left!=NULL){
                st.push(curr->left);
            }
            curr->right = st.empty()?NULL: st.top();
            curr->left=NULL;
        }
    }
};