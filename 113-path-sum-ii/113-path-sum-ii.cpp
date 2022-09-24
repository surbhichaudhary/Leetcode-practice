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
    
    void solve( TreeNode* root,vector<int>& path, int cs, int& ts, vector<vector<int>>& ans){
        if( !root ){
            if( cs == ts ){
                ans.push_back(path);
            }
            return ;
        }
        if( !root->left && !root->right ){
            if( ts == cs + root->val ){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        cs += root->val;
        path.push_back(root->val);
        
        if( root->left ){
            solve( root->left, path, cs, ts, ans );
        }
        if( root->right ){
            solve( root->right, path, cs, ts, ans );
        }
        path.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if( !root ){
            return ans;
        }
        
        vector<int> path;
        solve( root, path, 0, targetSum, ans );
        
        return ans;
    }
};