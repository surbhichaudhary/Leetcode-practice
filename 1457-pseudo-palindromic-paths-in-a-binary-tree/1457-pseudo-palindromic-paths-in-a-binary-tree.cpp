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
    
    bool isPal( vector<int>& freq ){
        int cnt =0 ;
        
        for( int i = 1 ; i < freq.size() ; i++ ){
            cnt += freq[i];
        }
        
        if( cnt % 2 == 0 ){
            for( int i = 1 ; i < freq.size() ; i++ ){
                if( freq[i] % 2 != 0 ){
                    return false;
                }
            }
        }
        else{
            int uni = 0;
            for( int i = 1 ; i < freq.size() ; i++ ){
                if( freq[i] % 2 != 0 ){
                    uni++;
                }
                if( uni > 1 ){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solve( TreeNode* root, vector<int>& freq, int& ans ){
        if( !root ){
            return ;
        }
        
        freq[root->val]++;
        
        if( !root->left && !root->right && isPal(freq) ){
            ans++;
        }
        
        solve( root->left, freq, ans );
        solve( root->right, freq, ans );
        
        freq[root->val]--;
        
        return ;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if( !root ){
            return 0;
        }
        
        int ans = 0;
        vector<int> freq(10, 0);
        solve( root , freq, ans );
        return ans;
    }
};