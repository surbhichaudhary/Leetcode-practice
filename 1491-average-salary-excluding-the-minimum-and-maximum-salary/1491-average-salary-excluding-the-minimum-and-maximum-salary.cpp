class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), mn = INT_MAX, mx = 0;
        
        for( int i =0 ; i < n ; i++ ){
            mn = min( mn, salary[i] );
            mx = max( mx, salary[i] );
        }
        
        double sal = 0.0, c = 0.0;
        for( int i =0 ; i < n ; i++ ){
            if( (salary[i] != mn) && (salary[i] != mx) ){
                sal += salary[i];
                c += 1.0;
            }
        }
        
        return ( sal/c);
        
    }
};