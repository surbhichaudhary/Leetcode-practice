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
    
    pair< TreeNode*, bool> solve( TreeNode* root ){
        pair< TreeNode*, bool> ans;
        if( !root ){
            ans.first = NULL;
            ans.second = false;
            return ans;
        }
        
        pair< TreeNode*, bool> la = solve( root->left );
        pair< TreeNode*, bool> ra = solve( root->right );
        
        if( !la.second && !ra.second && root->val == 0 ){
            root = NULL;
            ans.first = NULL;
            ans.second = false;
            return ans;
        }
        
        root->left = la.first;
        root->right = ra.first;
        
        ans.first = root;
        ans.second = true;
        return ans;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        pair< TreeNode*, bool> ans = solve( root );
        return ans.first;
    }
};