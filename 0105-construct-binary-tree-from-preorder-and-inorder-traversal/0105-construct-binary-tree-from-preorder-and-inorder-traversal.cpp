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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        int prestart = 0, preEnd = preorder.size() - 1;
        int instart = 0, inend = inorder.size() - 1;
         return build(preorder, prestart,preEnd,inorder,instart,inend,inMap);
       
    }
    TreeNode* build(vector<int>&preorder,int prestart,int preEnd,vector<int> &inorder,int instart ,int inend,map<int,int>&inMap){
        if(prestart>preEnd ||instart>inend) return NULL;
        TreeNode *node=new TreeNode(preorder[prestart]);
        int inroot=inMap[node->val];
        int numsleft=inroot-instart;
        node->left=build(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inMap);
        node->right=build(preorder,prestart+numsleft+1,preEnd,inorder,inroot+1,inend,inMap);
        return node;
    } 
};