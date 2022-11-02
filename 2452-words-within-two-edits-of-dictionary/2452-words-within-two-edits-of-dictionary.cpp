class Solution {
public:
    
    bool diff( string& a, string& b ){
        int c = 0;
        for( int i = 0 ; i < a.length() ; i++ ){
            if( a[i] != b[i] ){
                c++;
            }
            if( c > 2 ){
                return false;
            }
        }
        
        return ( c<=2 );
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
 
        for( int i = 0 ; i < queries.size() ; i++ ){
            for( int j = 0; j < dictionary.size(); j++ ){
                if( diff( queries[i], dictionary[j] ) ){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
      
        return ans;
    }
};