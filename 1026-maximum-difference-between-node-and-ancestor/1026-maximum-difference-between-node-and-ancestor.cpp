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
typedef pair<int,int> pi;

class Solution {
    
    int diff( TreeNode* root, int mn, int mx ){
        if( !root ){
            return mx-mn;
        }
        mn = min( mn, root->val );
        mx = max( mx, root->val );
        int l = diff( root->left, mn, mx ); 
        int r = diff( root->right, mn, mx );
        return max( l,  r );
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        if( !root ){
            return 0;
        }
        return diff( root, root->val, root->val );
    }
};