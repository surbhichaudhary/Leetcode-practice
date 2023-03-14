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
    void numSum( TreeNode* root, long long int cs, long long int& s ){
        if( !root ){
            s += cs;
            return;
        }
        
        cs = (cs*10) + root->val ;
        if( !root->left && !root->right ){
            s += cs;
            return;
        }
        if( !root->left ){
            numSum( root->right, cs, s);
            return;
        }
        if( !root->right ){
            numSum( root->left, cs, s);
            return;
        }
        
        numSum( root->left, cs, s);
        numSum( root->right, cs, s);
        return;
    }
    
public:
    int sumNumbers(TreeNode* root) {
        long long int s=0;
        numSum(root, 0, s);
        return s;
    }
};