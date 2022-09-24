class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int , int> full;
        int n = rains.size(), mx = 0 ;
        set<int> pos;
        vector<int> ans(n, INT_MIN);
  
        for( int i = 0 ; i < n ; i++ ){
            if( rains[i] > 0 ){
                mx = max( mx, rains[i] );
                if( full.count( rains[i] ) ){
                    auto it = pos.lower_bound( full[rains[i]] );
                    if( it == pos.end() ){
                        ans.clear();
                        return ans;
                    }
                    ans[*it] = rains[i];
                    pos.erase(*it);
                }
                ans[i] = -1;
                full[rains[i]] = i;
            }
            else{
                ans[i] = 1;
                pos.insert(i);
            }
        }
        
        return ans;
    }
};