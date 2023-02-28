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
    
    unordered_map<string, vector<TreeNode*> > mp;
    
    string inorder( TreeNode* root, vector<int>& in ){
        if( !root ){
            return "";
        }
        
        string ans = "c1_";
        ans += inorder( root->left, in );
        ans += ("r_");
        ans += (to_string(root->val));
        ans += ("c2_");
        ans += inorder( root->right, in );
      //  cout<<ans<<endl;
        mp[ans].push_back(root);
        return ans;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<int> in;
        vector<TreeNode*> dup;
        
        mp.clear();
        string ans = inorder( root, in );
        for( auto i : mp ){
            if( i.second.size() > 1 ){
                dup.push_back(i.second[0]);
            }
        }
        return dup;
    }
};