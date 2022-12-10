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
#define m 1000000007
typedef long long ll;

class Solution {
public:
    
    ll ts, ans;
    
    int total( TreeNode* root ){
        if( !root ){
            return 0;
        }
        
        return ( root->val + total( root->left ) + total( root->right ) );
    }
    
    ll solve( TreeNode* root ){
        if( !root ){
            return 0;
        }
        
        ll curr = solve( root->left ) + solve( root->right ) + root->val;
        ll pr = curr*( ts-curr );
        
        ans = max( ans, pr );
        return curr;
    }
    
    int maxProduct(TreeNode* root) {
        if( !root ){
            return 0;
        }
        ts = total( root );
        ans = INT_MIN;
        
        ll curr = solve( root );
        
        return ans%m;
        
    }
};

