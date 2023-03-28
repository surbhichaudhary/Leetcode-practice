class Solution {
    
    int solve( int i, vector<int>& days, vector<int>& costs, vector<int>& t ){
        if( i >= days.size() ){
            return 0;
        }
        if( t[i] != -1 ){
            return t[i];
        }
        int ans = costs[0] + solve( i+1, days, costs, t), j = i+1;
        while( j < days.size() && days[i] + 7 > days[j] ){
            j++;
        }
        ans = min(ans, costs[1] + solve( j, days, costs, t) );
        j = i+1;
        while( j < days.size() && days[i] + 30 > days[j] ){
            j++;
        }
        ans = min(ans, costs[2] + solve( j, days, costs, t) );
        t[i] = ans;
        return ans;
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> t( n+1, -1 );
        return solve(0, days, costs, t );
    }
};