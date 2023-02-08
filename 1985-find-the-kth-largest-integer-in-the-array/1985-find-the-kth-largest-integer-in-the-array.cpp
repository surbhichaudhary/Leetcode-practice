class Solution {
public:
    
    static bool comp( string a, string b ){
        if( a.length() == b.length() ){
            return ( a<b );
        }
        return ( a.length() < b.length() ); 
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size(), req = n-k, curr = 0;
        sort( nums.begin(), nums.end(), comp );
        return nums[req];
        
//         map< int, vector<string> > mp;
 
//         for( int i = 0 ;i < n ; i++ ){
//             int c = nums[i].length();
//             mp[c].push_back(nums[i]);
//         }
        
//         for( auto i : mp ){
//             int l = (i.second).size();
//             if( ( curr + l ) >= req ){
//                 // work here
//                 sort( (i.second).begin(), (i.second).end(), comp );
//                 return (i.second)[req-curr];
//             }
//             else{
//                 curr += l; 
//             }
//         }
        
//         return nums[0];
    }
};