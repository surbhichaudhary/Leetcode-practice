typedef long long ll;

class Solution {
public:
    
    bool isPossible( ll t, vector<int>& time, int trip ){
        ll k = 0;
        for( int i = 0 ; i < time.size() ; i++ ){
            ll curr = time[i];
            if( curr > t ){
                break;
            }
            k += ( t/curr );
            
            if( k >= trip ){
                return true;
            }
        }
        
        return ( k >= trip );
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort( time.begin(), time.end() );
        ll n = time.size(), s = 1, e = 1e16, ans = e;
        
        for( int i =0 ; i < n ; i++ ){
            e = min( e, ll(time[i])*totalTrips );
            ans = e;
        }
        
        while( s <= e ){
            ll m = s + (e-s)/2;
            
            if( isPossible( m, time, totalTrips ) ){
               // cout<<"got here"<<endl;
                ans = min( ans, m );
                e = m-1;
            }
            else{
              //  cout<<"else here"<<endl;
                s = m+1;
            }
        }
        
        return ans;
    }
};