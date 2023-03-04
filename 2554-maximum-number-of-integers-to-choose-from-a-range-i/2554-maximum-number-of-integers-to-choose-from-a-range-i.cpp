class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map< int, int> mp;
        for( int i = 0 ; i < banned.size() ; i++ ){
            if( banned[i] <= n ){
                mp[banned[i]]++;
            }
        }
        
        int sum = 0, ans = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
            if( !mp.count(i) ){
                if( sum + i <= maxSum ){
                    sum += i;
                    ans++;
                }
            } 
        }
        return ans;
    }
};