class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++) if(freq[i]!=0)  pq.push(freq[i]);
        int prev = pq.top();
        pq.pop();
        int output=0;
        while(!pq.empty()){
            int current = pq.top();
            if(current==0) break;
            pq.pop();
            if(current == prev){
                output++;
                pq.push(current-1);
            }
            prev = current;
        }
        return output;
    }
};