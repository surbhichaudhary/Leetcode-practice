class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort( players.begin(), players.end() );
        sort( trainers.begin(), trainers.end() );
        
        int i = 0, j= 0, n1 = players.size(), n2 = trainers.size(), ans = 0;
        while( i < n1 && j <  n2 ){
            if( trainers[j] < players[i] ){
                j++;
            }
            else if( trainers[j] >= players[i] ){
                i++;
                j++;
                ans++;
            }
        }
        
        return ans;
    }
};