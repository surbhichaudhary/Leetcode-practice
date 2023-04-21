typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

class Solution {
public:
    
    int num, pr, m = 1000000007 ;
    
    int solve( int i, int cr, int sm, vi& grp, vi& pro, vvvi& dp ){
        if( sm > pr ){
            sm = pr;
        }
        
        if( i >= pro.size() ){
            if( (cr <= num) && (sm >= pr) ){
                return 1;
            }
            return 0;
        }
        if( cr > num ){
            return 0;
        }
        
        if( dp[i][cr][sm] != -1 ){
            return dp[i][cr][sm];
        }
        
        int exc = solve( i+1, cr, sm, grp, pro, dp )%m, inc = 0, up = cr + grp[i];
        if( up <= num ){
            inc = solve( i+1, up, sm+pro[i], grp, pro, dp )%m;
        }
  
        return dp[i][cr][sm] = ( exc + inc )%m;

    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        num = n, pr = minProfit;
        int sum = 0 , sz = group.size(), cr = 0 ;
        for( int i = 0 ; i < sz ; i++ ){
            sum += profit[i];
            cr += group[i];
        }
        
        // i , people, profit
        vvvi dp( sz+1, vvi( cr+1, vi( minProfit+1, -1 ) ) );
        return solve( 0, 0, 0, group, profit, dp );
    }
};