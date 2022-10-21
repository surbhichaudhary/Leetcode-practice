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
    
    unordered_map< string, vector<TreeNode*> > mp;
    
    string unique( TreeNode* root ){
        if( !root ){
            return "";
        }
        
        string curr = to_string(root->val);
        curr.push_back('_');
        string la = unique( root->left );
        curr += la;
        
        curr.push_back('_');
        string ra = unique( root->right );
        curr += ra;
        
        mp[curr].push_back(root);
        if( mp[curr].size() > 2 ){
            mp[curr].pop_back();
        }
        return curr;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear();
        vector<TreeNode*> ans;
        string t = unique(root);
        
        for( auto i : mp ){
            if( i.second.size() > 1 ){
                ans.push_back( (i.second)[0] );
            }
        }
        
        return ans;
    }
};