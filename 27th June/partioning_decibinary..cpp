class Solution {
public:
    int minPartitions(string n) {
        int digit=0;
        for(int i=0;i<n.length();i++){
            digit = max(digit,n[i]-'0');
        }
        return digit;
    }
};