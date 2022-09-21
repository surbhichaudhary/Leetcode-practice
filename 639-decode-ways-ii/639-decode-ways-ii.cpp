#define m 1000000007

class Solution {
public:
    
    long long solve( int i, string& s, vector<long long>& dp ){
        long long n = s.length(), ans = 0;
        
        if( i >= n ){
            return 1;
        }
        
        if( dp[i] != -1 ){
            return dp[i];
        }
        
        if( s[i] == '*' ){
            for( int j = 1 ; j <= 9 ; j++ ){
                ans = (ans%m + solve( i+1, s, dp )%m)%m;
                
                if( i < n-1 ){
                    int num= j*10;
                   
                    if( s[i+1] == '*' ){
                        for( int k = 1 ; k <= 9 ; k++ ){
                            int curr = num + k;
                            if( curr > 9 && curr < 27 ){
                                ans = (ans%m + solve( i+2, s, dp )%m)%m;
                            }
                        }
                    }
                    else{
                        int curr = num + ( s[i+1]-'0' );
                        if( curr > 9 && curr < 27 ){
                            ans = (ans%m + solve( i+2, s, dp )%m)%m;
                        }
                    } 
                    
                }// if end
            }//for loop
        }//if end
        
        else{
            int num = (s[i] - '0');
            if( num > 0 ){
                ans += solve( i+1, s, dp );
            }
            if( i < n-1 && num < 3 ){
                num*= 10;
                if( s[i+1] == '*' ){
                    for( int j = 1 ; j <= 9 ; j++ ){
                        long long curr = num + j;
                        if( curr > 9 && curr < 27 ){
                            ans = (ans%m + solve( i+2, s, dp )%m)%m;
                        }
                    }
                }
                else{
                    long long curr = num + ( s[i+1]-'0' );
                    if( curr > 9 && curr < 27 ){
                        ans = (ans%m + solve( i+2, s, dp )%m)%m;
                    }
                }
            }
        }
        dp[i] = ans%m;
        return ans;
    }
  
    int numDecodings(string& s) {
        
        int n = s.length();
        vector<long long> dp(n+1, -1);
        
        return solve( 0, s, dp );
    }
};
