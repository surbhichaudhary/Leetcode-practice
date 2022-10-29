class Solution {
public:
  
    int solve( string& a ){
        int state = 0 ;
        for( int i = 0 ; i < a.length() ; i++ ){
            int ind = a[i] - 'a';
            state |= (1<<ind);
        }
        return state;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans =0 ;
        vector<int> state(n);
        
        for( int i = 0 ; i < n ; i++ ){ 
            state[i] = solve( words[i] );
        }
        
        for( int i = 0 ; i < n ; i++ ){ // O( n^2)
            for( int j = i+1 ; j < n ; j++ ){
                if( (state[i] & state[j]) == 0 ){
                    int curr = words[i].length() * words[j].length();
                    ans = max( ans, curr );
                }
            }
        }
        
        return ans;
    }
};