class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if( n == 0 ){
            return true;
        }
        if( flowerbed.size() == 1 ){
            return ( (n == 1) && (flowerbed[0] == 0) );
        }
        
        for( int i = 0 ; i < flowerbed.size() ; i++ ){
            
            if( n == 0 ) return true;
            
            if( flowerbed[i] == 0 ){
                if( i == 0 ){
                    if( flowerbed[1] == 0 ){
                        n--;
                        flowerbed[i] = 1;
                    }
                }
                else if( i == flowerbed.size() - 1 ){
                    if( flowerbed[i-1] == 0 ){
                        n--;
                        flowerbed[i] = 1;
                    }
                }
                else{
                    if( (flowerbed[i-1] == 0) && (flowerbed[i+1] == 0) ){
                        n--;
                        flowerbed[i] = 1;
                    }
                }
            }
        }
        
        return ( n == 0 );
    }
};