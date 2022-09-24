class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string , int> mp;
        for( int i = 0 ; i < cpdomains.size() ; i++ ){
            int n=0, j=0;
            string cur = cpdomains[i];
            
            while( j < cur.length() && cur[j] != 32 && isdigit( cur[j]) ) {
                n = n*10 + (cur[j]-'0');
                j++;
            }
            j++;
            cur = cur.substr(j);
            mp[cur] += n;
            
            while( cur.length() > 0 ){
                j = 0;
                while( j < cur.length() && cur[j] != '.' ){
                    j++;
                }
                j++;
                if( j >= cur.length() ){
                    break;
                }
                cur = cur.substr(j);
                mp[cur] += n;
            }
        }
        
        vector<string> ans;
        for( auto i : mp ){
            string cur = to_string(i.second);
            cur.push_back(' ');
            cur += i.first;
            
            ans.push_back(cur);
        }
        
        return ans;
    }
};