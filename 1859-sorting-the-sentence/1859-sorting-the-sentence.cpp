class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int, string> mp;
        int i = 0, n = s.length();
        while( i < n ){
            
            while( s[i] == 32 ){
                i++;
            }
            
            int j = i;
            string curr = "";
            while( j < n && !isdigit(s[j]) ){
                curr += s[j];
                j++;
            }
            int v = s[j] - '0';
            mp[v] = curr;
            i = j+1;
        }
        
        string ans = "";
        for( int i = 1 ; i < n ; i++ ){
            if( !mp.count(i) ){
                break;
            }
            ans += mp[i];
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};