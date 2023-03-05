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
typedef long long ll;

class Solution {
public:
    
    int height( TreeNode* root ){
        if( !root ){
            return 0;
        }
        
        return (1 + max( height(root->left), height(root->right ) ));
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int hgt = height(root);
        if( hgt < k ){
            return (-1);
        }
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        queue<TreeNode*> q;
        ll curr = 0;
        
        q.push( root );
        q.push( NULL );
        
        while( !q.empty() ){
            TreeNode* fr = q.front();
            q.pop();
            
            if( !fr ){
                pq.push(curr);
                curr = 0;
                if( !q.empty() ){
                    q.push(fr);
                }
                if( pq.size() > k ){
                    pq.pop();
                }
            }
            else{
                curr += fr->val;
                if( fr->left ){
                    q.push(fr->left);
                }
                if( fr->right ){
                    q.push(fr->right );
                }
            }
            
        }
        
        return pq.top();
        
    }
};