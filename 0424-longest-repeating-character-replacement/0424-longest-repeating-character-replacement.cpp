class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), i=0, j=0, ans = 0, cmx = 0;
        unordered_map< char, int> mp;
        
        while( j < n ) {
            mp[s[j]]++;
            
            for( auto i : mp ){
                cmx = max( cmx, i.second );
            }
            
            if( j-i+1 <= cmx + k ){
                ans = max( ans, j-i+1 );
            }
            else{
                while( j-i+1 > cmx + k ){
                    mp[s[i]]--;
                    if( mp[s[i]] == 0 ){
                        mp.erase( s[i] );
                    }
                    
                    i++;
                    for( auto i : mp ){
                        cmx = max( cmx, i.second );
                    }
                }
            }
            j++;
        }
        
        return ans;
    }
};