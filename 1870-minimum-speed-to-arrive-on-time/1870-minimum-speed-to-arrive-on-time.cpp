class Solution {
public:
   
    bool isPossible( vector<int>& dist, long long speed, double hour ){
        double time = 0.0 ;
        int n = dist.size();
        
        for( int i = 0 ; i < n-1 ; i++ ){
            time += ceil( (double)dist[i] / speed );  
        }
        
        time += (double)dist[n-1]/speed;
        
        return (time <= hour);
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long n = dist.size(), s = 1, e = 1e9, ans = -1, m;
        
        while( s <= e ){
            m = s + (e-s)/2;
            if( isPossible( dist, m, hour) ){
                e = m-1;
                ans = m;
            }
            else{
                s = m+1;
            }
        }
        
        return ans;
    }
};