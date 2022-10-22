class Solution {
public:
    string minWindow(string s, string t) {
        
        if( s.length() < t.length() ){
            return "";
        }
        
        unordered_map<char, int> mp;
        for( int i = 0 ; i < t.length() ; i++ ){
            mp[t[i]]++;
        }
        
        int c = mp.size(), i =0, j = 0, n = s.length(), ans = INT_MAX, st = -1;
        while( j < n ){
            if( mp.count(s[j]) ){
                mp[s[j]]--;
                if( mp[s[j]] == 0 ){
                    c--;
                }
            }
            if( c == 0 ){ 
                while( i <= j && c == 0 ){
                    if( c == 0 && j-i+1 < ans){
                        ans = min( ans, j-i+1 );
                        st =  i;
                    }
                    
                    if( mp.count( s[i]) ){
                        mp[s[i]]++;
                        if( mp[s[i]] == 1 ){
                            c++;
                        }
                    }
                    i++;
                    
                    if( c == 0 && j-i+1 < ans){
                        ans = min( ans, j-i+1 );
                        st =  i;
                    }
                }
            }
            j++;
        }
        /* if( c==0 ){
                while( i<=j && i<n && c == 0 ){
                    if( c == 0 && ml > j-i+1 ){
                        st = i;
                        ml = min(ml, j-i+1);
                    }
                    if( mp.find(s[i]) != mp.end() ){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1 ){
                            c++;
                        }
                    }
                    i++;
                    if( c == 0 && ml > j-i+1 ){
                        st = i;
                        ml = min(ml, j-i+1);
                    }
                }
            } */
        if( ans == INT_MAX ){
            return "";
        }
        
        string mws = s.substr(st, ans);
        return mws;
    }
};
