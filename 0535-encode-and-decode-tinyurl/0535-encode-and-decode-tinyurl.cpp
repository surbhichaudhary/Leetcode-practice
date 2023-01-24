class Solution {
public:

    unordered_map< string, string > enc;
    unordered_map< string, string > dec;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if( !enc.count(longUrl) ){
            string curr = to_string( 1 + enc.size() );
            enc[longUrl] = curr;
            dec[curr] = longUrl;
        }
        return enc[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dec[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));