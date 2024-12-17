/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent,TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*current=q.front();
            q.pop();
            if(current->left){
                parent[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent[current->right]=current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>p;
        markparent(root,p,target);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target]=true;
        int dis=0;
        while(!q.empty()){
            int n=q.size();
            if(dis==k) break;
            dis++;
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !vis[current->left]){
                    q.push(current->left);
                    vis[current->left]=true;
                }
                if(current->right &&!vis[current->right]){
                    q.push(current->right);
                    vis[current->right]=true;
                }
                if(p[current] && !vis[p[current]]){
                    q.push(p[current]);
                    vis[p[current]]=true;
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            res.push_back(temp->val);
        }
        return res;
    }
};