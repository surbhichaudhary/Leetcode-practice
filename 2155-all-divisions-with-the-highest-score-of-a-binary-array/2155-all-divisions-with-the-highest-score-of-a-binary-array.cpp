class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        vector<int> lft( n+1, 0 );
        vector<int> rgt( n+1, 0 );
        
        for( int i = 1 ; i<= n ; i++ ){
            int c = ((nums[i-1] == 0 )? 1 : 0 );
            lft[i] = lft[i-1] + c;
        }
        for( int i = n-1 ; i>=0 ; i-- ){
            int c = ((nums[i] == 1 )? 1 : 0 );
            rgt[i] = rgt[i+1] + c;
        }
        
        unordered_map< int , vector<int> > mp;
        for( int i = 0 ; i <= n ; i++ ){
            int c = lft[i] + rgt[i];
            mp[c].push_back(i);
        }
        
        for( auto i : mp ){
            ans = max( ans, i.first );
        }
        return mp[ans];
    }
};