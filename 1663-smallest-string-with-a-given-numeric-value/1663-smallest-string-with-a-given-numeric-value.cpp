class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        int val = 26;
        
        while( n>0 && k>0 && val > 0 ){
            if( n-1 + val <= k ){
                char ch = 'a' + val-1;
                ans.push_back( ch );
                k -= val;
                n--;
            }
            else{
                val--;
            }
        }
        
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};