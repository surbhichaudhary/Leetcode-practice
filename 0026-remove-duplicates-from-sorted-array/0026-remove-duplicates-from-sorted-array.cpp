class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0, j=0, n = nums.size();
        while( i<n && j<n ){
            while( j < n && nums[j] == nums[i] ){
                j++;
            }
            if( j < n ){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};