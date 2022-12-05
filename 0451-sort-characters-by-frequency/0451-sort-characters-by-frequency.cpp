#include<unordered_map>
#include<algorithm>
#include<queue>

string repeat(char s, int n)
{
    string s1 = "";
    s1.push_back(s);
    for ( int i = 1 ; i < n ; i++ )
        s1.push_back(s); 
    return s1;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for( int  i = 0 ; i < s.length() ; i++ ){
            mp[s[i]]++;
        }
        string ans = "";
        priority_queue<pair<int,char>> p;
        for( auto i: mp ){
            p.push({i.second,i.first});//int,char
        }
        while( !p.empty() ){
            ans += repeat(p.top().second, p.top().first);
            p.pop();
        }
        return ans;
    }
};