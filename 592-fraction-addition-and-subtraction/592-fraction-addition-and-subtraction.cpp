
class Solution {
public:
    
    long long gcd(long long n1,long long n2){
        if(n2%n1==0) return n1;
        long long rem=n2%n1;
        return gcd(rem,n1);
    }
    void convert(string& s,int i,long long& den,long long& num){
        if(i>=s.size()) return;
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        if(s[i]=='+') i++;
        int n=0;
        int j=i;
        while(j<s.size() && s[j]>=48 && s[j]<=57){
            n=(n*10)+(s[j]-48);
            j++;
        }
        n*=sign;
        j++;
        int d=0;
        while(j<s.size() && s[j]>=48 && s[j]<=57){
            d=d*10+(s[j]-48);
            j++;
        }
        den*=d;
        convert(s,j,den,num);
        num+=((den/d)*n);
        return;
    }
    string fractionAddition(string expression) {
        long long num=0;
        long long den=1;
        convert(expression,0,den,num);
        if(num==0) return "0/1";
        int f=gcd(abs(num),den);
        int sign=(num<0)?-1:1;
        int k=abs(num)/f;
        int g=den/f;
        string s1="";
        while(k>0){
            int rem=k%10;
            s1+=(rem+48);
            k/=10;
        }
        reverse(s1.begin(),s1.end());
        s1+='/';
        string s2="";
        while(g>0){
            int rem=g%10;
            s2+=(rem+48);
            g/=10;
        }
        reverse(s2.begin(),s2.end());
        s1+=s2;
        if(sign==-1) s1="-"+s1;
        return s1;
    }
};
