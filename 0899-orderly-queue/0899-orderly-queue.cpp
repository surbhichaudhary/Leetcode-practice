class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.length();
        if( n < 2 || k == 0 ){
            return s;
        }
        if( k == 1 ){
            string ans = s;
            for( int i = 1 ; i < n ; i++ ){
                string curr = s.substr(i) + s.substr(0, i);
                if( ans.compare(curr) > 0 ){
                    ans = curr;
                }
            }
            
            return ans;
        }
        
        sort( s.begin(), s.end());
        return s;
    }
};