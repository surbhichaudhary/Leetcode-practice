class Solution {
public:
    int addDigits(int num) {
        if( num < 10 ){
            return num;
        }
        
        int s = 0;
        while( num > 0 ){
            int r = num%10;
            s += r;
            num /= 10;
        }
        
        return addDigits(s);
    }
};