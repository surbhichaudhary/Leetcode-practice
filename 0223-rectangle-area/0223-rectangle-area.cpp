class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aa = ( ax2 - ax1 ) * ( ay2 - ay1 );
        int ba = ( bx2 - bx1 ) * ( by2 - by1 );
        
        int l = max( ax1, bx1 ), r = min( ax2, bx2 );
        int b = max( ay1, by1 ), t = min( ay2, by2 );
        
        int xo = r-l, yo = t-b;
        
        int ao = 0;
        if( (xo > 0) && (yo > 0) ){
            ao = xo*yo;
        }
        
        int area = aa + ba - ao;
        return area;
    }
};
