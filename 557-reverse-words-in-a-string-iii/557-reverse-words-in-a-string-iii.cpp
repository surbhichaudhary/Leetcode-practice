class Solution {
public:
    string reverseWords(string s) {
        int i=0, n = s.length();
        while( i<n ){
            int j = i;
            while( j<n && s[j] != 32 ){
                j++;
            }
            //cout<<j<<endl;
            int k = j-1;
            while( i<k ){
                char c = s[i];
                s[i] = s[k];
                s[k] = c;
                i++;
                k--;
            }
            i = j+1;
        }
        return s;
    }
};