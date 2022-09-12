class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for( int i = 0 ; i < words.size() ; i++ ){
            mp[words[i]]++;
        }
        
        int ans = 0, odd = 0 ;
        for( auto i : mp ){
            if( i.second == 0 ){
                continue;
            }
            
            string a = i.first;
            string b = i.first;
            reverse( a.begin(), a.end() );
            
            int c = b.compare(a) ;
            
            if( c == 0 ){
                if( i.second % 2 == 0 ){
                    ans += ( 2 * i.second );
                    //cout<<i.second<<endl;
                }
                else{
                    odd++;
                    ans += 2 * ( i.second - 1 );
                    //cout<<( i.second - 1 )<<endl;
                }
            }
            else if( c != 0  && mp.count(a) && mp[a] > 0 ){
                int t = min( i.second, mp[a] );
                //cout<<t<<endl;
                ans += t*4;
                mp[a] -= t;
                mp[b] -= t;
            }
        }
        
        if( odd > 0 ){
            ans += 2;
        }
        
        return ans;
    }
};