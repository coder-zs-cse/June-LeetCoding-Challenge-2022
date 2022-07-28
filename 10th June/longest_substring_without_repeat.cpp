class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int left=0,right=0;
        vector<int> record(256,-1);
        for(int i=0;i<s.length();i++){
            int current = s[i];
            if(record[current]!=-1){
                while(left<=record[current]){
                    record[s[left]] = -1;
                    left++;
                }
            }
            right++;
            record[current] = i;
            length = max(length, right - left);
        }
        return length;
    }
};