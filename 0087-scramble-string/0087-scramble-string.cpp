class Solution {
public:
    
    bool solve( string& a, string& b, unordered_map<string, bool>& mp ){
        int n1 = a.length(), n2 = b.length();
        string curr = a;
        curr.push_back('+');
        curr += b;
        
        if( n1 != n2 )
            return (mp[curr] = false);
        
        if((n1 == 0) || (a.compare(b) == 0) )
            return (mp[curr] = true);
        
        if( mp.count(curr) )
            return mp[curr];
        
        for( int i = 1 ; i < n1 ; i++ ){
            string a1 = a.substr(0, i), a2 = a.substr(i);
            string b1 = b.substr(0, i), b2 = b.substr(i);
            string b3 = b.substr( n1-i, i), b4 = b.substr( 0, n1-i );
            // no swap || swap
            if( ( solve( a1, b1, mp ) && solve( a2, b2, mp ) ) || 
                ( solve( a1, b3, mp ) && solve( a2, b4, mp ) ) ){
                return mp[curr] = true;
            }
        }
        
        return mp[curr] = false;
        
    }
    
    bool isScramble(string s1, string s2) {
        if( s1.length() != s2.length() ){
            return false;
        }
        if( s1.compare(s2) == 0 ){
            return true;
        }
        
        unordered_map< string, bool > mp;
        return solve( s1, s2, mp );
    }
};