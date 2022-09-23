class Solution {
public:
    
    int maximumScore(int a, int b, int c) {
        int ans =0;
        
        while( ( a>0 && b>0 ) || ( b>0 && c>0 ) || ( a>0 && c>0 ) ){
            if( a<=b && a<=c ){
                if( a==0 ){
                    ans += min(b,c);
                    return ans;
                }
                ans++;
                a--;
                if( b>c ) b--;
                else c--;
            }
            else if( b<=c && b<=a ){
                if( b==0 ){
                    ans += min(a,c);
                    return ans;
                }
                ans++;
                b--;
                if( a>c ) a--;
                else c--;
            }
            else if( c<=a && c<=b ){
                if( c==0 ){
                    ans += min(a,b);
                    return ans;
                }
                ans++;
                c--;
                if( a>b ) a--;
                else b--;
            }
        }
        
        return ans;
    }
};