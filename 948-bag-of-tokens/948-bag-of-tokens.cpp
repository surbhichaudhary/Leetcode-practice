class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort( tokens.begin(), tokens.end() );
        
        int i =0 , j= tokens.size() - 1, sc=0;
        while( i<=j ){
            if( power >= tokens[i] ){
                power -= tokens[i++];
                sc++;
            }
            else{ 
                if( sc > 0 && i != j && power + tokens[j] >= tokens[i] ){
                    power += tokens[j--];
                    sc--;
                }
                else{
                    break;
                }
            }
        }  
        return sc;
    }
};