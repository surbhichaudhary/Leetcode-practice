class FindSumPairs {
public:
    
    vector<int> a1;
    unordered_map<int, int> mp1;
    vector<int> a2;
    unordered_map<int, int> mp2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        //O(max(n,m));
        for(int i = 0; i< nums1.size() ; i++ ){
            mp1[nums1[i]]++;
            a1.emplace_back(nums1[i]);
        }
        
        for(int i = 0; i< nums2.size() ; i++ ){
            mp2[nums2[i]]++;
            a2.emplace_back(nums2[i]);
        }
    }
    
    void add(int index, int val) {
        //O(1);
        int prev = a2[index];
        mp2[prev]--;
        if( mp2[prev] == 0 ){
            mp2.erase(prev);
        }
        
        a2[index] += val;
        mp2[a2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        //O( n*logm)
        for( auto i : mp1 ){
            int v2 = tot - i.first;
            if( mp2.count( v2 ) ){
                ans += ( i.second * mp2[v2] );
            }
        }
        
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */