class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int, int > mp;
        bool flag = false;
        int n = cards.size(), ans = n + 1;
        
        for( int i = 0 ; i < n ; i++ ){
            if( mp.count( cards[i] ) ){
                ans = min( ans, i-mp[cards[i]]+1 );
                flag = true;
            } 
            mp[cards[i]] = i;
            
        }
        
        return (!flag) ? -1 : ans;
    }
};