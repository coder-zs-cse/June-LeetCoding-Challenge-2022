class NumMatrix {
public:
    vector<vector<int>> box;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++) temp.push_back(matrix[i][j]);
            box.push_back(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j!=0){
                    box[i][j] = box[i][j]+box[i][j-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0) {
                    box[i][j] = box[i-1][j] + box[i][j];
                }
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int output = box[row2][col2];
        if(row1>0 && col1>0) output+= box[row1-1][col1-1];
        if(col1>0) output-=box[row2][col1-1];
        if(row1>0) output-=box[row1-1][col2];
        return output;
        
    }
};