class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for( int i = 0 ; i < s.length() ; i++ ){
            mp[s[i]]++;
        }
        
        int ans = 0, odd=0;
        for( auto i : mp ){
            if( i.second % 2 == 0 ){
                ans += i.second;
            }
            else{
                odd++;
                ans += ( i.second - 1 );
            }
        }
        if( odd > 0 ){
            ans++;
        }
        
        return ans;
    }
};