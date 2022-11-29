struct item{
    int val, lab;
};

class Solution {
public:
    
    static bool comp( item& a, item& b ){
        return a.val > b.val ;
    }
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, 
                              int useLimit) {
        
        int n = values.size(), ans = 0, c =0;
        vector<item> nums(n);
        
        for( int i =0 ; i< n ;i++ ){
            nums[i].val = values[i];
            nums[i].lab = labels[i];
        }
        
        unordered_map< int, int> mp; 
        sort( nums.begin(), nums.end(), comp );
        
        for( int i =0 ; i< n && c < numWanted ; i++ ){
            if( !mp.count( nums[i].lab ) || mp[ nums[i].lab ] < useLimit ){
                ans += nums[i].val;
                mp[nums[i].lab]++;
                c++;
            }
        }
        
        return ans;
    }
};

