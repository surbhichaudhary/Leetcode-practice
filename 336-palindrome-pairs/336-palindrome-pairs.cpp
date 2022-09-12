class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int wordSize = words.size();
        vector<string> reversedWords(wordSize);
        for (int i = 0; i < wordSize; i++) {
            string s = words[i];
            std::reverse(s.begin(), s.end());
            reversedWords[i] = s;
            reversedWordToIndex[reversedWords[i]] = i;
        }
        
        // "" matches with every word if the word is palindrome
        const auto itEmpty = reversedWordToIndex.find("");
        if (itEmpty != reversedWordToIndex.end()) {
            const int emptyIndex = itEmpty->second;
            for (int i = 0; i < wordSize; i++) {
                if (i == emptyIndex) continue;
                const string &word = words[i];
                const int wordLen = word.length();
                if (!isPalindrome(word, 0, wordLen - 1)) continue;
                results.emplace_back(vector<int>{emptyIndex, i});
                results.emplace_back(vector<int>{i, emptyIndex});
            }
        }
        
        for (int i = 0; i < wordSize; i++) {
            const string &word = words[i];
            const int wordLen = word.length();
            
            // Check if substr(word, sublen) from left == reversedWord
            for (int sublen = 1; sublen < wordLen; sublen++) {
                const int matchIndex = findLeftSubstrMatchIndex(word, sublen);
                if (matchIndex < 0 || matchIndex == i) continue;
                results.emplace_back(vector<int>{i, matchIndex});
            }
            
            // Check if substr(word, sublen) from right == reversedWord
            for (int sublen = 1; sublen < wordLen; sublen++) {
                const int matchIndex = findRightSubstrMatchIndex(word, sublen);
                if (matchIndex < 0 || matchIndex == i) continue;
                results.emplace_back(vector<int>{matchIndex, i});
            }
            
            // Check if word == reversedWord
            const int matchIndex = findLeftSubstrMatchIndex(word, wordLen);
            if (matchIndex < 0 || matchIndex >= i) continue; // matchIndex >= i is to avoid duplicate pairs, matchIndex <= i would also be okay
            results.emplace_back(vector<int>{i, matchIndex});
            results.emplace_back(vector<int>{matchIndex, i});
        }
        return results;
    }
    
    // words=["batx", "tab"]
    // reversed=["xtab", "bat"]
    // substr(word="batx", sublen=3) = "bat"
    int findLeftSubstrMatchIndex(const string &word, const int sublen) {
        const string_view part(word.c_str(), sublen);
        const auto it = reversedWordToIndex.find(part);
        if (it == reversedWordToIndex.end()) return -1;
        if (isPalindrome(word, sublen, word.length() - 1)) return it->second;
        return -1;
    }
    
    // words=["tabx", "bat"]
    // reversed=["xtab", "tab"]
    // substr(word="xtab", sublen=3) = "tab"
    int findRightSubstrMatchIndex(const string &word, const int sublen) {
        const string_view part(word.c_str() + word.length() - sublen);
        const auto it = reversedWordToIndex.find(part);
        if (it == reversedWordToIndex.end()) return -1;
        if (isPalindrome(word, 0, word.length() - sublen - 1)) return it->second;
        return -1;
    }
    
    bool isPalindrome(const string &word, int left, int right) {
        while (left < right && word[left] == word[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
    
    unordered_map<string_view, int> reversedWordToIndex;
    vector<vector<int>> results;
};


// class Solution {
// public:
    
//     bool isPal( string& s, int i, int j ){
//         while( i < j ){
//             if( s[i] != s[j] ){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
    
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         unordered_map<string, int> mp;
//         vector<vector<int>> ans;
//         string emp = "";
//         bool pr = false;
        
//         for( int i = 0 ; i < words.size() ; i++ ){ //O(n);
//             mp[words[i]] = i;
//             if( words[i].length() == 0 ){
//                 pr = true;
//             }
//         }
//         //when reverse of string exists
//         for( int i = 0 ; i < words.size() ; i++ ){ // O(n*k);
//             string tmp = "";
//             for( int j = words[i].length() -1 ; j >= 0 ; j-- ){
//                 tmp.push_back(words[i][j]);
//             }
            
//             if( mp.count(tmp) && mp[tmp] != i ){ //O(log(n));
//                 ans.emplace_back(vector<int>{ i, mp[tmp] });
//             }
//         }
//         //when string is palindrome
//         if( pr ){
//             for( int i = 0 ; i < words.size() ; i++ ){ //O(n*k);
//                 if( i != mp[emp] && isPal( words[i], 0, words[i].length() - 1 ) ){
//                     ans.emplace_back( vector<int>{ mp[emp], i } );
//                     ans.emplace_back( vector<int>{ i, mp[emp] } );
//                 }
//             }
//         }
        
//         // combination is palindrome
//         for( int i = 0 ; i < words.size() ; i++ ){  //O(n * k * k);
//             for( int j = 1 ; j < words[i].length() ; j++ ){ //O(k)
//                 if( isPal(words[i], 0, j-1) ){ //O(k)
//                     string left = "";
//                     for( int x = words[i].length() -1 ; x >= j ; x-- ){
//                         left.push_back(words[i][x]);
//                     }
                    
//                     if( mp.count( left ) ){//O(log (n) )
//                         ans.emplace_back( vector<int>{ mp[left], i});
//                     }
                    
//                 }
//                 if( isPal( words[i], j, words[i].length() -1 ) ){//O(k)
//                     string left = "";
//                     for( int x = j -1 ; x >= 0 ; x-- ){
//                         left.push_back(words[i][x]);
//                     }
                    
//                     if( mp.count( left ) ){//O(log (n) )
//                         ans.emplace_back( vector<int>{ i, mp[left] } );
//                     }
                    
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

