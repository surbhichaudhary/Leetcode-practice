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
    
    unordered_map<int, int> mp;
    
    void hgt( TreeNode* root, int lvl ){
        if( !root ){
            return;
        }
        
        mp[lvl]++;
        
        if( !root->left && !root->right ){
            return;
        }
        
        hgt( root->left , lvl + 1 );
        hgt( root->right, lvl + 1 );
        
        return ;
    }
    
    int countNodes(TreeNode* root) {

        int ans =0 ;
        mp.clear();
        
        hgt( root, 0 );
        
        for( auto i : mp ){
            ans += i.second;
        }
        return ans;
    }
};
