class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map< double, long long> mp;
        for( int i = 0 ; i < rectangles.size() ; i++ ){
            double r = double(rectangles[i][0])/ rectangles[i][1];
            
            mp[r]++;
        }
        
        long long ans =0;
        
        for( auto i : mp ){
            long long curr = i.second;
            ans += ( (curr * (curr-1) ) / 2 );
        }
        
        return ans;
    }
};