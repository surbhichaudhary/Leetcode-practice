class Solution {
public:
    string arrangeWords(string text) {
        if( text.length() < 3 ){
            return text;
        }
        
        map< int, vector<string> > mp;
        
        int i =0, n = text.length(), ind=1;
        
        while( i < n ){
            int j = i;
            if( isupper( text[i] ) ){
                text[i] = tolower(text[i]);
            }
            string curr = "";
            while( j < n && text[j] != 32 ){
                curr.push_back(text[j]);
                j++;
            }
            mp[j-i].push_back(curr);
            i = j+1;
        }
        
        string ans = "";
        for( auto i : mp ){
            for( auto j : i.second ){
                ans += j;
                ans.push_back(' ');
            }
        }
        
        ans[0] = toupper(ans[0]);
        ans.pop_back();
        return ans;
    }
};