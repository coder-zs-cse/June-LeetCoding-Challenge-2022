class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> output;
        sort(people.begin(),people.end(),compare);
        for(int i=0;i<people.size();i++){
            int limit = people[i][1];
            int j=0;
            while(j<output.size() && (limit>0 || people[i][0]>output[j][0] && j>=output[j][1])){
                if(people[i][0]<=output[j][0]) limit--;
                j++;

            }
            output.insert(output.begin() + j,people[i]);
        }
        return output;
    }
};