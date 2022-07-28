class Solution {
public:
    #define rep(i,a,b) for(int i=a;i<b;i++)

    string longestPalindrome(string s) {
        string output="";
        rep(i,0,s.length()){
            int l=0;
            while(i-l>=0 && i+l<s.length()){
                if(s[i-l]==s[i+l]){
                    if(2*l+1>output.length()){
                        output=s.substr(i-l,2*l+1);
                    }
                    l++;
                }
                else break;
            }
        }
        rep(i,0,s.length()-1){
            if(s[i]==s[i+1]){
                int l=0;
                while(i-l>=0 && i+l+1<s.length()){
                    if(s[i-l]==s[i+l+1]){
                        if(2*l+2>output.length()){
                            output=s.substr(i-l,2*l+2);
                        }
                        l++;
                    }
                    else break;
                }
            }
        }
        return output;
    }
};