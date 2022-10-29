class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long n = chalk.size(), s =0 ;
        for( int i =0 ; i < n ; i++ ){
            s += chalk[i];
        }
        
        k %= s;
        for( int i = 0 ; i < n ; i++ ){
            if( k < chalk[i] ){
                return i;
            }
            k -=chalk[i];
        }
        
        return -1;
    }
};