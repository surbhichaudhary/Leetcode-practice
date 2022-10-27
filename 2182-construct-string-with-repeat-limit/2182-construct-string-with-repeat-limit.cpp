class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        for( int  i =0 ; i < s.length(); i++ ){
            mp[s[i]]++;
        }
        
        priority_queue< pair<char, int>> pq;
        for( auto i: mp ){
            pq.push({ i.first, i.second });
        }
        
        string ans = "";
        while( !pq.empty() ){
            pair<char, int> tp = pq.top();
            pq.pop();
            int f = tp.second, c = 0, l = ans.length();
            if( l > 0 && ans[l-1] == tp.first ){
                c = 1;
            }
            
            while( f > 0 && c < repeatLimit ){
                ans += tp.first;
                f--;
                c++;
            }
            if( !pq.empty() ){
                pair<char, int> tp2 = pq.top();
                pq.pop();
                ans += tp2.first;

                if( f > 0 ){
                    pq.push({ tp.first, f });
                }
                if( tp2.second > 1 ){
                    pq.push({tp2.first, tp2.second -1 });
                }
            } 
        }
        
        return ans;
    }
};