class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<int, int> mp;
        for( int i = 0 ; i < num.length() ; i++ ){
            int v = num[i] - '0';
            mp[v]++;
        }
        
        priority_queue< pair<int,int> > pq;
        int mx = INT_MIN, l = 0, j=0;
        
        for( auto i : mp ){
            if( i.second % 2 == 0 ){
                l += i.second;
                pq.push( { i.first, i.second } );
            }
            else{
                if( i.second - 1 > 0 ){
                    l += (i.second-1);
                    pq.push( { i.first, i.second-1 } );
                }
                mx = max( mx, i.first );
            }
        }
        string ans;
        if( mx > INT_MIN ){
            ans.append( l+1, '0');
        }
        else{
            ans.append( l, '0');
            l--;
        }
        
        while( !pq.empty() && j < l ){
            pair<int,int> tp = pq.top();
            pq.pop();
            char ch = tp.first + '0';
            int f = tp.second;
            
            while( f > 0 ){
                ans[j++] = (ch) ;
                ans[l--] = (ch) ;
                f -= 2;
            }
        }
        if( mx > INT_MIN && j == l){
            ans[j] = (mx+'0');
        }
        
        int i=0, n = ans.length();
        while( i < n && ans[i] == '0' ){
            i++;
        }
        n = n - 2*i ;
        ans = ans.substr(i, n );
        
        if( ans.length() == 0 ){
            return "0";
        }
        
        return ans;
    }
};