class Solution {
public:
    string reverseWords(string& s) {
        int i =0 , j=0, n  =s.length();
        
        while( (i < n) && (s[i] == 32) ){
            i++;
        }
        s = s.substr(i);
        
        while( s.back() == 32 ){
            s.pop_back();
        }
        
        reverse(s.begin(), s.end());
        //cout<<s<<endl;
        
        i =0 ,n = s.length();
        while( i < n ){
            if( s[i] == 32 ){
                i++;
            }
            //extra spaces
            if( s[i] == 32 ){
                j = i;
                while( (j< n) && (s[j] == 32) ){
                    j++;
                }
                
                s = s.substr(0, i) + s.substr(j);
            }
            n = s.length();
            j = i;
            while( (j < n) && (s[j] != 32) ){
                j++;
            }
            
            int l = j-1;
            while( i < l ){
                char c = s[i];
                s[i++] = s[l];
                s[l--] = c;
            }
            i = j;
            
        }
        
        return s;
        
    }
};