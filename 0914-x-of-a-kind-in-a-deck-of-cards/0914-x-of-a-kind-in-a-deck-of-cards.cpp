class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        int g = -1;
        
        for( int i = 0 ; i < deck.size() ; i++ ){
            mp[deck[i]]++;
        }
        
        for( auto i : mp ){
            if( i.second > 0 ){
                if( g == -1 ){
                    g = i.second;
                }
                else{
                    g = __gcd( g, i.second );
                }
            }
        }
        return (g >= 2) ;
    }
};