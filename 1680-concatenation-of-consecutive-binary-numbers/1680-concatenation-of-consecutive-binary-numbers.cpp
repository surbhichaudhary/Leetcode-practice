#define m 1000000007

class Solution {
public:
    
    string DecimalToBinary(int num){
        string str="";
        while(num){
            if(num & 1) // 1
                str+='1';
            else // 0
                str+='0';
            num>>=1; // Right Shift by 1 
        }   
        return str;
    }
    
    int concatenatedBinary(int n) {
        long long ans = 0;
        
        for( int i = 1 ; i <= n ; i++ ){
            string curr = DecimalToBinary(i);
            for( int c = curr.length()-1 ; c >= 0  ; c-- ){
                int val = curr[c] == '0' ? 0 : 1;
                ans = ((ans*2)%m + val )%m;
            }
        }
        
        return ans;
    }
};
