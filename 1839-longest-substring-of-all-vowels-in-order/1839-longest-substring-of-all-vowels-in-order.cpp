class Solution {
public:
    
    int order( char c ){
        if( c == 'a' ) return 1;
        if( c == 'e' ) return 2;
        if( c == 'i' ) return 3;
        if( c == 'o' ) return 4;
        return 5;
    }
    
    int longestBeautifulSubstring(string word) {
        int n = word.length(), i=0, j=0, ans=0 ;
        if( n < 5 ){
            return 0;
        }
        char lp = 'z';
        unordered_map<char, int> mp;
        
        while( j < n ){
            mp[word[j]]++;
            if( lp != 'z' ){
                int ol = order(lp);
                int oc = order(word[j]);
                
                if( ol > oc ){
                    mp.clear();
                    i = j;
                    mp[word[j]]++;
                }
            }
            
            lp = word[j];
            
            if( mp.size() == 5 ){
                ans = max( ans, j-i+1 );
            }
            j++;
        }
        
        return ans;
    }
};