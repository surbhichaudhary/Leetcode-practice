struct job{
    int st, ed, pr;
};

class Solution {
public:
    
    int n;
    
    static bool comp( job& a, job& b ){
        return ( a.st < b.st ) ;
    }
    
    int nextJob( int curr , vector<job>& v ){
        int s = curr + 1, e = n-1, ans = n ;
        
        while( s <= e ){
            int m = s + ( e-s )/2;
            
            if( v[m].st >= v[curr].ed ){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
            
        }
        
        return ans;
    }
    
    int solve( int i, vector<job>& v, vector<int>& t )
    {
        if( i >= n ){
            return 0;
        }
        if( t[i] != -1 ){
            return t[i];
        }
        //when not taking current job
        int exc = solve( i+1, v, t );
        //when taking current job
        int nxt = nextJob( i, v );
        int inc = v[i].pr + solve( nxt, v, t ) ;
        
        t[i] = max( inc, exc );

        return t[i];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        n = startTime.size();
        vector<job> v(n);
        
        for( int i = 0 ; i < n ; i++ ){
            v[i].st = startTime[i];
            v[i].ed = endTime[i];
            v[i].pr = profit[i];
        }
        
        sort( v.begin(), v.end(), comp );
        vector<int> t( n+1, -1 );
        
        return solve( 0, v, t );
        
    }
};