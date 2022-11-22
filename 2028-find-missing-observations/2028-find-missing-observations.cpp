class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), s = 0;
        
        for( int i =0 ; i< m ;i++ ){
            s += rolls[i];
        }
        
        int ns = ( mean*( n+m ) ) - s,  all = ns/n, i=0;
        
        if(( all > 6) || (all < 1) ){
            vector<int> ans;
            return ans;
        }
        
        vector<int> ans(n,all);
        
        ns -= ( all*n );
        
        if( ns == 0 ){
            return ans;
        }
        if( (all == 6) && (ns != 0) ){
            ans.clear();
            return ans;
        }

        for( int i =0 ; i< n ;i++ ){
            int av = min( 6 - ans[i], ns );
            ns -= av;
            ans[i] += av;
            
            if( ns == 0 ){
                break;
            }
        }
        return ans;
    }
};