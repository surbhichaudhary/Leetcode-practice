class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for( int i = 0 ; i < s.length() ; i++ ){
            mp[s[i]]++;
        }
        
        string ans = "";
        for( int i = 0; i< order.length() ; i++ ){
            if( mp.count( order[i] ) ){
                while( mp[order[i]] > 0 ){
                    ans.push_back(order[i]);
                    mp[order[i]]--;
                }
                mp.erase(order[i]);
            }
        }
        for( auto i : mp ){
            for( int j = 0; j < i.second ; j++ ){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};