class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1;
        set<int> s2;
        set<int> s3;
        
        for( int i = 0 ; i < nums1.size() ; i++ ){
            s1.insert(nums1[i]);
        }
        for( int i = 0 ; i < nums2.size() ; i++ ){
            s2.insert(nums2[i]);
        }
        for( int i = 0 ; i < nums3.size() ; i++ ){
            s3.insert(nums3[i]);
        }
        
        unordered_map<int, int>mp;
        
        for( auto i : s1 ){
            mp[i]++;
        }
        for( auto i : s2 ){
            mp[i]++;
        }
        for( auto i : s3 ){
            mp[i]++;
        }
        
        vector<int> ans;
        for( auto i : mp ){
            if( i.second >= 2 ){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};