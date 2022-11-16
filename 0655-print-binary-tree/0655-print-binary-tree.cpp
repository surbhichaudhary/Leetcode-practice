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
    
    int hgt( TreeNode* root ){
        if( !root ){
            return 0;
        }
        
        return 1 + max( hgt( root->left ), hgt( root->right ) );
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int h = hgt( root ), r = h, c = pow( 2,h ) - 1;
        
        queue< pair<vector<int> , TreeNode*> > q;
        vector<vector<string>> ans( r, vector<string>(c, "") );
        
        q.push({ {0, (c-1)/2}, root });
        
        while( !q.empty() ){
            int s = q.size();
            for( int i = 0 ; i < s ; i++ ){
                pair<vector<int> , TreeNode*> fr = q.front();
                q.pop();

                int x = fr.first[0], y = fr.first[1], p = pow( 2, h-x-2);
                TreeNode* curr = fr.second;
                
                ans[x][y] = to_string( curr->val );
                
                if( curr->left ){
                    q.push({ { x+1, y-p }, curr->left });
                }
                if( curr->right ){
                    q.push({ { x+1, y+p }, curr->right });
                }
            }
        }
        
        return ans;
    }
};

