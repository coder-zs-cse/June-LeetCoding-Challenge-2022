class Solution {
public:
    static bool compare(string &words1,string &words2){
        return words1.length() < words2.length();
    }
    //adfghjghfdfsdf
    // index=7
    // temp adfghjg + fdfsdf
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int word_chain =0;
        unordered_map<string,int> record;
        for(int i=0;i<words.size();i++){
            string temp;
            int chain_length=0;
            for(int j=0;j<words[i].size();j++){
                temp = words[i].substr(0,j) + words[i].substr(j+1);
                auto check = record.find(temp);
                if(check!=record.end()){
                    chain_length = max(chain_length,check->second);
                }
            }
            record[words[i]] = 1+chain_length;
            word_chain = max(word_chain,1+chain_length);
            
        }
        return word_chain;
    }
};