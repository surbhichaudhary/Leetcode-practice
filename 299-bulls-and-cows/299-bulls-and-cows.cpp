class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        int n = secret.length(), b= 0, c=0;
        
        for( int i = 0; i< n ;i++ ){
            mp[secret[i]]++;
        }
        for( int i=0; i< n ;i++ ){
            if( secret[i] == guess[i] ){
                b++;
                mp[guess[i]]--;
                if( mp[guess[i]] == 0 ){
                    mp.erase(guess[i]);
                }
            }
        }
        for( int i =0 ; i< n ;i++ ){
            if( guess[i] != secret[i] && mp.count(guess[i]) ){
                c++;
                mp[guess[i]]--;
                if( mp[guess[i]] == 0 ){
                    mp.erase(guess[i]);
                }
            }
        }
        
        string ans = to_string(b);
        ans.push_back('A');
        ans += to_string(c);
        ans.push_back('B');
        
        return ans;
    }
};