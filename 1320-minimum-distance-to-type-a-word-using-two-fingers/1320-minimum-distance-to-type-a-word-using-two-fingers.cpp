typedef pair<int, int> pi;
typedef pair<pi, pi> pos;

class Solution {
public:
    
    unordered_map< char, pi > mp;
    //position of f1, position of f2, index of word
    unordered_map< string, int> dp;
    pi null = {-1, -1};
    
    int solve( pi f1, pi f2, int i, string& word ){
        if( i>= word.length() ){
            return 0;
        }
        
        string curr = to_string( f1.first ) + to_string( f1.second ) + to_string( f2.first ) + 
            to_string( f2.second ) + to_string( i );
        if( dp.count(curr) ){
            return dp[curr];
        }
        //else find dp[curr]
        int ans = INT_MAX, d=0;
        //case 1 - I put f1 at i
        if( f1 != null ){
            d = abs( f1.first - mp[word[i]].first ) + abs( f1.second - mp[word[i]].second );
        }
        ans = min( ans, d + solve( mp[word[i]], f2, i+1, word ) );
        //case 2 - I put f2 at i;
        d = 0 ;
        if( f2 != null ){
            d = abs( f2.first - mp[word[i]].first ) + abs( f2.second - mp[word[i]].second );
        }
        ans = min( ans, d + solve( f1, mp[word[i]], i+1, word ) );
        
        return dp[curr] = ans;
    }
    
    
    int minimumDistance(string word) {
        mp['A'] = {0,0} ;   mp['B'] = {0,1};
        mp['C'] = {0,2} ;   mp['D'] = {0,3};
        mp['E'] = {0,4} ;   mp['F'] = {0,5};
        mp['G'] = {1,0} ;   mp['H'] = {1,1};
        mp['I'] = {1,2} ;   mp['J'] = {1,3};
        mp['K'] = {1,4} ;   mp['L'] = {1,5};
        mp['M'] = {2,0} ;   mp['N'] = {2,1};
        mp['O'] = {2,2} ;   mp['P'] = {2,3};
        mp['Q'] = {2,4} ;   mp['R'] = {2,5};
        mp['S'] = {3,0} ;   mp['T'] = {3,1};
        mp['U'] = {3,2} ;   mp['V'] = {3,3};
        mp['W'] = {3,4} ;   mp['X'] = {3,5};
        mp['Y'] = {4,0} ;   mp['Z'] = {4,1};
        
        dp.clear();
        
        return solve( null, null, 0, word );
    }
};