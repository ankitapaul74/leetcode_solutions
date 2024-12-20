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

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (reverse) {
            pushAll(temp->left);
        } else {
            pushAll(temp->right);
        }
        return temp->val;
    }
    
    // Returns true if there are more nodes to process
    bool hasNext() {
        return !st.empty();
    }

private:
    // Helper function to push all nodes along the traversal path
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j) {
            int sum = i + j;
            if (sum == k) {
                return true;
            } else if (sum > k) {
                j = r.next();
            } else {
                i = l.next();
            }
        }
        return false;
    }
};
