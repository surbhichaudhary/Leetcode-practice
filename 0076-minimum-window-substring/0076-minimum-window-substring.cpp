class Solution {
public:
    string minWindow(string s, string t) {
        if( s.length() < t.length() )
            return "";
        
        unordered_map< char, int> mp;
        
        for( int x = 0; x < t.length() ; x++ ){
            mp[t[x]]++;
        }
        
        int n = s.length(), i=0, j=0, st=-1, ans = n+1, cnt = mp.size();
        
        while( j < n ){
            
            if( mp.find(s[j]) != mp.end() ){
                mp[s[j]]--;
                if(mp[s[j]] == 0 ){
                    cnt--;
                }
            }

            if( cnt == 0 ){
                while( (cnt == 0) && ( i <= j) ){
                    if( (cnt == 0) && ( ans > (j-i+1) ) ){
                        st = i;
                        ans = j-i+1;
                    }
                    if( mp.find(s[i]) != mp.end() ){
                        mp[s[i]]++; 
                        if( mp[s[i]] == 1 ){
                            cnt++;
                        }
                    }
                    
                    i++;
                    if( (cnt == 0) && ( ans > (j-i+1) ) ){
                        st = i;
                        ans = j-i+1;
                    }
                }
            }
            
            j++;
        }
        if( ans > n )
            return "";
        
        return s.substr( st, ans );
        
    }
};
