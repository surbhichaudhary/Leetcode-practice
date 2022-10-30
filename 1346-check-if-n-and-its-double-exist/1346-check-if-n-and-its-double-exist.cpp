class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();
        for( int i = 0 ; i< n ; i++ ){
            int t = 2*arr[i];
           
            if( mp.count(t) || (arr[i]% 2 == 0 && mp.count(arr[i]/2) ) ){
                return true;
            }
            mp[arr[i]]++;
        }
        
        return false;
        
    }
};