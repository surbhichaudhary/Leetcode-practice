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
    
    bool mirror( TreeNode* a, TreeNode* b ){
        if( !a || !b ){
            return ( !a && !b );
        }
        
        if( a->val == b->val ){
            return mirror( a->left, b->right ) && mirror( a->right, b->left );
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if( !root ){
            return true;
        }
        return mirror( root->left, root->right );
    }
};