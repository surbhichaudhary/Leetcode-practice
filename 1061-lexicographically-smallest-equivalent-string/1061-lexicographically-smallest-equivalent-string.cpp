class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector< set<char >> mp(26);
        
        for( int i = 0 ; i < s1.length() ; i++ ){
            mp[ s1[i]-'a' ].insert( s2[i] );
            mp[ s2[i]-'a' ].insert( s1[i] );
        }
        
        for( int i = 0 ; i < 26 ; i++ ){ // each char
            if( mp[i].size() < 2 ){
                continue;
            }
            set<char> curr = mp[i];
            for( auto j : curr ){
                for( auto k : curr ){
                    mp[k-'a'].insert(j);
                }
            }
        }
        /*for (auto itr : s) {
            cout << itr << " ";
          } 
          
          for (itr = s.begin(); itr != s.end(); itr++) {
            cout << *itr << " ";
          } */
        string ans = "";
        for( int i = 0 ; i < baseStr.length() ; i++ ){
            set<char> curr = mp[baseStr[i]-'a'];
            char c = baseStr[i];
            for( auto j : curr ){
                if( j < c ){
                    c = j;
                }
            }
            
            ans += c;
        }
        return ans;
    }
};