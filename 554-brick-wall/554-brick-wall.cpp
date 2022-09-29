class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), mx = 0;
        unordered_map<int, int> mp;
        
        for( int i=0; i< n ;i++ ){
            int m = 0;
            for( auto j : wall[i] ){
                m += j;
                mp[m]++;
            }
            mx = max( mx, m );
        }
        
        int ans = 0;
        for( auto i : mp ){
            //cout<<i.first<<" "<<i.second<<endl;
            if( i.first != mx ){
                ans = max( ans, i.second );
            }
        }
        
        return ( n - ans );
    }
};