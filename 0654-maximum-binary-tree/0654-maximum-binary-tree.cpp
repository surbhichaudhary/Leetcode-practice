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
    
    TreeNode* build( int s, int e, vector<int>& nums ){
        if( s>e ){
            return NULL;
        }
        
        int pos = s;
        for( int i = s+1 ; i <= e ; i++ ){ 
            if( nums[i] > nums[pos] ){
                pos = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[pos]);
        
        root->left = build( s, pos-1, nums );
        root->right = build( pos+1, e, nums );
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return build( 0, n-1, nums );
    }
};