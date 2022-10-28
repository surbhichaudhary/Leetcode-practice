class Solution {
public:
    
    int solve( int i, string time ){
        if( i >= time.length() ){
            return 1;
        }
        
        int ans = 0;
        
        if( time[i] == '?' ){
            if( i == 0 ){
                if( time[1] == '?' ){
                    for( int j = 0 ; j < 3 ; j++ ){
                        time[i] = j + '0';
                        ans += solve( i+1, time );
                    }
                }
                else{
                    int r = 2;
                    if( time[1] == '0' || time[1] == '1'|| time[1] == '2' || time[1] == '3' ){
                        r = 3;
                    }
                    for( int j = 0 ; j < r ; j++ ){
                        time[i] = j + '0';
                        ans += solve( i+1, time );
                    }
                }
                
            }
            else if( i == 1 ){
                int r = 0;
                if( time[0] == '0' || time[0] == '1' ){
                    r = 10;
                }
                else if( time[0] == '2' ){
                    r = 4;
                }
                for( int j = 0 ; j < r ; j++ ){
                    time[i] = j + '0';
                    ans += solve( i+1, time );
                }
            }
            
            else if( i == 3 ){
                for( int j = 0 ; j < 6 ; j++ ){
                    time[i] = j + '0';
                    ans += solve( i+1, time );
                }
            }
            
            else if( i == 4 ){
                for( int j = 0 ; j < 10 ; j++ ){
                    time[i] = j + '0';
                    ans += solve( i+1, time );
                }
            }
            return ans;
        }
        return solve( i+1, time );
    }
    
    int countTime(string& time) {
        return solve( 0, time );
    }
};