class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        //to keep account of players who played
        set<int> players;
        //winners count
        unordered_map<int, int> win;
        //losers count
        unordered_map<int, int> lost;
        
        for( int i = 0 ; i < matches.size() ; i++ ){
            int w = matches[i][0], l = matches[i][1];
            
            players.insert(w);
            players.insert(l);
            
            win[w]++;
            lost[l]++;
        }
        
        vector<vector<int>> ans(2);
        for( auto i : players ){
            if( win.count(i) && !lost.count(i) ){
                ans[0].push_back(i);
            }
            
            else if( (lost.count(i)) && (lost[i] == 1 ) ){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};