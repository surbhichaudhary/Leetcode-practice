struct bloom{
    int plant;
    int grow;
};

class Solution {
public:
    
    static bool comp( bloom a, bloom b ){
        if( a.grow == b.grow ){
            return a.plant > b.plant ;
        }
        return a.grow > b.grow;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size(), p = 0 , g = 0 ;
        vector<bloom> seed(n);
        
        for( int i = 0 ; i < n ; i++ ){
            seed[i].plant = plantTime[i];
            seed[i].grow = growTime[i];
        }
        
        sort( seed.begin(), seed.end(), comp );
        
        for( int i = 0 ; i < n ; i++ ){
            p += seed[i].plant;
            g = max( g, p+seed[i].grow );
        }
        
        return g;
    }
};