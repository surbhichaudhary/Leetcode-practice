class Solution {
public:
    
    
    
    void solve( int i, int n, int k, vector<int>& curr, vector<vector<int>>& ans ){
        if( i > n ){
            if( curr.size() == k ){
                ans.push_back(curr);
            }
            return;
        }
        if( curr.size() == k ){
            ans.push_back(curr);
            return;
        }
        
        solve( i+1, n, k, curr, ans );
        curr.push_back(i);
        solve( i+1, n, k, curr, ans );
        curr.pop_back();
        return;
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve( 1, n, k, curr, ans );
        
        return ans;
    }
};