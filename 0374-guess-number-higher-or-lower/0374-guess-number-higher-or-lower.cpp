/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s =1, e = n, ans;
        while( s <= e ){
            int m = s + (e-s)/2;
            if( guess(m) == 0 ){
                ans = m;
                return m;
            }
            else if( guess(m) == -1 ){
                e = m-1;
            }
            else if ( guess(m) == 1 ){
                s = m+1;
            }
        }
        return ans;
    }
};