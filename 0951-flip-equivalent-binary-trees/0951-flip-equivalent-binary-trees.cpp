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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if( (!root1) || (!root2) ){
            return ( (!root1) && (!root2) );
        }
        
        if( root1->val != root2->val ){
            return false;
        }
        
        TreeNode* l1 = root1->left ;    TreeNode* r1 = root1->right;
        TreeNode* l2 = root2->left ;    TreeNode* r2 = root2->right;
        
        bool a1 = flipEquiv( l1, l2) && flipEquiv( r1, r2 );
        bool a2 = flipEquiv( l1, r2) && flipEquiv( r1, l2 );
        
        return ( a1 || a2 );
    }
};

