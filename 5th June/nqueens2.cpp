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
    int recursive_engine(vector<int> board,int i,int j,int n){
        if(i==n) return 1;
        int output=0;
        for(int x=0;x<n;x++){
            if(!ifclash(board,i,x,n)){
                board[i] = x;
                output+=recursive_engine(board,i+1,x,n);
                board[i] = -1;
            }
        }
        return output;
    }
    // 1 3 0 2
    int totalNQueens(int n) {
        vector<int> board(n,-1);
        int output=0;
        for(int i=0;i<n;i++){
            board[0] = i;
            output+=recursive_engine(board,1,i,n);
            board[0] = -1;
        }
        return output;
    }
};