class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> fact;
        int m = n/2;
        
        for( int i = 1 ; i <= m ; i++ ){
            if( n%i == 0 ){
                fact.push_back( i );
            }
        }
        fact.push_back(n);
        
        if( fact.size() < k ){
            return ( -1 );
        }
        return fact[k-1];
    }
};