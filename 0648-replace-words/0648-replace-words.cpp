//typedef pair< bool, string > pbs;

class TrieNode{
    public:
    
    char data;
    TrieNode* child[26];
    bool isEnd;
    string str;

    TrieNode( char c ){
        data = c;
        isEnd = false;
        for( int i = 0 ; i < 26 ; i++ ){
            child[i] = NULL;
        }
    }
};

class Solution {
    
    TrieNode* root = new TrieNode('#');
    
    void insert(string& word) {
        TrieNode* curr = root;
        int i = 0 ;
        
        while( i < word.size() ){
            int ind = word[i]-'a';
            
            if( curr->child[ind] == NULL ){
                curr->child[ind] = new TrieNode( word[i] );
            }
            
            curr = curr->child[ind];
            i++;
        }
        
        curr->isEnd = true;
        curr->str = word;
    }
    
    string search( string& word ){
        TrieNode* curr = root;
        int i = 0 ;
        
        while( i < word.size() ){
            int ind = word[i]-'a';
            
            if( curr->isEnd ){
                return curr->str;
            }
            if( curr->child[ind] == NULL ){
                return word;
            }
            
            curr = curr->child[ind];
            i++;
        }
        
        if( !curr->isEnd ){
            return word;
        }
        return curr->str ;
    }
    
public:
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for( int i = 0 ; i < dictionary.size() ; i++ ){
            insert( dictionary[i] );
        }
        
        int i = 0;
        string ans = "";
        
        while( i < sentence.length() ){
            int j = i;
            string curr = "";
            while( (j < sentence.length()) && (sentence[j] != ' ') ){
                curr.push_back( sentence[j] );
                j++;
            }
            
            if( curr.length() == 1 ){
                ans += curr;
            }
            else{
                string res = search( curr );
                ans += res;
            }
            
            ans.push_back(' ');
            i = j+1;
        }
        ans.pop_back();
        
        return ans;
    }
};
/*

    bool search(string word) {
        TrieNode* curr = root;
        int i = 0 ;
        
        while( i < word.size() ){
            int ind = word[i]-'a';
            
            if( curr->child[ind] == NULL ){
                return false;
            }
            
            curr = curr->child[ind];
            i++;
        }
        
        return( curr->isEnd );
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int i = 0 ;
        
        while( i < prefix.size() ){
            int ind = prefix[i]-'a';
            
            if( curr->child[ind] == NULL ){
                return false;
            }
            
            curr = curr->child[ind];
            i++;
        }
        
        return true;
    }
    
    ["e","k","c","harqp","h","gsafc","vn","lqp","soy","mr","x","iitgm","sb","oo","spj","gwmly","iu","z","f","ha","vds","v","vpx","fir","t","xo","apifm","tlznm","kkv","nxyud","j","qp","omn","zoxp","mutu","i","nxth","dwuer","sadl","pv","w","mding","mubem","xsmwc","vl","farov","twfmq","ljhmr","q","bbzs","kd","kwc","a","buq","sm","yi","nypa","xwz","si","amqx","iy","eb","qvgt","twy","rf","dc","utt","mxjfu","hm","trz","lzh","lref","qbx","fmemr","gil","go","qggh","uud","trnhf","gels","dfdq","qzkx","qxw"]
"ikkbp miszkays wqjferqoxjwvbieyk gvcfldkiavww vhokchxz dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dco kddxmckhvqifbuzkhstp wc ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy ifvifheoxqlbosfww mengfdydekwttkhbzenk wjhmmyltmeufqvcpcxg hthcuovils ldipovluo aiprogn nusquzpmnogtjkklfhta klxvvlvyh nxzgnrveghc mpppfhzjkbucv cqcft uwmahhqradjtf iaaasabqqzmbcig zcpvpyypsmodtoiif qjuiqtfhzcpnmtk yzfragcextvx ivnvgkaqs iplazv jurtsyh gzixfeugj rnukjgtjpim hscyhgoru aledyrmzwhsz xbahcwfwm hzd ygelddphxnbh rvjxtlqfnlmwdoezh zawfkko iwhkcddxgpqtdrjrcv bbfj mhs nenrqfkbf spfpazr wrkjiwyf cw dtd cqibzmuuhukwylrnld dtaxhddidfwqs bgnnoxgyynol hg dijhrrpnwjlju muzzrrsypzgwvblf zbugltrnyzbg hktdviastoireyiqf qvufxgcixvhrjqtna ipfzhuvgo daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh qzsaobsghgm ichlpsjlsrwzhbyfhm ksenb bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala qmxixtooxtbrzyorn gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn frotscysdyclrc ckcttaceuuxzcghw pxbd oklwhcppuziixpvihihp"
["tsgl","pzmnl","gfpb","upm","ddo","wiqvz","sma","daqbpa","motdh","kzhwx","zyyh","dqaopk","ilqhb","nqgloj","kdtjwss","rklrcc","nmb","atxkh","svui","lmtbrypd","krsbtjjt","ztx","xpr","kory","rigpn","cldqwbjg","gaeiqlid","gbrxn","uab","sxbh","xdjhuh","mstil","lzewly","gikyilyj","leeo","yome","rydqrtx","jlll","afxzkuy","uoqda","ulinp","qkqe","rayjerc","hhm","sbinf","tmlamjy","gdnlhjww","sohtk","dofu","ixmomhp","cgfkgh","ftx","lqsukuh","xqmpmslv","oxtal","wxrhzgnv","pig","vesjo","pikl","bmi","bsmlto","tnqjxsvd","vdljudu","yrelagq","iuyqqigu","hbrs","waa","oqhmmb","vwge","gaf","fsy","ozowi","sqzoqdx","blexficw","hflrzpq","gviqvj","gmi","zqgt","qeni","pzncquw"]
"gbhshlxzqazyfpaod yadlbkkbrqugknuz unwqfkvomvmnx onifxbeqoormoirjph hkifwaacidgvdq qiy wsuboxjskibrcjf gyburzrgjrijsbtp lmxt rrfldbtgn pfstz gwdfxnoj l dukefqczd gmfpldis icdik njkoh lqebxnkojn nyrw xxccaxrctbwwjqct xcoafc pfcxzhdnf skrmajixytut txwxcd ckdoehkriabbmjmu vsnotydabinwby samzmxdkcdjvjxkz hnmftt qxrfunwxywapxzee wzjniszcffbj spuhkisnqxm o ncpffozioqper ridvisnhgkywmwkzyxsg gdx feymcwxzqyfuijp drqfrlj wbczpflvimjnooj danhfasvuzxr puzjyfzjlsmzjsmeh grfpywrqbicqjb iurjzdofcjmjnhva ejhpihogyqc pklztcbwhptmzfbjs xpyoddzpitvwuioezt cdh wp ydacnhybfqfrrzcgnkn rjozblhrab kjoqnbrxydxjzblaxlc ccqbmsgzlusna uuqxyevhloshi jpvwbetnurdeoltf eqd pwruejfs zhlaakqqgo gmoqdhybykccqpxkwyuu bkcxeyii znwwiurtnvnfwcbmdi rmkeeolnqszmvzls nxoratnatkmug zsrlhsjrr qfbdvojauoq e voja fbaonsiaxpruyg mzspoittzlhuhrys stumtch qgsgoptlmxko ydemhbfh fzufzzvjn o ywvtywdsmirgfwmiapf wynfwbi azayqvzvrkjwgxydozdv lpioshhwxqgnqsqdj bs aqxvaycvb hkejxyxy ggz"
*/