class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue< double > pq;
        double s = 0.0, h = 0.0, r = 0.0;
        int n = nums.size(), ans =0;
        
        for( int i =0 ;i < n ;i++ ){
            s += nums[i];
            pq.push(double(nums[i]));
        }
        
        h = s/2.0;
        r = s;
        
        while( r > h ){
            double tp = pq.top();
            pq.pop();
            double sub = tp/2.0;
            ans++;
            r -= sub;
            pq.push(sub);
        }
        
        return ans;
    }
};