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
    
    int solve( TreeNode* root, int& res ){
        if( !root ){
            return 0;
        }
        int la = solve(root->left, res);
        int ra = solve(root->right, res);
        int temp = max(max(la, ra)+root->val, root->val);
        int ans = max(temp, ra+la+root->val);
        res = max( res, ans);
        return temp;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int ans = solve(root, res);
        return res;
    }
};