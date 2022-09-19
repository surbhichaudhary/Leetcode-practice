class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        
        for( int i = 0 ; i < l ; i++ ){
            if( n == 0 ){
                return true;
            }
            if( flowerbed[i] == 0 ){
                if( ( i == 0 && ( l == 1 || flowerbed[1] == 0 ) ) || 
                    ( i > 1 && i == l-1 && flowerbed[i-1] == 0 ) ){
                        flowerbed[i] = 1;
                        n--;
                }
                else{
                    if( i > 0 && i < l-1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 ){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
        }
        
        return ( n <= 0 );
    }
};