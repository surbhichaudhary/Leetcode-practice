class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end() );
        
        int n = piles.size(), ans = 0, i=0, j = n-1;
        while( i < j ){
            ans+= piles[j-1];
            j-=2;
            i++;
        }
        return ans;
    }
};