class TrieNode{
    char data;
    vector<TrieNode*> record;
    TrieNode(char c){
        data = c;
        record = vector<TrieNode*>(26,NULL);
    }
    friend class Solution;
};
class Solution {
public:
    static bool compare(string &a,string &b){
        return a.length()>b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int output =0;
        TrieNode *root = new TrieNode('%');
        for(int i=0;i<words.size();i++){
            TrieNode *current = root;
            for(int j=words[i].size()-1;j>=0;j--){
                if(!current->record[words[i][j]-'a']){
                    TrieNode *newnode = new TrieNode(words[i][j]);
                    current->record[words[i][j]-'a'] = newnode;
                    if(j==0) output+=words[i].size()+1;
                }
                current = current->record[words[i][j]-'a'];
            }
        }
        return output;
    }
};