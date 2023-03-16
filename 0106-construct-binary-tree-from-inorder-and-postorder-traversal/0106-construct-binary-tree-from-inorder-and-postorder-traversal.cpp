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
typedef vector<int> vi;

class Solution {
public:
    
    TreeNode* solve( int is, int ie, int ps, int pe, vi& inorder, vi& postorder){
        if( is > ie || ps > pe ){
            return NULL;
        }
        if( is == ie ){
            TreeNode* root = new TreeNode( inorder[is] );
            return root;
        }
        
        int i = is ;
        while( inorder[i] != postorder[pe] ){
            i++;
        }
        
        TreeNode* root = new TreeNode( inorder[i] );
        //see index of postorder in both calls
        root->left = solve( is, i-1, ps, i-is+ps-1, inorder, postorder );
        root->right = solve( i+1, ie, i-is+ps, pe-1, inorder, postorder );
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        return solve( 0, n-1, 0, n-1, inorder, postorder );
    }
};