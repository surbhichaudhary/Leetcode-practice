class Solution {
public:
    int minSwaps(string& s) {
        int o =0 , c=0, n = s.length(), sw=0;
        vector<int> open;
        
        for( int i = 0 ; i < n ;i++ ){
            if( s[i] == '[' ){
                open.push_back(i);
            }
        }
        
        for( int i =0 ; i < n ; i++ ){
            if( s[i] == '[' ){
                o++;
            }
            else{
                c++;
                if( c > o ){
                    int l = open.size(), ind = open[l-1];
                    open.pop_back();

                    sw++;
                
                    s[i] = '[';
                    c--;
                    o++;
                    s[ind] = ']';
                }
            }
        }
        return sw;
    }
};