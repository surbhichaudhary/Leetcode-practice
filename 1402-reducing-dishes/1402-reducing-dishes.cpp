class Solution {
public:
    
    int solve( int i, int time, vector<int>& satisfaction, vector<vector<int>>& t ){
        if( i >= satisfaction.size() ){
            return 0;
        }
        if( t[i][time] != -1 ){
            return t[i][time];
        }
        
        int ans = ( time*satisfaction[i]) + solve( i+1, time+1, satisfaction, t);
        ans = max( ans, solve( i+1, time, satisfaction, t ) );
        
        return t[i][time] = ans;
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort( satisfaction.begin(), satisfaction.end() );
        vector<vector<int>> t ( n+1, vector<int>( n+1, -1) );
        
        return solve( 0, 1, satisfaction, t );
    }
};