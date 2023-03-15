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
    
//     bool solve( TreeNode* root, int lvl, int cnt, unordered_map<int, int>& mp ){
//         if( !root ){
//             return true;
//         }
//         if( !root->left && root->right ){
//             return false;
//         }
        
        
//         bool la = solve( root->left, lvl+1, mp );
//         bool ra = solve( root->right, lvl+1, mp );
        
//         mp[lvl]++;
//         return ( la && ra );
        
//     }
    
    bool isCompleteTree(TreeNode* root) {
        int h = hgt( root ), cnt = 0;
        queue< pair<TreeNode*, int> > q;
        unordered_map<int, int> mp;
        
        q.push({ root, 0 });
        q.push({ NULL, 0 });
        
        while( !q.empty() ){
            TreeNode* fr = q.front().first;
            int lvl = q.front().second, s = q.size()-1;
            q.pop();
            
            if( !fr ){
                int p = pow( 2, lvl );
                if( (lvl != h-1) && (mp[lvl] != p) ){
                    //cout<<"HERE 54 line "<<lvl<<endl;
                    return false;
                }
                if( !q.empty() ){
                    q.push({ NULL, lvl+1 });
                }
                continue;
            }
            
            mp[lvl]++;
            
            if( !fr->left && fr->right ){
               // cout<<"HERE 2"<<endl;
                return false;
            }
            
            if( ( s > 1 ) && (q.front().first) && ( !fr->left || !fr->right ) ){
                TreeNode* tmp = q.front().first;
                if( tmp->left || tmp->right  ){
                   // cout<<"HERE 3"<<endl;
                    return false;
                }
            }
            if( fr->left ){
                q.push({ fr->left, lvl+1 });
            }
            if( fr->right ){
                q.push({ fr->right, lvl+1 });
            }
        }
        return true;

    }
};