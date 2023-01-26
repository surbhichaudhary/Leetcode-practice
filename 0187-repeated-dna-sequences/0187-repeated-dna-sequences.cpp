class Solution {
public:
    vector<string> findRepeatedDnaSequences(string& s) {
        vector<string> ans;
        string curr = "";
        unordered_map< string, int > mp;
        
        for( int i = 0 ; ( i < 10) && ( i < s.length() ) ; i++ ){
            curr.push_back(s[i]);
        }
        
        mp[curr]++;
        for( int i = 10 ; i < s.length() ; i++ ) {
            curr = curr.substr(1);
            curr.push_back(s[i]);
            mp[curr]++;
        }
        
        for( auto i : mp ){
            if( i.second > 1 ){
                ans.push_back( i.first );
            }
        }
        
        return ans;
        
    }
};