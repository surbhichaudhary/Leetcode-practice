class Solution {
public:
    
    vector<int> ori;
    
    Solution(vector<int>& nums) {
        ori = nums;
    }
    
    vector<int> reset() {
        return ori;
    }
    
    vector<int> shuffle() {
        vector<int> ans;
        vector<int> tmp = ori;
        
        while( tmp.size() > 0 ){
            int n = tmp.size();
            int r = rand()%n;
            
            swap( tmp[r], tmp[n-1] );
            ans.push_back(tmp[n-1]);
            
            tmp.pop_back();
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */