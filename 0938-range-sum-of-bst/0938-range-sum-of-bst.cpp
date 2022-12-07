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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if( !root ){
            return 0;
        }
        
        int ans = 0, v = root->val;
        if( (v >= low) && ( v <= high ) ){
            ans += root->val;
        }
        return ( ans + rangeSumBST(root->left, low, high) + 
                       rangeSumBST(root->right, low, high) );
    }
};