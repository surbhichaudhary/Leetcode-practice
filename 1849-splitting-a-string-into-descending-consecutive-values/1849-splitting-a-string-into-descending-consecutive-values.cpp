class Solution {
public:
    
    bool solve( int i, long long lp, int w, string& s ){
        if( i >= s.length() ){
            return ( w > 1 );
        }
        
        long long v = 0;
        for( int j = i ; j < s.length() ; j++ ){
            int t = s[j] - '0';
            v *= 10; 
            v += t;
            
            if( lp-v == 1 ){
                if( solve( j+1, v, w+1, s ) ){
                    return true;
                }
            }
            else if( v >= lp ){
                break;
            }
        }
        
        return false;
    }
    
    bool splitString(string& s) {
        long long n = s.length(), v =0, h = n/2, p = pow(10, h) ;
        if( p < 100000000000 ){
            p = 100000000000;
        }
        
        for( int i = 0 ; i < n ; i++ ){
            int t = s[i] - '0';
            v *= 10;
            v += t;
            
            if( solve( i+1, v, 1, s) ){
                return true;
            }
            if( (i > h) && (v > p) ){
                break;
            }
        }
        
        return false;
        
    }
};