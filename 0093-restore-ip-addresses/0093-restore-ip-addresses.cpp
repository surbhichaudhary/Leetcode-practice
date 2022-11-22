class Solution {
public:
    
    vector<string> ans;
    unordered_set<string> st;
    
    void solve( int i, int dc, string& in, string& s ){
        //base case
        int l = in.length();
        if( i >= s.length() ){
            if( dc != 3 ){
                return;
            }
            
            int j = 0 , n = in.length();
            while( j < n ){
                int k = j, num =0;
                while( k < n && in[k] != '.' ){
                    int v = in[k] - '0';
                    num *= 10;
                    num += v;
                    k++;
                }
                
                // invalid or leading zero
                if((num < 0) || (num > 255) || ((num != 0) && (in[j] == '0')) ){
                    return;
                }
         
                j = k+1;
            }
            
            if( st.find(in) == st.end() ){
                ans.push_back(in);
                st.insert(in);
            }
            
            return;
        }
        // calculate the last number
        in.push_back(s[i]);
        
        int v = 0, n = in.length() , j = n-1, k= n-1;
        while( (j >= 0) && (in[j] != '.') ){
            j--;
            k--;
        }
        
        j++;
        k++;
        
        while( j < n ){
            int c = in[j] - '0';
            v *= 10;
            v += c;
            j++;
        }
        
        if( (v > 255) || ( (in[k] == '0') && (v != 0) ) || (v == 0 && n-k > 1) ){
            in.pop_back();
        }
   
        else{
            solve( i+1, dc, in, s );
            in.pop_back();
        }
        
        if( (dc < 3) && (l > 0) && ( in[l-1] != '.' ) ){
            in.push_back('.');
            solve( i, dc+1, in, s );
            in.pop_back();
        }
        
    }
    
    vector<string> restoreIpAddresses(string& s) {
        ans.clear();
        st.clear();
        string in = "";
        
        solve( 0, 0, in, s );
        
        return ans;
    }
};
