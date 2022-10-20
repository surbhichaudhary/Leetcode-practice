class Solution {
public:
    int countPalindromicSubsequence(string& s) {
//         unordered_map< char, int > mp; 
//         set<char> st;
//         unordered_map<string, int> pal;
//         int n = s.length(), ans = 0;
        
//         for( int i= n -1 ; i > 0 ; i-- ){// O(n)
//             mp[s[i]]++;
//         }
        
//         st.insert(s[0]);
//         for( int i = 1 ; i < n-1 ; i++ ){ //O(n)
            
//             for( int j = 0 ; j < 26 ; j++ ) { //O(26)
//                 char c = 'a' + j;
//                 if( st.find(c) != st.end() &&
//                   ( (s[i] == c && mp[c] > 1) || ( s[i] != c && mp.count(c) ) )){
//                     string p = "";
//                     p += c;
//                     p += s[i];
//                     p += c;
//                     //cout<<p<<endl;
//                     pal[p]++;
//                 } 
//             }
            
//             mp[s[i]]--;
//             st.insert(s[i]);
//             if( mp[s[i]] == 0 ){
//                 mp.erase(s[i]);
//             }
//         }
//         return pal.size();
        
        vector<pair<int, int>> startsAndEnds(26, {-1,-1});
        int n = s.size();
        //finding out the start and end points
        for(int i = 0; i<n; i++) {
            auto& [start, end] = startsAndEnds[s[i] - 'a'];
            if(start == -1) start = i;
            else end = i;
        }
        //calculating number of palindromes
        int cnt = 0;
        for(int i = 0; i<26; i++) {
            //get its start and end
            auto [start, end] = startsAndEnds[i];
            unordered_set<char> st;
            for(int j = start + 1; j<end; j++) {
                st.insert(s[j]);
            }
            cnt += st.size();
        }
        return cnt;
    } 
};