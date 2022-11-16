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
    
    int solve( TreeNode* root ){
        if( !root ){
            return 0;
        }
        
        int la = solve( root->left );
        int ra = solve( root->right );
        
        int s = root->val + la + ra;
        mp[s]++;
        
        return s;

    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mp.clear();
        
        int s = solve( root ), mx = 0;
        
        unordered_map< int, vector<int> > freq;
        for( auto i : mp ){
            if( i.second > mx ){
                freq.clear();
                mx = i.second;
                freq[mx].push_back( i.first );
            }
            else if( i.second == mx ){
                freq[mx].push_back( i.first );
            }
        }
        
        return freq[mx];
    }
};

