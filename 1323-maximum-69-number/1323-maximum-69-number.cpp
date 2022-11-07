class Solution {
public:
    int maximum69Number (int n) {
        vector<int> nums;

        while( n > 0 ){
            int r = n%10;
            nums.push_back(r);
            n /= 10;
        }
        
        int i = nums.size()-1, p=0;
        while( i>=0 && nums[i] != 6 ){
            i--;
        }
        if( i>=0 ){
            nums[i] = 9;
        }
        
        for( int i= nums.size() -1 ; i >= 0 ; i-- ){
            p = p*10 + nums[i];
        }
        return p;
    }
};