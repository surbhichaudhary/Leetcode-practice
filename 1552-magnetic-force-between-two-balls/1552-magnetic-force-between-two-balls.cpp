class Solution {
public:
    
    bool isPossible( int dist, int ball, vector<int>& position ){
        int c = 1, n = position.size(), lp = position[0];
        
        for( int i = 1 ; i < n ; i++ ){
            if( position[i] - lp >= dist ){
                c++;
                lp = position[i];
            }
            if( c >= ball ){
                return true;
            }
        }
        
        return ( c >= ball );
        
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort( position.begin(), position.end() );
        int n = position.size(), s = 0, e = position[n-1]-position[0] ;
        
        while( s < e ){
            int dist = s + ( e-s+1 )/2;
            if( isPossible( dist, m, position ) ){
                s = dist;
            }
            else{
                e = dist-1;
            }
        }
        return s;
    }
};