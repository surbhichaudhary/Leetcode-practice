class Solution {
public:
    bool rotateString(string s, string goal) {
        if( s.length() != goal.length() ){
            return false;
        }
        if( s.length() == 0 ){
            return true;
        }
        
        s += s;
        if( s.find(goal) != string::npos )
            return true;
        
        return false;
    }
};