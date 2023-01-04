class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        int n = tasks.size(), ans = 0;
        unordered_map<int, int> mp;
        
        for( int i = 0 ; i < n ; i++ )
        {
            mp[tasks[i]]++;
        }
        for( auto i : mp )
        {
            int f = i.second;
            if( f == 1 )
                return -1;
            if( f==2 )
                ans++;
            if( f==3 )
                ans++;
            if( f>=4 ){
                int a = f/3;
                int r = f - 3*a;
                if( r==0 )
                    ans += a;
                if( r==1 || r==2)
                    ans += (a+1);
            }
        }
        return ans;
    }
};