class Solution {
public:
    bool ifclash(vector<int> queen_pos,int x,int y,int n){
        for(int i = x-1;i>=0;i--){
            if(queen_pos[i]==y) return true;
        }
        for(int i = x-1,j = y-1;i>=0 && j>=0;i--,j--){
            if(queen_pos[i]==j) return true;
        }
        for(int i = x-1,j = y+1;i>=0 && j<n;i--,j++){
            if(queen_pos[i]==j) return true;
        }
        return false;
    
    }
    string insert_queen_pos(int pos,int n){
        string output="";
        for(int i=0;i<n;i++){
            if(i==pos) output+= 'Q';
            else output += '.';
        }
        return output;
    }
    void recursive_engine(vector<int> &queen_pos,int i,int j,vector<vector<string>> &output,int n){
        if(ifclash(queen_pos,i,j,n)) return;
        queen_pos[i] = j;
        if(i==n-1){
            vector<string> current;
            for(int x=0;x<n;x++){
                current.push_back(insert_queen_pos(queen_pos[x],n));
            }
            output.push_back(current);
            return;
        }
        for(int x=0;x<n;x++){
            recursive_engine(queen_pos,i+1,x,output,n);
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<int> queen_pos(n,-1);
        for(int i=0;i<n;i++){
            recursive_engine(queen_pos,0,i,output,n);
        }
        return output;
        
    }
};