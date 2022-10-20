class Solution {
public:
    
    unordered_map<int, string> mp;
    
    string solve( int n ){
        if( n < 0 ){
            return "";
        }
        if( mp.count(n) ){
            return mp[n];
        }
        else if( n >= 1000 ){
            return ( "M" + solve( n-1000 ));
        }
        else if( n >= 900 ){
            return ( "CM" + solve( n-900 )); 
        }
        else if( n >= 500 ){
            return ( "D" + solve( n-500 ));
        }
        else if( n >= 400 ){
            return ( "CD" + solve( n-400 ));
        }
        else if( n >= 100 ){
            return ( "C" + solve( n-100 )); 
        }
        else if( n >= 90 ){
            return ( "XC" + solve( n-90 ));
        }
        else if( n >= 50 ){
            return ( "L" + solve( n-50 ) );
        }
        else if( n >= 40 ){
            return ( "XL" + solve( n-40 )); 
        }
        else if( n >= 10 ){
            return ( "X" + solve( n-10 ));
        }
        else if( n >= 5 ){
            return ( "V" + solve( n-5 ));
        }
        string ans = "";
        for( int i = 1; i<= n ;i++ ){
            ans += mp[1];
        }
        return ans;
    }
    
    string intToRoman(int num) {
        mp[1]    = "I";
        mp[4]    = "IV";
        mp[5]    = "V";
        mp[9]    = "IX";
        mp[10]   = "X";
        mp[40]   = "XL";
        mp[50]   = "L";
        mp[90]   = "XC";
        mp[100]  = "C";
        mp[400]  = "CD";
        mp[500]  = "D";
        mp[900]  = "CM";
        mp[1000] = "M";
        
        return solve(num);
    }
    
};