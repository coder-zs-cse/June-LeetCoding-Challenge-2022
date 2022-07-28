class TrieNode{
    char data;
    vector<TrieNode*> record;
    bool end;
    TrieNode(char c){
        data = c;
        record = vector<TrieNode*>(26,NULL);
        end = false;
    }
    friend class Solution;
};
class Solution {
public:
    TrieNode* buildTrie(vector<string> &products){
        TrieNode *root = new TrieNode('#');
        for(int i=0;i<products.size();i++){
            TrieNode *current = root;
            for(int j=0;j<products[i].length();j++){
                if(current->record[products[i][j]-'a']==NULL){
                    TrieNode *newnode = new TrieNode(products[i][j]);
                    current->record[products[i][j]-'a'] = newnode;
                }
                current = current->record[products[i][j]-'a'];
                if(j==products[i].length()-1) current->end = true;
            }
        }
        return root;
    }
    bool dfs(TrieNode *root,vector<string> &suggestion,string &current){
        if(!root) return false;
        current+=root->data;
        if(root->end)  suggestion.push_back(current);
        if(suggestion.size()==3) {
            current.pop_back();
            return true;
        }
        
        for(int i=0;i<26;i++){
            if(root->record[i]){
                if(dfs(root->record[i],suggestion,current)) {
                    current.pop_back();
                    return true;
                }
            }
        }
        current.pop_back();
        return false;
        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> output;
        TrieNode *root = buildTrie(products);
        TrieNode *current = root;
        string curr = "";
        for(int i=0;i<searchWord.length();i++){
            current = current->record[searchWord[i]-'a'];
            if(current==NULL) break;
            else{
                vector<string> suggestions;
                dfs(current,suggestions,curr);
                output.push_back(suggestions);
            }
            curr+=searchWord[i];
        }
        while(output.size()<searchWord.length()){
            output.push_back({});
        }
        return output;
    }
};