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
    
    unordered_map< int, int> mp;
    void inorder( TreeNode* root, vector<int>& in ){
        if( !root ){
            return ;
        }
        
        inorder(root->left, in );
        mp[root->val]++;
        in.push_back(root->val);
        inorder( root->right, in );
        
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        if( !root ){
            return ans;
        }
        
        vector<int> in;
        mp.clear();
        inorder( root, in );
        int n = in.size();
        
        for( int i =0 ; i < queries.size() ; i++ ){
            int v = queries[i];
            //in range & present
            if( mp.count(v) ){
                ans.push_back({ v, v });
            }
            //smaller than all
            else if( v < in[0] ){
                ans.push_back({ -1, in[0] });
            }
            //greater than all
            else if( v > in[n-1] ){
                ans.push_back({ in[n-1], -1 });
            }
            
            else{
                vector<int>::iterator l;
                l = lower_bound( in.begin(), in.end(), v );
                int p = l - in.begin();
                //
                ans.push_back({ in[p-1], in[p] });
                
            }
        }
        
        return ans;
    }
};

