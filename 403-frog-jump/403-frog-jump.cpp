class Solution {
public:
    
    unordered_map<string, bool> t;
    
    bool solve( int jmp ,int curr, int lp, unordered_map<int,int>& mp, int& val ){
        if( curr == val ){
            return true;
        }
        if( !mp.count(curr) || mp[curr] <= lp ){
            return false;
        }
        
        string s = to_string(jmp);
        s.push_back('_');
        s += to_string(curr);
        s.push_back('_');
        s += to_string(lp);
        
        if( t.count(s) ){
            return t[s];
        }
        return ( t[s] = solve( jmp-1, curr + jmp -1 , mp[curr], mp, val ) ||
                        solve( jmp, curr + jmp , mp[curr], mp, val ) ||
                        solve( jmp+1, curr + jmp + 1 , mp[curr], mp, val ) );
    }
    
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mp;
        for( int i = 0 ; i < stones.size() ; i++ ){
            mp[stones[i]] = i;
        }
        
        t.clear();
        return solve( 1, stones[0] + 1, 0, mp, stones[stones.size()-1] );
    }
};