class Solution {
public:
    
    int len;
    unordered_map< string, int > mp;
    
    bool solve( string& in ){
        if( in.length() == len ){
            return ( mp.count(in) );
        }
        
        in.push_back('1');
        if( !solve(in) ) return false;
        in.pop_back();
        
        in.push_back('0');
        if( !solve(in) ) return false;
        in.pop_back();
        
        return true;
    }
    
    bool hasAllCodes(string& s, int k) {
        string curr = "";
        mp.clear();
        //generate all substrings of length k
        for( int i = 0 ; ( i < k ) && ( i < s.length() ) ; i++ ){
            curr.push_back(s[i]);
        }
        //store them in a map
        mp[curr]++;
        for( int i = k ; i < s.length() ; i++ ) {
            curr = curr.substr(1);
            curr.push_back(s[i]);
            mp[curr]++;
        }
        
        len = k;
        curr = "";
        return solve( curr );
        
    }
};