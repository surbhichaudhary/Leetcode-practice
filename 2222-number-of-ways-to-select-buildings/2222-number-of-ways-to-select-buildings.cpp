// typedef long long ll;

// class Solution {
// public:
    
//     ll solve( int i, int len, int lp, string& s, vector<vector<vector<ll>>>& t ){
//         if( i >= s.length() || len >= 3 ){
//             return ( len == 3 ? 1 : 0 );
//         }
//         if( t[i][len][lp] != -1 ){
//             return t[i][len][lp];
//         }
//         //curr not taken
//         ll ans = solve( i+1, len , lp, s, t ) ;
//         //when taken
//         if( len == 0 || 
//           ( len > 0 && ((s[i] == '1' && lp == 0) || (s[i] =='0' && lp == 1) )) ){
//             ans += solve( i+1, len+1, s[i]-'0', s, t );
//         }
//         return t[i][len][lp] = ans;
//     }
    
//     long long numberOfWays(string& s) {
//         int n = s.length();
//         vector<vector<vector<ll>>> t(n+1, vector<vector<ll>>(4, vector<ll>(2, -1) ) );
//         return solve( 0, 0, 0, s, t );
//     }
// };

class Solution {
public:
    int len;
    vector<vector<vector<long long>>>dp;
    long long numberOfWays(string s) 
    {
        int idx=0;
        int prv=-1;
        len=s.length()+1;
        long long dp[s.length()+1][3][4];
        memset(dp,-1,sizeof(dp));

        // dp.resize(s.length()+1,vector<vector<long long>>(3,vector<long long>(4,-1)));
        int n=3;
        return fun(s,idx,prv,n,dp);
    }
    long long fun(string &s,int idx,int prv,int n,long long (*dp)[3][4])
    {
        if(n==0)
        return 1;

        if(idx>=s.length())
        return 0;

        if(dp[idx][prv+1][n]!=-1)
        {
            return dp[idx][prv+1][n];
        }

        if(prv==-1)
        {
            long long choise1=fun(s,idx+1,s[idx]-'0',n-1,dp);  //take 
            long long choise2=fun(s,idx+1,prv,n,dp);   //not take
            return dp[idx][prv+1][n]=choise1+choise2;
        }
        else 
        {
            //take choise
            long long choise1=0;
            long long choise2=0;
            if(prv != s[idx]-'0')
            {
                choise1=fun(s,idx+1,s[idx]-'0',n-1,dp);
            }
            choise2=fun(s,idx+1,prv,n,dp);
            return dp[idx][prv+1][n]=choise1+choise2;
        }
        return -1;  //this will never get encounterd
    }
};