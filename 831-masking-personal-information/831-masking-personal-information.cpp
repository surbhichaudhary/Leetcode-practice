class Solution {
public:
    string maskPII(string s) {
        string ans="";
        //email
        if( isalpha(s[0]) ){
            s[0] = tolower(s[0]);
            ans.push_back(s[0]);
            int i = 1;
            while( s[i] != '@' ){
                i++;
            }
            if( i > 1 ){
                for(int j = 1 ; j<= 5; j++ ){
                    ans.push_back('*');
                }
                s[i-1] = tolower(s[i-1]);
                ans.push_back(s[i-1]);
            }
            while( i < s.length() ){
                s[i] = tolower(s[i]);
                ans.push_back( s[i] );
                i++;
            }
        }
        //phone number
        else{
            int i = s.length()-1, c=0;
            stack<char> stk;
            string mid = "***-***-";
            
            while( i >= 0 && stk.size() < 10 ){ 
                if( isdigit( s[i] ) ){
                    stk.push(s[i]);
                } 
                i--;
            }
            //forming the XXXX part
            while( stk.size() > 4 ){
                stk.pop();
            }
            while( !stk.empty() ){
                mid.push_back(stk.top());
                stk.pop();
            }
            if( i < 0 ){ // no country code
                return mid;
            }
            //examining the country code;
            while( i >= 0 ){
                if(isdigit(s[i]) ){
                    c++;
                }
                i--;
            }
            
            if( c == 1 ){ // 1 digit country code
                ans = "+*-";
            }
            else if( c == 2 ){ // 2 digit country code
                ans = "+**-";
            }
            else if( c == 3 ){ // 3 digit country code
                ans = "+***-";
            }
            ans += mid;
        }
        return ans;
    }
};