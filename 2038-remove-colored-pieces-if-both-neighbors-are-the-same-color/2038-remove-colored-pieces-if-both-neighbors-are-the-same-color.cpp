class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size(), a =0 , b = 0 ;
        
        for( int i = 0 ; i < n - 2 ;  ){
               // check removable count of alice
               if(colors[i] == 'A' && colors[i+1] == 'A' ){  
                   int j = i+2;
                   while( j < n && colors[j] == 'A' ){
                       a++;
                       j++;
                   }
                   i = j;
               }
               // check removable count of bob
               else if(colors[i] == 'B' && colors[i+1] == 'B' ) { 
                   int j = i+2;
                   while( j < n && colors[j] == 'B' ){
                       b++;
                       j++;
                   } 
                   i = j;
               }
            else{
                i++;
            }
        }
        
        return ( a > b );
        
    }
};

