class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0, n = s.length(), r = 1;
        while( i < n ){
            int j = min( n, i+k );
            if( r == 1 ){
                int l = j-1;
                while( i<l ){
                    char c = s[i];
                    s[i] = s[l];
                    s[l] = c;
                    i++;
                    l--;
                }
            }
            i=j;
            r = r^1;
        }
        return s;
    }
};
